#include <SFML/Graphics.hpp>
#include <iostream>
// #include "../../logic/CollisionDetectionOperation.h"
#include "../../Entities/Box.cpp"
#include <cstdlib>
#include <chrono>
#include <ctime>

class Smoke{
    private:
        //box container
        std::vector<Box> boxes;

        //box instantiating variables
        sf::Vector2f spawn_point = sf::Vector2f(640.f/2.f, 370.f);
        float random_velocity_x;
        float random_velocity_y;
        float tempo;

        //box texture
        sf::Texture texture;
    
    public:
        Smoke();

        //custom function
        void createBoxes();

        //integrator and displayer
        void update(float dt);
        void render(sf::RenderTarget* target);
};