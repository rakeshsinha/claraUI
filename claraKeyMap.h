#ifndef KEYMAP_H
#define KEYMAP_H


#include <QMap>
#include <QKeyEvent>
#include <QString>

class ClaraKeyMap
{
private:
    ClaraKeyMap();
public:
    static const QMap<Qt::Key, QString> keyMapSmallCase;
};

#endif // KEYMAP_H
