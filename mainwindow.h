#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <paintcanvas.h>
#include <QPushButton>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void penWidthChanged(int width);
    void changePenColor();
    void changeFillColor();
    void changeFillProperty();

private:
    Ui::MainWindow *ui;
    PaintCanvas *canvas;
    QPushButton *penColorButton;
    QPushButton *fillColorButton;
    QCheckBox *fillCheckBox;
};
#endif // MAINWINDOW_H
