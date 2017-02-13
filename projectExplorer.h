#ifndef PROJECTEXPLORER_H
#define PROJECTEXPLORER_H

#include <QTreeView>
#include <QHeaderView>
#include <QFileSystemModel>

#include "claraTerminal.h"

class ProjectExplorer : public QTreeView
{
public:
    ProjectExplorer();
private:
    QFileSystemModel *fileSystemModel;
};

#endif // PROJECTEXPLORER_H
