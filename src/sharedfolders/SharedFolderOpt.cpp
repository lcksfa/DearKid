#include "SharedFolderOpt.h"

#include <Windows.h>
#include <tchar.h>
#include <WinNetWk.h>
#include <stdio.h>
#include <QString>
#include <QDir>

#pragma comment(lib, "Mpr.lib")

namespace
{
const static LPTSTR SharedFolderRemotePath = TEXT("\\\\192.168.1.166\\sharedFolder");
const static LPTSTR SharedFolderLocalDriver = TEXT("Z:");
} // namespace

bool SharedFolderOpt::open()
{
    NETRESOURCE net_Resource;
    net_Resource.dwDisplayType = RESOURCEDISPLAYTYPE_DIRECTORY;
    net_Resource.dwScope = RESOURCE_CONNECTED;
    net_Resource.dwType = RESOURCETYPE_ANY;
    net_Resource.dwUsage = 0;
    net_Resource.lpComment = TEXT("");
    net_Resource.lpLocalName = SharedFolderLocalDriver; //映射成本地驱动器z:
    net_Resource.lpProvider = NULL;
    net_Resource.lpRemoteName = SharedFolderRemotePath; // 共享资源名
    DWORD dwFlags = CONNECT_UPDATE_PROFILE;
    // TCHAR szPasswd[] = TEXT("");//TEXT("90523");          //共享资源授权用户的密码
    // TCHAR szUserName[] = TEXT("");//TEXT("Administrator");        //共享资源授权的用户
    DWORD dw = WNetAddConnection2(&net_Resource, NULL, NULL, dwFlags);

    return NO_ERROR == dw || ERROR_ALREADY_ASSIGNED == dw;
    // error handling
    // switch (dw)
    // {
    // case ERROR_SUCCESS:
    // 	ShellExecute(NULL, TEXT("open"), TEXT("z:"), NULL, NULL, SW_SHOWNORMAL);
    // 	break;
    // case ERROR_ACCESS_DENIED:
    // 	wprintf(TEXT("没有权访问！"));
    // 	break;
    // case ERROR_ALREADY_ASSIGNED:
    // 	ShellExecute(NULL, TEXT("open"), TEXT("z:"), NULL, NULL, SW_SHOWNORMAL);
    // 	break;
    // case ERROR_INVALID_ADDRESS:
    // 	wprintf(TEXT("IP地址无效"));
    // 	break;
    // case ERROR_NO_NETWORK:
    // 	wprintf(TEXT("网络不可达!"));
    // 	break;
}

bool SharedFolderOpt::close()
{
    auto ret = WNetCancelConnection2(SharedFolderLocalDriver, CONNECT_UPDATE_PROFILE, TRUE);
    return NO_ERROR == ret;
}

QStringList SharedFolderOpt::getSubdirs()
{
    QStringList subdirs;
    QString basePath(QString::fromUtf16(
        reinterpret_cast<const unsigned short *>(SharedFolderLocalDriver)));
    QDir baseDir(basePath);
    baseDir.setFilter(QDir::AllDirs | QDir::NoDotDot);
    QFileInfoList filesInfoList = baseDir.entryInfoList();
    foreach (const QFileInfo& info, filesInfoList) {
        auto absolutePath = info.absoluteFilePath();
        subdirs << absolutePath;
    }
    return subdirs;
}
