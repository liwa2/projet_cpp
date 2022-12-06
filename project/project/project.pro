QT       += core gui sql charts \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accommodation.cpp \
    chatbox.cpp \
    client.cpp \
    client_interface.cpp \
    client_profil.cpp \
    connexion.cpp \
    dialog.cpp \
    employee.cpp \
    historique.cpp \
    main.cpp \
    mainwindow.cpp \
    notif_space.cpp \
    payment.cpp \
    profil.cpp \
    replyy.cpp \
    reservation.cpp \
    review.cpp

HEADERS += \
    accommodation.h \
    chatbox.h \
    client.h \
    client_interface.h \
    client_profil.h \
    connexion.h \
    dialog.h \
    employee.h \
    historique.h \
    mainwindow.h \
    notif_space.h \
    payment.h \
    profil.h \
    replyy.h \
    reservation.h \
    review.h

FORMS += \
    chatbox.ui \
    client_interface.ui \
    dialog.ui \
    mainwindow.ui \
    notif_space.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc \
    login_ressources.qrc
