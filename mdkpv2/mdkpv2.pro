QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_main.cpp \
    buyed_history.cpp \
    buying_package.cpp \
    change_employes.cpp \
    change_info.cpp \
    change_packages.cpp \
    clientsmodel.cpp \
    employee_main.cpp \
    employees_class.cpp \
    main.cpp \
    mainwindow.cpp \
    packagemodel.cpp \
    registration.cpp \
    show_clients.cpp \
    user_main.cpp \
    userclass.cpp \
    usermodel.cpp \
    users_list.cpp \
    usingdatabase.cpp

HEADERS += \
    admin_main.h \
    buyed_history.h \
    buying_package.h \
    change_employes.h \
    change_info.h \
    change_packages.h \
    clientsmodel.h \
    employee_main.h \
    employees_class.h \
    mainwindow.h \
    packageclass.h \
    packagemodel.h \
    registration.h \
    show_clients.h \
    user_main.h \
    userclass.h \
    usermodel.h \
    users_list.h \
    usingdatabase.h

FORMS += \
    admin_main.ui \
    buyed_history.ui \
    buying_package.ui \
    change_employes.ui \
    change_info.ui \
    change_packages.ui \
    employee_main.ui \
    mainwindow.ui \
    registration.ui \
    show_clients.ui \
    user_main.ui \
    users_list.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
