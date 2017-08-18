#ifndef APP_GAME_HPP
#define APP_GAME_HPP
#include <iostream>
#include <vector>

#include "app/Config.hpp"
#include "app/Kbhit.h"

class Game
{
  public:
    Game();
    ~Game();

  public:
    void initGame();
    void drawGameBoard();
    void update();
    int randEven(int max);

  public:
    void onKeyboardHit();

  public:
    int getKey() const;

  public:
    std::vector< std::vector< int > > m_gameBoard;
    int m_key;
};

#endif
