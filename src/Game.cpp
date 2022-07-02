
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

    menusInit();

  return true;
}

void Game::menusInit()
{
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

    if(!one_texture.loadFromFile("Data/Images/Assets/tile_0171.png"))
    {
        std::cout<<"1 texture did not load\n";
    }
    one.setTexture(one_texture);
    one.setScale(10,10);
    one.setPosition(window.getSize().x/2-one.getGlobalBounds().width/2,
                            window.getSize().y/6-one.getGlobalBounds().height/2);

    if(!two_texture.loadFromFile("Data/Images/Assets/tile_0172.png"))
    {
        std::cout<<"2 texture did not load\n";
    }
    two.setTexture(two_texture);
    two.setScale(10,10);
    two.setPosition(window.getSize().x/2-two.getGlobalBounds().width/2,
                    window.getSize().y/2.5-two.getGlobalBounds().height/2);

    if(!three_texture.loadFromFile("Data/Images/Assets/tile_0173.png"))
    {
        std::cout<<"3 texture did not load\n";
    }
    three.setTexture(three_texture);
    three.setScale(10,10);
    three.setPosition(window.getSize().x/2-three.getGlobalBounds().width/2,
                    window.getSize().y/1.5-three.getGlobalBounds().height/2);


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
      window.draw(one);
      window.draw(two);
      window.draw(three);
  }
  if(level1_1)
  {

  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
  if(main_menu)
  {
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
  if(level_select)
  {
      if(collisionCheck(click, one))
      {
          level1_1 = true;
          level_select = false;
      }
  }

}

void Game::mouseReleased(sf::Event event)
{

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


