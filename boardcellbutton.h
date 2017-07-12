#ifndef BOARDCELLBUTTON_H
#define BOARDCELLBUTTON_H
#include <QObject>
#include <QPushButton>
#include "enums.h"
class IBoard;
class BoardCellButton : public QPushButton
{
    Q_OBJECT
public:
    BoardCellButton(int index);
    virtual ~BoardCellButton();

    int getIndex();
    void setStatus(CellStatus status);
    CellStatus getStatus();

private:
    QPixmap XIcon ; //TODO: these resources need to be static
    QPixmap OIcon ;
    QPixmap EmptyIcon ;

    int m_index;
    CellStatus m_status;
};

#endif // BOARDCELLBUTTON_H
