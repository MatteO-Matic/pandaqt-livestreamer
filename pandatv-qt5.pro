#-------------------------------------------------
#
# Project created by QtCreator 2016-06-25T02:42:08
#
#-------------------------------------------------

QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pandatv-qt5
TEMPLATE = app


SOURCES += main.cpp\
        pandaqt5.cpp \
    customwidgets/imagebutton.cpp \
    forms/FormSettings.cpp \
    customwidgets/pandalistwidget.cpp \
    forms/formgamecategories.cpp \
    pandanetworkcontroller.cpp \
    customwidgets/pandatvchannelthumbnail.cpp \
    customwidgets/pandatvgamecategorythumbnail.cpp \
    forms/formbookmarks.cpp \
    forms/formchannels.cpp


HEADERS  += pandaqt5.h \
    customwidgets/imagebutton.h \
    forms/FormSettings.h \
    customwidgets/pandalistwidget.h \
    forms/formgamecategories.h \
    pandanetworkcontroller.h \
    customwidgets/pandatvchannelthumbnail.h \
    customwidgets/pandatvgamecategorythumbnail.h \
    forms/formbookmarks.h \
    forms/formchannels.h

FORMS    += pandaqt5.ui \
    forms/FormSettings.ui \
    forms/formgamecategories.ui \
    forms/formbookmarks.ui \
    forms/formchannels.ui

DISTFILES += \
    misc/streamerQueryOnGame.json \
    misc/UrlConst.java \
    misc/jsonChannellistReq

RESOURCES += \
    thumbnail.qrc

#QT += snore-qt5
#QT += snoresettings-qt5

#INCLUDEPATH += $$PWD/../../../../usr/include/libsnore
#DEPENDPATH += $$PWD/../../../../usr/include/libsnore

#LIBS += -L/usr/lib -lsnore-qt5
#LIBS += -lsnore-qt5


#QT += LibsnoreQt5
#QT += LibsnoreSettingsQt5

#unix: CONFIG += link_pkgconfig
#unix: PKGCONFIG += lsnore-qt5
