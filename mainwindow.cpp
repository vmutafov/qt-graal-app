#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "libgraalmultiply.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setLabelText();
}

void MainWindow::setLabelText() {
    graal_isolate_t *isolate = NULL;
    graal_isolatethread_t *thread = NULL;

    if (graal_create_isolate(NULL, &isolate, &thread) != 0) {
        fprintf(stderr, "initialization error\n");
        return;
    }

    int multiplyResult = graal_multiply(thread, 6, 7);

    QString msg = QString("Multiplication result:  %1").arg(multiplyResult);
    ui->resultLbl->setText(msg);

    graal_tear_down_isolate(thread);
}

MainWindow::~MainWindow()
{
    delete ui;
}

