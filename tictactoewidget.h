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
    virtual void onStatusChanged(int row, int col, Player * player, bool disableBoard) override;
    CellStatus* getCells() const override;
    int getRowsColumns() const override;
    void reset();
    void initialize(Player *, Player *);
private slots:
    void onClick();

private:
    CellStatus m_board [9];
    Player * m_player1;
    Player * m_player2;
    int m_rowsColumns = 3;
    bool m_initialized;
};

#endif // TicTacToEWIDGET_H
