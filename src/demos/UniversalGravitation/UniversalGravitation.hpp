#include <SFML/Graphics.hpp>
#include <iostream>
// #include "../../Entities/Ball.cpp"
// #include "../../logic/Operation.h"
#include "../../logic/CollisionDetectionOperation.h"

class UniversalGravitation{
    private:
        //ball container
        std::vector<Ball> balls;
        //boundary(line) container
        std::vector<Line> lines;

        //formula variables
        const float G = 6.43f;
        sf::Vector2f displacement;
        float distance;
        float force_magnitude;
        sf::Vector2f force;

        //instantiating objects
        Operation operation;
        CollisionDetectionOperation collisionDetectionOperation;

        //..
        Ball gravity_center;

    public:
        UniversalGravitation();

        //custom functions
        void createEntities(sf::Vector2f vector);
        void attractor(Ball &a, Ball &b);

        //integrator and displayer
        void update(float dt, sf::Vector2f mouse_position);
        void render(sf::RenderTarget* target);
};