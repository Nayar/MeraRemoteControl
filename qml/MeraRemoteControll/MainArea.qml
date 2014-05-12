import QtQuick 2.0

Item {
    id: mainArea
    width: 400
    height: 400

    state : "control"

    states: [
        State {
            name: "control"
            PropertyChanges {
                target: controllers;
                anchors.centerIn: mainArea
            }
            PropertyChanges {
                target: settings;
                x: mainArea.width
            }
        },
        State {
            name: "settings"
            PropertyChanges {
                target: settings;
                anchors.centerIn: mainArea
            }
            PropertyChanges {
                target: controllers;
                x: mainArea.width
            }
        }

    ]


    ControllerWindow{
        id: controllers
        Behavior on x { SmoothedAnimation { velocity: 5000 } }
    }

    SettingsWindow{
        id: settings
        height: mainArea.height
        Behavior on x { SmoothedAnimation { velocity: 5000 } }
    }
}
