#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    
    ui->setupUi(this);
    player1Time = 0;
    player2Time = 0;
    currentPlayer = 1;
    gameTime = 0;

    pQTimer = new QTimer(this);
    connect(pQTimer, &QTimer::timeout, this, &MainWindow::timeout);

    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);
    ui->switchPlayer->setEnabled(false);
    ui->switchPlayer2->setEnabled(false);

    setGameInfoText("Select playtime and press start game!", 12);

    connect(ui->btn120sec, &QPushButton::clicked, this, [=]() {
        gameTime = 120;
        player1Time = 120;
        player2Time = 120;
        updateProgressBar();
        setGameInfoText("ready to play", 14);
});

    connect(ui->btn5min, &QPushButton::clicked, this, [=]() {
        gameTime = 300;
        player1Time = 300;
        player2Time = 300;
        updateProgressBar();
        setGameInfoText("ready to play", 14);
});

    connect(ui->startGame, &QPushButton::clicked, this, [=]() {
        if (gameTime == 0) {
            return;
        }
        currentPlayer = 1;
        pQTimer->start(1000);
        ui->switchPlayer->setEnabled(true);
        ui->switchPlayer2->setEnabled(false);
        setGameInfoText("Game ongoing", 14);
    });

    connect(ui->stopGame, &QPushButton::clicked, this, [=]() {
        pQTimer->stop();
        player1Time = 0;
        player2Time = 0;
        gameTime = 0;
        currentPlayer = 1;
        ui->switchPlayer->setEnabled(false);
        ui->switchPlayer2->setEnabled(false);
        updateProgressBar();
        setGameInfoText("New game via start button", 12);
    });

    connect(ui->switchPlayer, &QPushButton::clicked, this, [=]() {
        if (currentPlayer == 1) {
            currentPlayer = 2;
            ui->switchPlayer->setEnabled(false);
            ui->switchPlayer2->setEnabled(true);
        }
    });

    connect(ui->switchPlayer2, &QPushButton::clicked, this, [=]() {
        if (currentPlayer == 2) {
            currentPlayer = 1;
            ui->switchPlayer2->setEnabled(false);
            ui->switchPlayer->setEnabled(true);
        }
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::timeout() {
    if (currentPlayer == 1) {
        player1Time--;
    } else {
        player2Time--;
    }
    updateProgressBar();
    if (player1Time <= 0) {
        pQTimer->stop();
        ui->switchPlayer->setEnabled(false);
        ui->switchPlayer2->setEnabled(false);
        setGameInfoText("Player 2 WON!!", 14);
    } else if (player2Time <= 0) {
        pQTimer->stop();
        ui->switchPlayer->setEnabled(false);
        ui->switchPlayer2->setEnabled(false);
        setGameInfoText("Player 1 WON!!", 14);
    }
}

void MainWindow::updateProgressBar() {
    int p1 = 0;
    int p2 = 0;
    if (gameTime > 0) {
        p1 = (player1Time * 100) / gameTime;
        p2 = (player2Time * 100) / gameTime;
    }
    ui->progressBar->setValue(p1);
    ui->progressBar_2->setValue(p2);
}
void MainWindow::setGameInfoText(QString text, short fontSize)
{
    ui->label->setText(text);
    QFont font = ui->label->font();
    font.setPointSize(fontSize);
    font.setBold(true);
    ui->label->setFont(font);
}
