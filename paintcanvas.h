#ifndef PAINTCANVAS_H
#define PAINTCANVAS_H

#include <QWidget>

class PaintCanvas : public QWidget
{
    Q_OBJECT
public:

    enum ToolType {Pen, Rect, Ellipse, Eraser};
    explicit PaintCanvas(QWidget *parent = nullptr);

    int getPenWidth() const;
    void setPenWidth(int newPenWidth);

    QColor getFillColor() const;
    void setFillColor(const QColor &newFillColor);

    QColor getPenColor() const;
    void setPenColor(const QColor &newPenColor);

    ToolType getTool() const;
    void setTool(ToolType newTool);

    bool getFill() const;
    void setFill(bool newFill);

signals:

private:

    void drawLineTo(const QPoint &endPoint);
    void drawRectTo(const QPoint &endPoint, bool ellipse = false);
    void eraseUnder(const QPoint &topLeft);

    void resizeImage(QImage *image,const QSize &newSize);

    ToolType tool;
    bool fill;
    bool drawing;
    int penWidth;
    QColor fillColor;
    QColor penColor;
    QPoint lastPoint;
    QRectF lastRect;
    QRectF lastEraserRect;
    QImage image;


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
};

#endif // PAINTCANVAS_H
