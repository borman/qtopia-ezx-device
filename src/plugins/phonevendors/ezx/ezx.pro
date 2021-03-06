qtopia_project(qtopia plugin)
TARGET=ezxvendor

CONFIG+=no_tr

HEADERS		=  ezxplugin.h \
  ezxmodemservice.h \
  ezxvibrateaccessory.h \
  ezxmodempinmanager.h \
  ezxmodemnetworkregistration.h \
  ezxmodemsiminfo.h \
  ezxmodemsupplementaryservices.h \
  ezxmodemsmssender.h \
  ezxmodemcallprovider.h \
  ezxmodemsmsreader.h

SOURCES	        =  ezxplugin.cpp \
  ezxmodemservice.cpp \
  ezxvibrateaccessory.cpp \
  ezxmodempinmanager.cpp \
  ezxmodemnetworkregistration.cpp \
  ezxmodemsiminfo.cpp \
  ezxmodemsupplementaryservices.cpp \
  ezxmodemsmssender.cpp \
  ezxmodemcallprovider.cpp \
  ezxmodemsmsreader.cpp



depends(libraries/qtopiaphonemodem)

