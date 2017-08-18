#ifdef LINUX
#  include <ncurses.h> // getyx() lncurses - Linux
#  include <curses.h>
#elseif (WIN32)
#  include <Windows.h>
#endif

#include <memory>

#include <cassert>
#include <ctime>

#include "app/Game.hpp"

int main(int , char *[])
{
  assert(MAX_START_COUNT <= (GAMEBOARD_COLS * GAMEBOARD_ROWS));

  // Init random
  std::srand(std::time(0));

  std::string key;

  std::shared_ptr<Game> g(new Game());

  // Init game
  g->initGame();

  // while (true)
  {
    g->drawGameBoard();

    key = getchar();

    // system("clear");

    std::cout << key;
  }

  return 0;
}

