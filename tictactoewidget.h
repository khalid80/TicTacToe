#ifndef TicTacToEWIDGET_H
#define TicTacToEWIDGET_H

#include <QWidget>
#include "iboard.h"
class Player;

class TicTacToeWidget : public QWidget, public IBoard
{
    Q_OBJECT
    Q_INTERFACES(IBoard)
public:
    explicit TicTacToeWidget(QWidget *parent = 0);
    virtual void onStatusChanged(int row, int col, PlayerType type) override;
    const CellStatus* getCells() const;
    int getRowsColumns() const;
    void reset();
private slots:
    void onClick();

private:
    CellStatus m_board [9];
    Player * m_human;
    Player * m_computer;
    int m_rowsColumns = 3;
};

#endif // TicTacToEWIDGET_H
