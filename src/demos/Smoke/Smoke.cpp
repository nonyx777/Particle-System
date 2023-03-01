#include "Smoke.hpp"

//defining constructor
Smoke::Smoke(){
    try{
        this->texture.loadFromFile("/home/nonyx/Desktop/scripts/C++/personal/WhatEverComesToMind/Particle-System/src/demos/Smoke/smoke.png");
    }catch(...){
        std::cout << "Could not load image" << std::endl;
    }
}

//defining custom functions
void Smoke::createBoxes(){
    auto seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    srand(seed);

    float min_x = -1.f;
    float max_x = 1.f;

    float min_y = -1.f;
    float max_y = -3.f;

    this->random_velocity_x = min_x + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(max_x-min_x)));
    this->random_velocity_y = min_y + static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(max_y-min_y)));

    float angular_speed = min_x + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(max_x - min_x)));

    if(this->random_velocity_x != tempo){
        this->tempo = this->random_velocity_x;
        Box box;
        box.angular_speed = angular_speed;
        box.particle_property.setTexture(&this->texture);
        box.particle_property.setSize(sf::Vector2f(60.f, 60.f));
        box.particle_property.setOrigin(box.particle_property.getSize()/2.f);
        box.particle_property.setPosition(this->spawn_point);
        box.setVelocity(sf::Vector2f(this->random_velocity_x, this->random_velocity_y));

        this->boxes.push_back(box);
    }
}

//defining integrator and displayer
void Smoke::update(float dt){
    for(int i = this->boxes.size()-1; i > 0; i--){
        if(this->boxes[i].alpha <= 0)
            this->boxes.erase(this->boxes.begin() + i);
    }

    for(int i = 0; i < 5; i++)
        this->createBoxes();

    for(Box &box : this->boxes)
        box.update(dt);
    
    // std::cout << this->boxes.size() << std::endl;
}
void Smoke::render(sf::RenderTarget* target){
    for(Box &box : this->boxes)
        box.render(target);
}