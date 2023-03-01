#include <SFML/Graphics.hpp>
#include <chrono>
#include "../../include/Particle.hpp"

class Box : public Particle{
    public:
        sf::RectangleShape particle_property;
        int alpha = 255;

        //angular speed
        float angular_speed;
    public:
        Box(){
            //...
        }
        void update(float dt){
            this->particle_property.rotate(this->angular_speed);
            this->velocity += this->acceleration * dt;
            this->particle_property.move(this->velocity);
            this->alpha = this->alpha > 5.f ? this->alpha - 2.f : this->alpha = 0.f;
            this->particle_property.setFillColor(sf::Color(255, 255, 255, this->alpha));
        }

        void render(sf::RenderTarget* target){
            target->draw(this->particle_property);
        }
};