#ifndef APP_KEY_PUSH_MANAGER_HPP
#define APP_KEY_PUSH_MANAGER_HPP
#include "app/Kbhit.h"
#include "app/Game.hpp"

class Game;

class KeyPushManager
{
  public:
    KeyPushManager(Game &game);

  public:
    void waitKeyPush();
    void onKeyboardHit();

  public:
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

  private:
    Game &game;
    Game::GameBoard gb;
    int m_key;
};

#endif
