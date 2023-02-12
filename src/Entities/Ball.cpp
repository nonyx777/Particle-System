#include <SFML/Graphics.hpp>
#include "../../include/Particle.hpp"

class Ball : public Particle{
    private:
        int alpha = 255;
    public:
        void update(float dt){
            this->velocity += this->acceleration * dt;
            this->particle_property.move(this->velocity);
            this->alpha = this->alpha > 0 ? this->alpha - 3 : this->alpha = 0;
            this->particle_property.setFillColor(sf::Color(255, 255, 255, this->alpha));
        }
};