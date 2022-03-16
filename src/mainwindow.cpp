#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initializeUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeUI()
{
    setWindowTitle("TransparentBackground  --- Dev. by BIT_TYX");
    setFixedSize(windowWidth, windowHeight);

    oriImagePathLabel = new QLabel(this);
    oriImagePathLabel ->setGeometry(30, 30, 170, 30);
    oriImagePathLabel ->setFont(QFont("Timers", 13, QFont::Bold));
    oriImagePathLabel ->setAlignment(Qt::AlignRight);
    oriImagePathLabel ->setText("Ori Image Path");

    oriImagePathEdit = new QLineEdit(this);
    oriImagePathEdit ->setGeometry(210, 30, windowWidth - 360, 30);
    oriImagePathEdit ->setFont(QFont("Timers", 13, QFont::Bold));
    oriImagePathEdit ->setText(QApplication::applicationDirPath());

    selectButton = new QPushButton(this);
    selectButton ->setGeometry(windowWidth - 130, 30, 100, 30);
    selectButton ->setFont(QFont("Timers", 13, QFont::Bold));
    selectButton ->setText("Select");
    QObject::connect(selectButton, SIGNAL(clicked()), this, SLOT(selectPath()));

    acceptButton  = new QPushButton(this);
    acceptButton ->setGeometry(windowWidth / 2 - 75, 80, 150, 50);
    acceptButton ->setFont(QFont("Timers", 15, QFont::Bold));
    acceptButton ->setText("Accept");
    QObject::connect(acceptButton, SIGNAL(clicked()), this, SLOT(accept()));

}

void MainWindow::selectPath()
{
    QString static lastPath = QApplication::applicationDirPath();
    QString oriImagePath = QFileDialog::getOpenFileName(this, tr("Select Image"), lastPath, tr("Image (*.png; *.jpg)"));
    if(!oriImagePath.isEmpty())
    {
        oriImagePathEdit ->setText(oriImagePath);
        lastPath = oriImagePath;
    }  
}

void MainWindow::accept()
{
    QString newImagePath = QFileDialog::getSaveFileName(this, tr("Save Image"), oriImagePathEdit ->text(), tr("Image (*.png)"));
    if(!newImagePath.isEmpty())
    {
        QImage* newImage = transparent(oriImagePathEdit ->text());
        if(newImage == nullptr)
        {
            QMessageBox::warning(nullptr, "Wrong Image", "Please select RGBA Image!");
            return;
        }
        newImage ->save(newImagePath, "PNG", 100);
        delete newImage;
    }
}
