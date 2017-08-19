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
