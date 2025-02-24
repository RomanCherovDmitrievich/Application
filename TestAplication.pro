QT       += core gui
QT       += sql
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    autorization.cpp \
    main.cpp \
    mainwindow.cpp \
    secondwindow.cpp

HEADERS += \
    autorization.h \
    mainwindow.h \
    secondwindow.h

FORMS += \
    autorization.ui \
    mainwindow.ui \
    secondwindow.ui

TRANSLATIONS += \
    TestAplication_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations


#macx {
 #   INCLUDEPATH += "/path_to_opencv/include"
  #  LIBS += -L"/path_to_opencv/lib" \
   # -l"opencv_world"
#}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
