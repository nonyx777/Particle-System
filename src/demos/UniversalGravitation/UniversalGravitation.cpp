#include <SFML/Graphics.hpp>
#include "UniversalGravitation.hpp"

UniversalGravitation::UniversalGravitation(){
    //adding the lines to the a container
    Line line1 = Line(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 360.f));//left
    Line line2 = Line(sf::Vector2f(0.f, 0.f), sf::Vector2f(640.f, 0.0f));//top
    Line line3 = Line(sf::Vector2f(640.f, 0.f), sf::Vector2f(640.f, 360.f));//right
    Line line4 = Line(sf::Vector2f(0.f, 360.f), sf::Vector2f(640.f, 360.f));//down
    this->lines.push_back(line1);
    this->lines.push_back(line2);
    this->lines.push_back(line3);
    this->lines.push_back(line4);
    //creating a big central ball
    this->gravity_center.setMass(1000.f);
    this->gravity_center.particle_property.setFillColor(sf::Color::Transparent);
    this->gravity_center.particle_property.setRadius(20.f);
    this->gravity_center.particle_property.setOrigin(this->gravity_center.particle_property.getRadius(), this->gravity_center.particle_property.getRadius());
    this->gravity_center.particle_property.setPosition(640.f/2.f, 360.f/2.f);
}

//custom functions
void UniversalGravitation::createEntities(sf::Vector2f vector){
    Ball ball;
    ball.setMass(10.f);
    ball.setElasticity(5.f);
    ball.setDamping(0.1f);
    ball.particle_property.setFillColor(sf::Color::White);
    ball.particle_property.setRadius(1.f);
    ball.particle_property.setOrigin(ball.particle_property.getRadius(), ball.particle_property.getRadius());
    ball.particle_property.setPosition(vector);
    this->balls.push_back(ball);
}

sf::Vector2f UniversalGravitation::attractor(Ball &a, Ball &b){
    this->displacement = this->operation._displacement(a.getPosition(), b.getPosition());
    this->distance = this->operation._magnitude(this->displacement);
    this->force_magnitude = this->G * (a.getMass() * b.getMass())/(this->distance * this->distance);
    this->force = this->force_magnitude * this->operation._unitVector(this->displacement);
    return this->force;
}

void UniversalGravitation::update(float dt, sf::Vector2f mouse_position){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        this->gravity_center.setPosition(mouse_position);

    for(Ball &ball : this->balls){
        sf::Vector2f to_gravity_center = this->attractor(this->gravity_center, ball);
        if(this->collisionDetectionOperation._ballCollide(this->gravity_center, ball))
            ball.setAcceleration(ball.getAcceleration() * 0.0001f);
            // ball.setAcceleration(-to_gravity_center/ball.getMass());
        else
            ball.setAcceleration(to_gravity_center/ball.getMass());
    }

    for(auto &ball : this->balls)
        ball.update(dt);
}
void UniversalGravitation::render(sf::RenderTarget* target){
    // for(auto &line : this->lines)
    //     line.render(target);
    for(auto &ball : this->balls)
        ball.render(target);
    this->gravity_center.render(target);
}