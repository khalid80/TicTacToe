#include "tictactoewidget.h"
#include <QGridLayout>
#include <boardcellbutton.h>
#include <QObject>
#include "computerplayer.h"
#include "human.h"
#include "qdebug.h"
#include "utils.h"
TicTacToeWidget::TicTacToeWidget(QWidget *parent) : QWidget(parent),
  m_rowsColumns(3),
  m_initialized(false)
{
    QGridLayout *gridLayout = new QGridLayout;

    int size =  m_rowsColumns * m_rowsColumns;

    for(int i = 0; i < size; ++i)
    {
        m_board[i] = CellStatus::Value_Empty;
        BoardCellButton * cell= new BoardCellButton(i);
        gridLayout->addWidget(cell, i / m_rowsColumns, i % m_rowsColumns);
        connect(cell, SIGNAL(clicked()), this, SLOT(onClick()));
    }

    setLayout(gridLayout);
    setEnabled(false);
}

void TicTacToeWidget::initialize(Player  *player1, Player *player2)
{
    m_player1 = player1;
    m_player2 = player2;
    m_initialized = true;

    if(m_player1->getStatus() == CellStatus::Value_X)
        m_player1->start();
    else
        m_player2->start();
    setEnabled(true);
}

void TicTacToeWidget::onClick()
{
    if(!m_initialized)
        return; // TODO : through exception here
    BoardCellButton *cell = qobject_cast<BoardCellButton*>(sender());

    if(cell->getStatus() == CellStatus::Value_Empty)
    m_player1->start(cell->getIndex());
    m_player2->start(cell->getIndex());
}

void TicTacToeWidget::onStatusChanged(int row, int col, Player * player, bool disableBoard)
{
    if(!m_initialized)
        return; // TODO : through exception here

    int index = row * m_rowsColumns + col;

    m_board[index] = player->getStatus();

    QList<BoardCellButton*> buttons = this->findChildren<BoardCellButton *>();
    BoardCellButton * cell = buttons[index];
    cell->setStatus(player->getStatus());

    CellStatus status = Utils::getWinner(m_board, m_rowsColumns);
    if( status != CellStatus::Value_Empty)
    {
        if(status == CellStatus::Value_Tie)
            player->setResult(Player::GameStatus::Tie);
        else
            player->setResult(Player::GameStatus::Lost);

        setEnabled(false);
    }
    else
    {
        setDisabled(disableBoard);
        if(player == m_player1)
        {
            m_player2->start();
        }
        else
        {
            m_player1->start();
        }
    }
}

CellStatus* TicTacToeWidget::getCells() const
{
    int size = m_rowsColumns * m_rowsColumns;
    CellStatus * cells = new CellStatus[size];

    if(cells != NULL)
    {
        memcpy(cells, m_board, sizeof(CellStatus) *size);
    }

    return cells;
}

void TicTacToeWidget::reset()
{
    setEnabled(true);

    QList<BoardCellButton*> buttons = this->findChildren<BoardCellButton *>();
    foreach(BoardCellButton * button, buttons)
    {
        button->setStatus(CellStatus::Value_Empty);
        int index = button->getIndex();
        m_board[index] = CellStatus::Value_Empty;
    }

    initialize(m_player1, m_player2);
}

int TicTacToeWidget::getRowsColumns() const
{
    return m_rowsColumns;
}

