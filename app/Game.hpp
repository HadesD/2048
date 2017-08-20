#ifndef APP_GAME_HPP
#define APP_GAME_HPP
#include <iostream>
#include <vector>

#include "app/Config.hpp"

class Game
{
  public:
    typedef std::vector< std::vector< int > > GameBoard;
  public:
    Game();
    ~Game();

  public:
    void init();
    void drawHBarrier(int zeroSpaceLen);
    void drawGameBoard();
    void update();
    void fillRandPos(GameBoard &gb);

  public:
    void setKey(int key);
    int getKey() const;
    void setPoint(int point);
    int getPoint() const;
    void setGameBoard(GameBoard gb);
    GameBoard getGameBoard() const;

  public:
    GameBoard m_gameBoard;
    int m_key;
    int m_point;
};

#endif
