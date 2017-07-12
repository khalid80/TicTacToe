#include "TicTacToewidget.h"
#include <QGridLayout>
#include <boardcellbutton.h>
#include <QObject>
#include "computerplayer.h"
#include "human.h"
#include "qdebug.h"
TicTacToeWidget::TicTacToeWidget(QWidget *parent) : QWidget(parent),
  m_rowsColumns(3)
{
    QGridLayout *gridLayout = new QGridLayout;

    m_human = new HumanPlayer(QString("khalid"), this, CellStatus::Value_O);

    m_computer = new ComputerPlayer(this, CellStatus::Value_X);

    int size =  m_rowsColumns * m_rowsColumns;

    for(int i = 0; i < size; ++i)
    {

        m_board[i] = CellStatus::Value_Empty;
        BoardCellButton * cell= new BoardCellButton(i);
        gridLayout->addWidget(cell, i / m_rowsColumns, i % m_rowsColumns);
        connect(cell, SIGNAL(clicked()), this, SLOT(onClick()));
        connect(cell, SIGNAL(statusChanged(int index, IBoard::CellStatus)), this, SLOT(onStatusChanged(int, IBoard::CellStatus)));
    }

    setLayout(gridLayout);
    //resize(800, 600);
}


void TicTacToeWidget::onClick()
{
    BoardCellButton *cell = qobject_cast<BoardCellButton*>(sender());

    if(cell->getStatus() == CellStatus::Value_Empty)
        m_human->start(cell->getIndex());
}

void TicTacToeWidget::onStatusChanged(int row, int col, PlayerType type)
{
    int index = row * m_rowsColumns + col;
    m_board[index] = CellStatus::Value_O;
    QList<BoardCellButton*> buttons = this->findChildren<BoardCellButton *>();
    BoardCellButton * cell = buttons[index];
    cell->setStatus(CellStatus::Value_O);
    if(type == PlayerType::Human)
    {
        /*foreach(BoardCellButton * button, buttons)
        {
            //button->setEnabled(false);
        }*/

        setEnabled(false);
        m_computer->start();
        //Disable
        // give chance to computer
    }
    else
    {
        cell->setStatus(CellStatus::Value_X);
        setEnabled(true);
        //cell->setEnabled(false);
        //enable who is not empty;

        /*foreach(BoardCellButton * button, buttons)
        {
            if(button->getStatus() == CellStatus::Value_Empty)
                button->setEnabled(true);\
        }*/
    }
}

const CellStatus* TicTacToeWidget::getCells() const
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
}

int TicTacToeWidget::getRowsColumns() const
{
    return m_rowsColumns;
}
