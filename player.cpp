#include "player.h"
#include "qdebug.h"
Player::Player(QString name, IBoard *board, CellStatus status, int totalGames, int wins, int ties):
  m_name(name),
  m_wins(wins),
  m_totalGames(totalGames),
  m_ties(ties),
  m_board(board),
  m_status(status)
{

}

int Player::getWins() const
{
    return m_wins;
}

int Player :: getTies() const
{
    return m_ties;
}

int Player::getTotalGames() const
{
    return m_totalGames;
}

void Player::setResult(GameStatus status)
{
    m_totalGames++;
    switch(status)
    {
        case GameStatus::Won:
            m_wins++;
            break;
        case GameStatus::Tie:
            m_ties++;
            qDebug()<<m_ties;
            break;
        default:
        break;

    }
}

IBoard *::Player::getBoard() const
{
    return m_board;
}

CellStatus Player::getStatus() const
{
    return m_status;
}

void Player::setStatus(CellStatus status)
{
     m_status = status;
}
