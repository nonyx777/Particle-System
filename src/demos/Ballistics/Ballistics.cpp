#include <SFML/Graphics.hpp>
#include "../../../include/Particle.hpp"

class Ballistics : public Particle{
    public:
        Ballistics(){
            this->mass = 20.f;
            this->acceleration = sf::Vector2f(0.f, 25.f);
            this->velocity = sf::Vector2f(7.f, -15.f);
        }

        void update(float dt)
        {
            this->velocity += this->acceleration * dt;
            this->position += this->velocity * dt;
            this->particle_property.move(this->position);
        }
};