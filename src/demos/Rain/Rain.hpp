#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
// #include "../../logic/CollisionDetectionOperation.h"
#include "Drop.cpp"

class Rain{
    private:
        //drop related
            //length related
        float length;
        float length_min = 10.f;
        float length_max = 40.f;
        //drop container
        std::vector<Drop> drops;
        //spawn related
        float min_x = 0.f;
        float max_x = 640.f;
        float random_position_x;
        float position_saver;
    public:
        //custom functions
        void createDrop();
        //integrator and displayer
        void update(float dt);
        void render(sf::RenderTarget* target);
};