#ifndef __SHAREDFOLDEROPT_H__
#define __SHAREDFOLDEROPT_H__

#include <QStringList>

class SharedFolderOpt
{
public:
    SharedFolderOpt(){}
    bool open();
    bool close();
    QStringList getSubdirs();

};
#endif // __SHAREDFOLDEROPT_H__