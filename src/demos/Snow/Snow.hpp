#include <SFML/Graphics.hpp>
#include <iostream>
// #include "../../logic/CollisionDetectionOperation.h"
#include "SnowFlake.cpp"
#include <chrono>

class Snow{
    private:
        //snowflake container
        std::vector<SnowFlake> snow_flakes;
        //snowflake related
        float min_size, max_size, min_pos_x, max_pos_x, random_size, random_pos_x, position_saver;
    public:
        Snow();
        //custom functions
        void createSnowFlake();
        void size(float min, float max);
        void position(float min, float max);
        float random(float min, float max);
        //integrator and displayer
        void update(float dt);
        void render(sf::RenderTarget* target);
};