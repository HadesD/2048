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

int main(int /* argc */, char * /* argv */[])
{
  assert(MAX_START_COUNT <= (GAMEBOARD_COLS * GAMEBOARD_ROWS));

  // Init random
  std::srand(std::time(0));

  std::shared_ptr<Game> g(new Game());

  // Init game
  g->initGame();

  while (true)
  {
    g->drawGameBoard();

    g->update();
    // system("clear");

    if (g->getKey() == 'q')
    {
      std::cout << "Do you want to exit game? [y/n] ";
      std::string ans;
      std::cin >> ans;
      if (ans == "y")
      {
        break;
      }
    }
  }

  return 0;
}

