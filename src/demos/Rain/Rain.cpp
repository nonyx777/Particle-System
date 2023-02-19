#include "Rain.hpp"

//defining integrator and displayer
void Rain::createDrop(){
    auto seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    srand(seed);

    this->random_position_x = this->min_x + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(this->max_x - this->min_x)));
    this->length = this->length_min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(this->length_max - this->length_min)));

    if(this->random_position_x != this->position_saver){
        this->position_saver = this->random_position_x;
        Drop drop = Drop(sf::Vector2f(sf::Vector2f(this->random_position_x, -2.f)), sf::Vector2f(drop.getBase().x, drop.getBase().y + this->length));
        this->drops.push_back(drop);
    }
}
void Rain::update(float dt){
    for(int i = this->drops.size()-1; i > 0; i--){
        if(this->drops[i].getBase().y > 360.f)
            this->drops.erase(this->drops.begin() + i);
    }

    this->createDrop();

    for(Drop &drop : this->drops)
        drop.update();

    std::cout << this->drops.size() << std::endl;
}
void Rain::render(sf::RenderTarget* target){
    for(Drop &drop : this->drops)
        drop.render(target);
}