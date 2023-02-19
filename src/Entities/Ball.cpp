#include <SFML/Graphics.hpp>
#include "../../include/Particle.hpp"

class Ball : public Particle{
    public:
        sf::CircleShape particle_property;
        int alpha = 255;
    public:
        Ball(){
            //..
        }
        void update(float dt){
            this->velocity += this->acceleration * dt;
            this->particle_property.move(this->velocity);
            this->alpha = this->alpha > 0 ? this->alpha - 3 : this->alpha = 0;
            this->particle_property.setFillColor(sf::Color(255, 255, 255, this->alpha));
        }
        void render(sf::RenderTarget* target){
            target->draw(this->particle_property);
        }
};