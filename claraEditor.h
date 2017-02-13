/*#ifndef CLARAEDITOR_H
#define CLARAEDITOR_H

#include <QTextEdit>
#include <QWidget>
#include <QScrollBar>
#include <QTextBlock>
#include <QAbstractTextDocumentLayout>
#include <QPainter>


class LineNumberArea : public QWidget
{
    Q_OBJECT

public:
    LineNumberArea(QTextEdit *editor);

    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *event);

private:
    QTextEdit *codeEditor;
};


class ClaraEditor : public QTextEdit
{
    Q_OBJECT
public:
    explicit ClaraEditor();

    int getFirstVisibleBlockId();
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

signals:


public slots:

    void resizeEvent(QResizeEvent *e);

private slots:

    void updateLineNumberAreaWidth(int newBlockCount);
    void updateLineNumberArea(QRectF /*rect_f*/);
/*    void updateLineNumberArea(int /*slider_pos*/);
/*    void updateLineNumberArea();

private:

    QWidget *lineNumberArea;

};

#endif // CLARAEDITOR_H
