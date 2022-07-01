
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
    play_button.setScale(0.1,0.1);
    play_button.setPosition(window.getSize().x/2-play_button.getGlobalBounds().width/2,
                            window.getSize().y/8-play_button.getGlobalBounds().height/2);

    if(!quit_texture.loadFromFile("Data/Images/Assets/quit.png"))
    {
        std::cout<<"quit button did not load\n";
    }
    quit_button.setTexture(quit_texture);
    quit_button.setScale(0.25,0.3);
    quit_button.setPosition(window.getSize().x/2-quit_button.getGlobalBounds().width/2,
                            window.getSize().y/2-quit_button.getGlobalBounds().height/2);

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
      window.draw(quit_button);
  }
  if(level_select)
  {

  }

}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);

  if(collisionCheck(click, play_button))
  {
      level_select = true;
      main_menu = false;
  }
  if(collisionCheck(click, quit_button))
  {
      window.close();
  }


}

void Game::keyPressed(sf::Event event)
{

}

void Game::keyReleased(sf::Event event)
{

}

bool Game::collisionCheck(sf::Vector2i click, sf::Sprite sprite)
{
    if(click.x>sprite.getPosition().x && click.x<sprite.getPosition().x + sprite.getGlobalBounds().width
       && click.y>sprite.getPosition().y && click.y<sprite.getPosition().y + sprite.getGlobalBounds().height)
    {
        return true;
    }
    else
    {
        return false;
    }

}


