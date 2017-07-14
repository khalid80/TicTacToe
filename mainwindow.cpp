#include "mainwindow.h"
#include "tictactoewidget.h"
#include "QVBoxLayout"
#include "QPushButton"
#include "QApplication"
#include "settings.h"
#include "QMessageBox"
#include "human.h"
#include "computerplayer.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setFixedSize(sizeHint());

    m_pTicTacToeWidget = new TicTacToeWidget();
    m_you = new HumanPlayer(QString("You"), m_pTicTacToeWidget, CellStatus::Value_X);
    m_computer = new ComputerPlayer(m_pTicTacToeWidget, CellStatus::Value_O);

    m_pTicTacToeWidget->initialize(m_you, m_computer);
    m_pTicTacToeWidget->setSizePolicy(QSizePolicy::QSizePolicy::Maximum, QSizePolicy::QSizePolicy::Maximum);
    m_pTicTacToeWidget->setMaximumSize(500,500);

    QWidget *widget = new QWidget;
    QVBoxLayout *vLayout = new QVBoxLayout;

    // create buttons
    QPushButton * reset = new QPushButton("Reset", widget);
    connect(reset, SIGNAL(clicked()), this, SLOT(onResetClick()));

    QPushButton * quit = new QPushButton("Quit", widget);
    connect(quit, SIGNAL(clicked()), this, SLOT(onQuitClick()));

    QPushButton * info = new QPushButton("Info", widget);
    connect(info, SIGNAL(clicked()), this, SLOT(onInfoClick()));

    QPushButton * settings = new QPushButton("Settings", widget);
    connect(settings, SIGNAL(clicked()), this, SLOT(onSettingsClick()));

    //add buttons to VBox
    vLayout->addWidget(m_pTicTacToeWidget, 0, Qt::AlignCenter);
    vLayout->addWidget(reset);
    vLayout->addWidget(quit);
    vLayout->addWidget(settings);
    vLayout->addWidget(info);

    widget->setLayout(vLayout);

    setCentralWidget(widget);
}

void MainWindow::onResetClick()
{
    m_pTicTacToeWidget->reset();
}

void MainWindow::onQuitClick()
{
    QApplication::quit();
}

void MainWindow::onInfoClick()
{
    if(m_you!=NULL)
    {
        int total = m_you->getTotalGames();
        int wins = m_you->getWins();
        int ties = m_you->getTies();
        int loss = total - wins - ties;

        QString info = QString("(Wins :%1) \n (Ties : %2) \n (Loss : %3) \n (Total games:%4)").arg(QString::number(wins), QString::number(ties),  QString::number(loss), QString::number(total) );

        QMessageBox::information(NULL, "Results", info);
    }
}

void MainWindow::onSettingsClick()
{
    QMessageBox::StandardButton reply;
    QString title = "X or O?";
    CellStatus status = m_you->getStatus();

    QString text = status  == Value_O ? "You choosed  O. Want to Change to X ?" : "You choosed  X. Want to Change to O ?";
    reply = QMessageBox::question(this, title, text, QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        if(status == Value_X)
        {
            m_computer->setStatus(CellStatus::Value_X);
            m_you->setStatus(CellStatus::Value_O);
        }
        else
        {
            m_computer->setStatus(CellStatus::Value_O);
            m_you->setStatus(CellStatus::Value_X);
        }
        m_pTicTacToeWidget->reset();
    }
}

MainWindow::~MainWindow()
{
    if(m_pTicTacToeWidget!= NULL)
    {
        delete m_pTicTacToeWidget;
        m_pTicTacToeWidget = NULL;
    }
}
