#include <iterator>
#include <algorithm> // std::find
#include "app/Game.hpp"
#include "app/KeyPushManager.hpp"
#include "app/Utils.hpp"

Game::Game()
{
  m_point = 0;
  m_isFinish = false;

  m_gameBoard.reserve(GAMEBOARD_ROWS);

  for (int x = 0; x < GAMEBOARD_ROWS; x++)
  {
    m_gameBoard.reserve(GAMEBOARD_COLS);

    std::vector< int > vX;

    for (int y = 0; y < GAMEBOARD_COLS; y++)
    {
      vX.emplace_back(0);
    }

    m_gameBoard.emplace_back(vX);
  }
}

Game::~Game()
{
}

void Game::init()
{
  for (int c = 0; c < MAX_START_COUNT; c++)
  {
    this->fillRandPos(m_gameBoard);
  }
}

void Game::drawHBarrier(int zeroSpaceLen)
{
  std::cout << "+";
  for (int i = 0; i < GAMEBOARD_COLS; i++)
  {
    std::cout << std::string(zeroSpaceLen, '-');
    std::cout << "+";
  }
  std::cout << std::endl;
}

void Game::drawGameBoard()
{
  std::cout << "<2048 version console> :: Dark.Hades" << std::endl;
  int zeroSpaceLen = 5;
  for (size_t x = 0; x < m_gameBoard.size(); x++)
  {
    this->drawHBarrier(zeroSpaceLen);
    std::cout << "|";
    for (size_t y = 0; y < m_gameBoard.at(x).size(); y++)
    {
      int curValue = m_gameBoard.at(x).at(y);
      int len = std::to_string(m_gameBoard.at(x).at(y)).size();
      std::cout << std::string(zeroSpaceLen - len, ' ');
      if (curValue == 0)
      {
        std::cout << " ";
      }
      else
      {
        switch (curValue)
        {
          case 2:
            {
              std::cout << "\e[38;5;196m";
            }
            break;
          case 4:
            {
              std::cout << "\e[38;5;27m";
            }
            break;
          case 8:
            {
              std::cout << "\e[38;5;58m";
            }
            break;
          case 16:
            {
              std::cout << "\e[38;5;93m";
            }
            break;
           case 32:
            {
              std::cout << "\e[38;5;129m";
            }
            break;
           case 64:
            {
              std::cout << "\e[38;5;237m";
            }
            break;
           case 128:
            {
              std::cout << "\e[38;5;201m";
            }
            break;
           case 256:
            {
              std::cout << "\e[38;5;172m";
            }
            break;
        }
        std::cout << curValue;
        std::cout << "\e[0m";
      }
      std::cout << "|";
    }
    std::cout << std::endl;
  }
  this->drawHBarrier(zeroSpaceLen);
  std::cout << "Point: " << m_point << std::endl;
}

void Game::update()
{
  KeyPushManager key(*(this));
  key.waitKeyPush();
}

void Game::checkFinish()
{
  for (size_t x = 0; x < m_gameBoard.size(); x++)
  {
    auto it = std::find(std::begin(m_gameBoard.at(x)), std::end(m_gameBoard.at(x)), 0);
    if (it != std::end(m_gameBoard.at(x)))
    {
      return;
    }
  }

  for (size_t x = 0; x < m_gameBoard.size(); x++)
  {
    for (size_t y = 0; y < m_gameBoard.at(x).size(); y++)
    {
      if (x < m_gameBoard.size() - 1)
      {
        if (m_gameBoard.at(x).at(y) == m_gameBoard.at(x + 1).at(y))
        {
          return;
        }
      }

      if (y < m_gameBoard.at(x).size() - 1)
      {
        if (m_gameBoard.at(x).at(y + 1) == m_gameBoard.at(x).at(y))
        {
          return;
        }
      }
    }
  }
  m_isFinish = true;
}

void Game::fillRandPos(Game::GameBoard &gb)
{
  while(true)
  {
    int x = std::rand() % gb.size();
    int y = std::rand() % gb.at(x).size();

    if (gb.at(x).at(y) == 0)
    {
      gb[x][y] = Utils::randEven(4);
      break;
    }
  }
}

void Game::setKey(int key)
{
  m_key = key;
}

int Game::getKey() const
{
  return m_key;
}

void Game::setPoint(int point)
{
  m_point = point;
}

int Game::getPoint() const
{
  return m_point;
}

Game::GameBoard Game::getGameBoard() const
{
  return m_gameBoard;
}

void Game::setGameBoard(Game::GameBoard gb)
{
  m_gameBoard = gb;
}

bool Game::isFinish() const
{
  return m_isFinish;
}
