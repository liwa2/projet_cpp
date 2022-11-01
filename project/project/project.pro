QT       += core gui sql charts \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accommodation.cpp \
    client.cpp \
    connexion.cpp \
    dialog.cpp \
    employee.cpp \
    main.cpp \
    mainwindow.cpp \
    payment.cpp \
    profil.cpp \
    reservation.cpp

HEADERS += \
    accommodation.h \
    client.h \
    connexion.h \
    dialog.h \
    employee.h \
    mainwindow.h \
    payment.h \
    profil.h \
    reservation.h

FORMS += \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc \
    login_ressources.qrc
