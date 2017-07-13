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

void TicTacToeWidget::onStatusChanged(int row, int col, PlayerType type, CellStatus status)
{
    int index = row * m_rowsColumns + col;
    m_board[index] = status;
    QList<BoardCellButton*> buttons = this->findChildren<BoardCellButton *>();
    BoardCellButton * cell = buttons[index];
    cell->setStatus(status);

    if(getWinner() != CellStatus::Value_Empty)
    {
        qDebug()<< type;
        setEnabled(false);
    }
    else
    {
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

CellStatus TicTacToeWidget:: checkSum(int value) const
{
    float val = (float)(value)/(float)(m_rowsColumns);

    if(val == CellStatus::Value_O || val == CellStatus::Value_X)
        return (CellStatus)(int)val;

    return CellStatus::Value_Empty;
}

CellStatus TicTacToeWidget:: getWinner() const
{
    // check diagonals
    int firstDiagonal = 0;
    int secondDiagonal = 0;
    for(int i = 0; i < m_rowsColumns; ++i)
    {
         firstDiagonal+= m_board[i * 3 + i];
         secondDiagonal+= m_board[i * 3 + m_rowsColumns - i -1];
    }

    qDebug()<<"First"<<firstDiagonal;
    qDebug()<<"Second"<<secondDiagonal;

    CellStatus status = checkSum(firstDiagonal);
    if( status != CellStatus::Value_Empty)
        return status;

    status = checkSum(secondDiagonal);
    if( status != CellStatus::Value_Empty)
        return status;

    for(int row =0; row < m_rowsColumns; ++row)
    {
        int rowSum = 0;
        int columnSum = 0;
        for(int col =  0; col < m_rowsColumns; ++col)
        {
            rowSum += m_board[row * m_rowsColumns + col];
            columnSum += m_board[col *m_rowsColumns + row];
        }

        status = checkSum(rowSum);
        if( status != CellStatus::Value_Empty)
            return status;

        status = checkSum(columnSum);
        if( status != CellStatus::Value_Empty)
            return status;
    }

    return CellStatus::Value_Empty;
}

