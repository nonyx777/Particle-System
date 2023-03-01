#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
// #include "../demos/UniversalGravitation/UniversalGravitation.hpp"
// #include "../demos/Smoke/Smoke.hpp"
// #include "../demos/Rain/Rain.hpp"
#include "../demos/Snow/Snow.hpp"

using namespace std;

class Engine{
    private:
        //initializer functions
        void initVariables();
        void initWindow();

        //window variables
        sf::RenderWindow* window;
        sf::VideoMode video_mode;
        sf::Event event;

        //instantiating objects
        // UniversalGravitation universalGravitation;
        // Smoke smoke;
        // Rain rain;
        Snow snow;


        //mouse position
        sf::Vector2i mouse_position;

        //target container
        std::vector<sf::RectangleShape> targets;

    public:
        sf::Vector2f mouse_position_view;

        //key check
        bool q_pressed;
        //constructor and destructor
        Engine();
        ~Engine();


        //window functions
        void pollEvent();
        void update(float dt);
        void render();

        //Accessors
        const bool running() const;
};