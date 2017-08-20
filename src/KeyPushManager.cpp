#include "app/KeyPushManager.hpp"
#include "app/Game.hpp"

KeyPushManager::KeyPushManager(Game &game) : game(game)
{
}

void KeyPushManager::waitKeyPush()
{
  Kbhit m_kbhit;
  m_key = m_kbhit.getch();
  game.setKey(m_key);

  this->onKeyboardHit();
}

void KeyPushManager::onKeyboardHit()
{
  switch (m_key)
  {
    case 'a':
    case 'h':
      {
        this->moveLeft();
      }
      break;
    case 's':
    case 'j':
      {
        this->moveDown();
      }
      break;
    case 'w':
    case 'k':
      {
        this->moveUp();
      }
      break;
    case 'd':
    case 'l':
      {
        this->moveRight();
      }
      break;
  }
  std::cout << "Pushed: " << (static_cast<char>(m_key)) << std::endl;
}

void KeyPushManager::moveUp()
{
  Game::GameBoard gb = game.getGameBoard();
  std::cout << std::endl;

  for (size_t y = 0; y < gb.at(0).size(); y++)
  {
    for (size_t x = gb.size() - 1; x > 0; x--)
    {
      std::cout << gb.at(x).at(y) << " ";
      if (
        (gb.at(x - 1).at(y) == 0) ||
        (gb.at(x - 1).at(y) == gb.at(x).at(y))
        )
      {
        gb[x - 1][y] += gb[x][y];
        gb[x][y] = 0;
      }
      game.setGameBoard(gb);
    }
    std::cout << std::endl;
  }
}

void KeyPushManager::moveDown()
{
}

void KeyPushManager::moveLeft()
{
}

void KeyPushManager::moveRight()
{
}
