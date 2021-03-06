# Add more folders to ship with the application, here
folder_01.source = qml/MeraRemoteControl
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    carcontroller.cpp \
    gpio.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2controlsapplicationviewer/qtquick2controlsapplicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    carcontroller.h \
    gpio.h \
    post.h

OTHER_FILES += \
    qml/MeraRemoteControl/SettingsWindow.qml \
    qml/MeraRemoteControl/ControllerWindow.qml
