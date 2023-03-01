#include <SFML/Graphics.hpp>
// #include "../../Entities/Ball.cpp"
#include "../../logic/CollisionDetectionOperation.h"

class SnowFlake : public Ball{
    private:
        //instantiate
        Operation operation;

        sf::Vector2f gravity = sf::Vector2f(0.f, 0.01f);
        sf::Vector2f oscillation2D;

        float angle;
    public:
        SnowFlake(){
            
        }

        void update(){
            this->oscillation2D = sf::Vector2f(this->operation._sin(this->angle) * 0.1f, 0.f);
            this->acceleration = this->gravity * this->getInverseMass();
            this->velocity += this->acceleration;
            this->particle_property.move(this->velocity + this->oscillation2D);
            if(this->angle < 360.f)
                this->angle++;
            else
                this->angle = 0.f;
        }

        void render(sf::RenderTarget* target){
            target->draw(this->particle_property);
        }
};