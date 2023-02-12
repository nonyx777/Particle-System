#include "Smoke.hpp"

//defining custom functions
void Smoke::createBalls(){
    auto seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    srand(seed);

    float min_x = -1.f;
    float max_x = 1.f;

    float min_y = -1.f;
    float max_y = -3.f;

    this->random_velocity_x = min_x + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(max_x-min_x)));
    this->random_velocity_y = min_y + static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(max_y-min_y)));

    if(this->random_velocity_x != tempo){
        this->tempo = this->random_velocity_x;
        Ball ball;
        ball.particle_property.setFillColor(sf::Color::White);
        ball.particle_property.setRadius(10.f);
        ball.particle_property.setOrigin(sf::Vector2f(ball.particle_property.getRadius(), ball.particle_property.getRadius()));
        ball.setPosition(this->spawn_point);
        ball.setVelocity(sf::Vector2f(this->random_velocity_x, this->random_velocity_y));

        this->balls.push_back(ball);
    }
}

//defining integrator and displayer
void Smoke::update(float dt){
    for(int i = 0; i < 5; i++)
        this->createBalls();

    for(Ball &ball : this->balls)
        ball.update(dt);
}
void Smoke::render(sf::RenderTarget* target){
    for(Ball &ball : this->balls)
        ball.render(target);
}