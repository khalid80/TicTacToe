#include "mainwindow.h"
#include "tictactoewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
   m_pTicTacToeWidget = new TicTacToeWidget();
   setCentralWidget(m_pTicTacToeWidget);
}

MainWindow::~MainWindow()
{
    if(m_pTicTacToeWidget!= NULL)
    {
        delete m_pTicTacToeWidget;
        m_pTicTacToeWidget = NULL;
    }
}
