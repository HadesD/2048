#include "app/Game.hpp"
#include "app/KeyPushManager.hpp"
#include "app/Utils.hpp"

Game::Game()
{
  m_point = 0;

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
  int zeroSpaceLen = 5;
  for (size_t x = 0; x < m_gameBoard.size(); x++)
  {
    this->drawHBarrier(zeroSpaceLen);
    std::cout << "|";
    for (size_t y = 0; y < m_gameBoard.at(x).size(); y++)
    {
      int len = std::to_string(m_gameBoard.at(x).at(y)).size();
      std::cout << std::string(zeroSpaceLen - len, ' ');
      if (m_gameBoard.at(x).at(y) == 0)
      {
        std::cout << " ";
      }
      else
      {
        std::cout << m_gameBoard.at(x).at(y);
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
