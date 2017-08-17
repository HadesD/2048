#include <iostream>

#ifdef LINUX
#  include <ncurses.h> // getyx() lncurses - Linux
#  include <curses.h>
#elseif (WIN32)
#  include <Windows.h>
#endif

#include <vector>
#include <cassert>
#include <ctime>

#define GAMEBOARD_ROWS 4
#define GAMEBOARD_COLS 5
#define MAX_START_COUNT 20

std::vector< std::vector< int > > game_board;

int genRandEven(int max);
void initGame();
void drawGameBoard();

int main(int , char *[])
{
  assert(MAX_START_COUNT <= (GAMEBOARD_COLS * GAMEBOARD_ROWS));

  // Init random
  std::srand(std::time(0));

  std::string key;

  // Init game
  initGame();

  // while (true)
  {
    drawGameBoard();

    key = getchar();

    // system("clear");

    std::cout << key;
  }

  return 0;
}

int genRandEven(int max)
{
  int v = std::rand() % max;

  if (v == 0)
  {
    v = 2;
  }
  else if ((v % 2) != 0)
  {
    v++;
  }

  return v;
}

void initGame()
{
  game_board.reserve(GAMEBOARD_ROWS);

  for (int x = 0; x < GAMEBOARD_ROWS; x++)
  {
    game_board.reserve(GAMEBOARD_COLS);

    std::vector< int > vX;

    for (int y = 0; y < GAMEBOARD_COLS; y++)
    {
      vX.emplace_back(0);
    }

    game_board.emplace_back(vX);
  }

  for (int c = 0; c < MAX_START_COUNT; c++)
  {
    int x = std::rand() % GAMEBOARD_ROWS;
    int y = std::rand() % GAMEBOARD_COLS;

    game_board[x][y] = genRandEven(4);
  }
}

void drawGameBoard()
{
  for (size_t x = 0; x < game_board.size(); x++)
  {
    std::cout << std::string(game_board.at(x).size(), '-') << std::endl;
    for (size_t y = 0; y < game_board.at(x).size(); y++)
    {
      std::cout << game_board.at(x).at(y);
      std::cout << " ";
    }
    std::cout << std::endl;
  }
}
