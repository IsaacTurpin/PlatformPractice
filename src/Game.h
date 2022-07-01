
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);

 private:
  sf::RenderWindow& window;
  sf::Sprite background;
  sf::Texture background_texture;
  sf::Sprite play_button;
  sf::Texture play_texture;
  sf::Sprite quit_button;
  sf::Texture quit_texture;
  bool main_menu;
  bool level_select = false;
  bool level1_1 = false;
  bool level1_2 = false;
  bool level1_3 = false;
 // bool level2_1 = false;
 // bool level2_2 = false;
 // bool level2_3 = false;
 // bool level3_1 = false;
 // bool level3_2 = false;
 // bool level3_3 = false;
 bool in_win = false;
 bool in_lose = false;
};

#endif // PLATFORMER_GAME_H
