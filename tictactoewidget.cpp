#include "TicTacToewidget.h"
#include <QGridLayout>
#include <boardcellbutton.h>
#include <QObject>
#include "computerplayer.h"
#include "human.h"
#include "qdebug.h"
TicTacToeWidget::TicTacToeWidget(QWidget *parent) : QWidget(parent)
{
    QGridLayout *gridLayout = new QGridLayout;

    m_human = new HumanPlayer(QString("khalid"), this, CellStatus::Value_O);
    m_computer = new ComputerPlayer(this, CellStatus::Value_X);

    for(int i = 0; i < 9; ++i)
    {
        m_board[i] = CellStatus::Value_Empty;
        BoardCellButton * cell= new BoardCellButton(i);
        gridLayout->addWidget(cell, i / 3, i % 3);
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
    m_board[row *3 +col] = CellStatus::Value_O;
    QList<BoardCellButton*> buttons = this->findChildren<BoardCellButton *>();
    BoardCellButton * cell = buttons[row*3 + col];
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
    CellStatus * x = new CellStatus[9];
    memcpy(x, m_board, sizeof(CellStatus) * 9);
    return x;
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
