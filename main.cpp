#include "qtquick2controlsapplicationviewer.h"
#include <QtQml>
#include "carcontroller.h"

int main(int argc, char *argv[])
{
    Application app(argc, argv);

    qmlRegisterType<CarController>("MeraCar",1,4,"MeraCar");
    qmlRegisterType<GPIO>("MeraCar",1,4,"GPIO");

    QtQuick2ControlsApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/MeraRemoteControll/main.qml"));
    viewer.show();

    return app.exec();
}
