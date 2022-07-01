
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
    main_menu = true;

    if(!play_texture.loadFromFile("Data/Images/Assets/play.png"))
    {
        std::cout<<"play button did not load\n";
    }
    play_button.setTexture(play_texture);
    play_button.setScale(1,1);
    play_button.setPosition(window.getSize().x/2-play_button.getGlobalBounds().width/2,
                            window.getSize().y/8-play_button.getGlobalBounds().height/2);

  return true;
}

void Game::update(float dt)
{

}

void Game::render()
{
    if(main_menu)
    {
        window.draw(play_button);
    }

}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{

}


