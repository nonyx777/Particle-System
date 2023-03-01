#include "Snow.hpp"

//defining constructor
Snow::Snow(){
    //setting the minimum and maximum size and
    //position of the snowflake
    this->size(2.f, 10.f);
    this->position(0.f, 640.f);
    //..........................
}
//defining custom functions
void Snow::createSnowFlake(){
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    srand(seed);

    this->random_pos_x = this->min_pos_x + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(this->max_pos_x - this->min_pos_x)));
    this->random_size = this->min_size + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(this->max_size - this->min_size)));

    if(this->random_pos_x != this->position_saver){
        SnowFlake snowFlake;
        snowFlake.particle_property.setFillColor(sf::Color::White);
        snowFlake.particle_property.setRadius(this->random_size);
        snowFlake.particle_property.setOrigin(sf::Vector2f(snowFlake.particle_property.getRadius(), snowFlake.particle_property.getRadius()));
        snowFlake.particle_property.setPosition(sf::Vector2f(this->random_pos_x, -20.f));
        if(snowFlake.particle_property.getRadius() > 7.f)
            snowFlake.setMass(this->random(1.f, 3.f));
        else
            snowFlake.setMass(this->random(7.f, 11.f));
        this->snow_flakes.push_back(snowFlake);
    }
}
void Snow::size(float min, float max){
    this->min_size = min;
    this->max_size = max;
}
void Snow::position(float min, float max){
    this->min_pos_x = min;
    this->max_pos_x = max;
}
float Snow::random(float min, float max){
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    srand(seed);
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(max - min)));
}
//defining integrator and displayer
void Snow::update(float dt){
    for(int i = this->snow_flakes.size()-1; i > 0; i--){
        if(this->snow_flakes[i].particle_property.getPosition().y > 360.f)
            this->snow_flakes.erase(this->snow_flakes.begin() + i);
    } 

    this->createSnowFlake();

    for(SnowFlake &snow_flake : this->snow_flakes)
        snow_flake.update();
    
    // std::cout << this->snow_flakes.size() << std::endl;
}
void Snow::render(sf::RenderTarget* target){
    for(SnowFlake &snow_flake : this->snow_flakes)
        snow_flake.render(target);
}