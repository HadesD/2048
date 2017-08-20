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

  for (int c = 0; c < MAX_START_COUNT; c++)
  {
    int x = std::rand() % GAMEBOARD_ROWS;
    int y = std::rand() % GAMEBOARD_COLS;

    m_gameBoard[x][y] = Utils::randEven(4);
  }
}

Game::~Game()
{
}

void Game::drawGameBoard()
{
  for (size_t x = 0; x < m_gameBoard.size(); x++)
  {
    std::cout << std::string(m_gameBoard.at(x).size(), '=') << std::endl;
    for (size_t y = 0; y < m_gameBoard.at(x).size(); y++)
    {
      // if (m_gameBoard.at(x).at(y) == 0)
      {
        // std::cout << " ";
      }
      // else
      {
        std::cout << m_gameBoard.at(x).at(y);
      }
      std::cout << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "Point: " << m_point << std::endl;
}

void Game::update()
{
  KeyPushManager key(*(this));
  key.waitKeyPush();
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
