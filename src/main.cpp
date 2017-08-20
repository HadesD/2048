#include <cassert>
#include <memory>
#include <ctime>

#include "app/Game.hpp"

int main(int /* argc */, char * /* argv */[])
{
  assert(MAX_START_COUNT <= (GAMEBOARD_COLS * GAMEBOARD_ROWS));

  // Init random
  std::srand(std::time(0));

  std::shared_ptr<Game> g(new Game());

  g->init();

  while (true)
  {
    g->drawGameBoard();

    g->update();
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif

    if (g->getKey() == 'q')
    {
      std::string ans;
      std::cout << "Do you want to exit game? [y/n] ";
      while(std::cin >> ans)
      {
        if ((ans == "y") || (ans == "n"))
        {
          break;
        }
        std::cout << "[y/n]: ";
      }
      if (ans == "y")
      {
        std::cout << "Exit game" << std::endl;
        break;
      }
    }
  }

  return 0;
}

