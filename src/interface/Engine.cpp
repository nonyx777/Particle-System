#include "Engine.h"

//defining initializer functions
void Engine::initVariables(){
    this->window = nullptr;
}
void Engine::initWindow(){
    this->video_mode.width = 640;
    this->video_mode.height = 360;
    this->window = new sf::RenderWindow(this->video_mode, "Particle-System", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

//defining constructor and destructor
Engine::Engine(){
    this->initVariables();
    this->initWindow();
}
Engine::~Engine(){
    delete this->window;
}

//defining accessors
const bool Engine::running() const{
    return this->window->isOpen();
}

//defining window functions
void Engine::pollEvent(){
    while(this->window->pollEvent(this->event)){
        switch(this->event.type){
            case sf::Event::Closed:
                this->window->close();
                break;
            // case sf::Event::KeyPressed:
            //     if(this->event.key.code == sf::Keyboard::Q)
                    // this->universalGravitation.createEntities(this->mouse_position_view);
            //     break;
        }
    }
}
void Engine::update(float dt){
    this->pollEvent();
    this->mouse_position = sf::Mouse::getPosition(*this->window);
    this->mouse_position_view = this->window->mapPixelToCoords(this->mouse_position);

    // universalGravitation.update(dt, this->mouse_position_view);
    // this->smoke.update(dt);
    // this->rain.update(dt);
    this->snow.update(dt);
}
void Engine::render(){
    this->window->clear(sf::Color::Black);

    // universalGravitation.render(this->window);
    // this->smoke.render(this->window);
    // this->rain.render(this->window);
    this->snow.render(this->window);

    this->window->display();
}
