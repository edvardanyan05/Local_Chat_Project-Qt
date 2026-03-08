#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QInputDialog>
#include <QTextStream>
#include <QTime>
#include <QTimer>

static QString chatFilePath()
{
    return QCoreApplication::applicationDirPath() + "/chat.txt";
}

static QString currentTime()
{
    return "[" + QTime::currentTime().toString("HH:mm") + "]";
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->sendButton, &QPushButton::clicked,
            this, &MainWindow::sendMessage);

    connect(ui->messageEdit, &QLineEdit::returnPressed,
            this, &MainWindow::sendMessage);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::refreshChat);
    timer->start(500);

    refreshChat();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::sendMessage()
{
    QString message = ui->messageEdit->text().trimmed();
    if (message.isEmpty())
        return;
    ui->messageEdit->clear();

    if (message.startsWith('/')) {
        if(processCommand(message))
            return;
    }

    QFile file(chatFilePath());
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << currentTime() << " " << username << ": " << message << "\n";
    }

}

void MainWindow::refreshChat()
{
    QFile file(chatFilePath());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QStringList lines;

    while (!in.atEnd()) {
        lines.append(in.readLine());
    }

    if (lines.size() > lastLineCount) {
        for (int i = lastLineCount; i < lines.size(); ++i) {
            ui->chatView->append(lines[i]);
        }
        lastLineCount = lines.size();
    }
}

bool MainWindow::processCommand(const QString& message)
{
    // /help
    if (message == "/help") {
        ui->chatView->append(
            "Commands:\n"
            "/help     ->  show commands\n"
            "/clear    ->  clear chat history\n"
            "/newName  ->  change username\n"
            );
        return true;
    }

    // /clear
    if (message == "/clear") {
        QFile file(chatFilePath());
        if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)){
            file.close();

            ui->chatView->clear();
            lastLineCount = 0;
            ui->chatView->append("Chat history has been cleared.");
            return true;
        }else {
            ui->chatView->append("Error: unable to clear chat history.");
        }
    }

    // /newName
    if (message == "/newName") {
        ui->chatView->append("Enter your new name:");
        bool ok;
        QString newName = QInputDialog::getText(
            this,
            "Change username",
            "New name:",
            QLineEdit::Normal,
            username,
            &ok
            );

        if (ok && !newName.trimmed().isEmpty()) {
            ui->chatView->append(
                "Username changed from " + username + " to " + newName
                );
            username = newName;
        }
        return true;
    }

    return false;
}



