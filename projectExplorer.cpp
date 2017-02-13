#include "projectExplorer.h"

ProjectExplorer::ProjectExplorer()
{
    fileSystemModel = new QFileSystemModel();
    fileSystemModel->setRootPath(globalVar::clara_home);
    this->header()->hide();
    this->setModel(fileSystemModel);
    this->setRootIndex(fileSystemModel->index(globalVar::clara_home));
    this->setColumnHidden(1,true);
    this->setColumnHidden(2,true);
    this->setColumnHidden(3,true);
}
