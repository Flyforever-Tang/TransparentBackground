#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include "prolib.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QLabel *oriImagePathLabel;
    QLineEdit *oriImagePathEdit;
    QPushButton *selectButton;
    QPushButton *acceptButton;

    const static int windowWidth = 800, windowHeight = 150;

private:
    void initializeUI();

private slots:
    void selectPath();
    void accept();
};
#endif // MAINWINDOW_H
