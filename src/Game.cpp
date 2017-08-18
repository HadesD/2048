#include "app/Game.hpp"

Game::Game()
{
}

Game::~Game()
{
}

void Game::initGame()
{
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

    m_gameBoard[x][y] = randEven(4);
  }
}

void Game::drawGameBoard()
{
  for (size_t x = 0; x < m_gameBoard.size(); x++)
  {
    std::cout << std::string(m_gameBoard.at(x).size(), '=') << std::endl;
    for (size_t y = 0; y < m_gameBoard.at(x).size(); y++)
    {
      std::cout << m_gameBoard.at(x).at(y);
      std::cout << " ";
    }
    std::cout << std::endl;
  }
}

int Game::randEven(int max)
{
  int v = std::rand() % max;

  if (v == 0)
  {
    v = 2;
  }
  else if ((v % 2) != 0)
  {
    v++;
  }

  return v;
}
