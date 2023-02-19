#include <SFML/Graphics.hpp>
#include "../../../include/Particle.hpp"
#include "../../Entities/Line.cpp"

class Drop : public Line, public Particle{
    private:
        sf::Vector2f velocity = sf::Vector2f(0.f, 10.f);
        float length;
    public:
        Drop(){

        }
        Drop(sf::Vector2f base, sf::Vector2f direction){
            this->base = base;
            this->direction = direction;
            this->length = this->getDirection().y - this->getBase().y;
        }

        void update(){
            this->setDirection(sf::Vector2f(this->getBase().x, this->getBase().y + this->length));

            this->setBase(this->getBase() + velocity);
        }
};