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
    void drawGameBoard();
    void update();

  public:
    void setKey(int key);
    int getKey() const;
    int getPoint() const;

  public:
    std::vector< std::vector< int > > m_gameBoard;
    int m_key;
    int m_point;
};

#endif
