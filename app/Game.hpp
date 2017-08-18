#ifndef APP_GAME_HPP
#define APP_GAME_HPP
#include <iostream>
#include <vector>

#include "app/Config.hpp"

class Game
{
  public:
    Game();
    ~Game();

  public:
    void initGame();
    void drawGameBoard();
    int randEven(int max);

  public:
    std::vector< std::vector< int > > m_gameBoard;
};

#endif
