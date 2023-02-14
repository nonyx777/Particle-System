#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../logic/CollisionDetectionOperation.h"
#include <cstdlib>
#include <chrono>
#include <ctime>

class Smoke{
    private:
        //ball container
        std::vector<Ball> balls;

        //ball instantiating variables
        sf::Vector2f spawn_point = sf::Vector2f(640.f/2.f, 360.f);
        float random_velocity_x;
        float random_velocity_y;
        float tempo;
    
    public:
        // Smoke();

        //custom function
        void createBalls();

        //integrator and displayer
        void update(float dt);
        void render(sf::RenderTarget* target);
};