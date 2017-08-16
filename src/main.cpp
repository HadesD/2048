#include <iostream>

#ifdef LINUX
#  include <ncurses.h> // getyx() lncurses - Linux
#  include <curses.h>
#elseif (WIN32)
#  include <Windows.h>
#endif

int main(int , char *[])
{
  std::string key;

  while (true)
  {
    int x, y;
    getyx(x, &y);
    std::cin >> key;
    std::cout << key;
  }

  return 0;
}
