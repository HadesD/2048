#include "app/KeyPushManager.hpp"

KeyPushManager::KeyPushManager(Game &game) : game(game)
{
  gb = game.getGameBoard();
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
  game.setGameBoard(gb);
  std::cout << "Pushed: " << (static_cast<char>(m_key)) << std::endl;
}

void KeyPushManager::moveUp()
{
  for (size_t i = 0; i < gb.size(); i++)
  {
    for (size_t x = gb.size() - 1; x > 0; x--)
    {
      for (size_t y = 0; y < gb.at(x).size(); y++)
      {
        if (
          (gb.at(x - 1).at(y) == 0) ||
          (gb.at(x - 1).at(y) == gb.at(x).at(y))
          )
        {
          if (gb.at(x - 1).at(y) != 0)
          {
            game.setPoint(game.getPoint() + gb.at(x).at(y));
          }
          gb[x - 1][y] += gb[x][y];
          gb[x][y] = 0;
        }
      }
    }
  }
}

void KeyPushManager::moveDown()
{
  for (size_t i = 0; i < gb.size(); i++)
  {
    for (size_t x = 0; x < gb.size() - 1; x++)
    {
      for (size_t y = 0; y < gb.at(x).size(); y++)
      {
        if (
          (gb.at(x + 1).at(y) == 0) ||
          (gb.at(x + 1).at(y) == gb.at(x).at(y))
          )
        {
          if (gb.at(x + 1).at(y) != 0)
          {
            game.setPoint(game.getPoint() + gb.at(x).at(y));
          }
          gb[x + 1][y] += gb[x][y];
          gb[x][y] = 0;
        }
      }
    }
  }
}

void KeyPushManager::moveLeft()
{
  for (size_t i = 0; i < gb.size(); i++)
  {
    for (size_t x = 0; x < gb.size(); x++)
    {
      for (size_t y = gb.at(x).size() - 1; y > 0; y--)
      {
        if (
          (gb.at(x).at(y - 1) == 0) ||
          (gb.at(x).at(y - 1) == gb.at(x).at(y))
          )
        {
          if (gb.at(x).at(y - 1) != 0)
          {
            game.setPoint(game.getPoint() + gb.at(x).at(y));
          }
          gb[x][y - 1] += gb[x][y];
          gb[x][y] = 0;
        }
      }
    }
  }
}

void KeyPushManager::moveRight()
{
  for (size_t i = 0; i < gb.size(); i++)
  {
    for (size_t x = 0; x < gb.size(); x++)
    {
      for (size_t y = 0; y < gb.at(x).size() - 1; y++)
      {
        if (
          (gb.at(x).at(y + 1) == 0) ||
          (gb.at(x).at(y + 1) == gb.at(x).at(y))
          )
        {
          if (gb.at(x).at(y + 1) != 0)
          {
            game.setPoint(game.getPoint() + gb.at(x).at(y));
          }
          gb[x][y + 1] += gb[x][y];
          gb[x][y] = 0;
        }
      }
    }
  }
}
