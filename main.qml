import QtQuick 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Escala Do Mayor")
//    Component.onCompleted: randNoteGen.startTimer()
    Button{
        id: botonModo
        property bool modoPrograma: false
        text: modoPrograma ? "Cambiar a notas" : "Cambiar a acordes"
        onClicked: modoPrograma = !modoPrograma
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: texto
        property bool siguienteColor: true
        focus: true //Necesario para detectar las teclas
        font.pixelSize: 80
        color: siguienteColor ? "red" : "blue"
        anchors.centerIn: parent
        Keys.onRightPressed: {
            slider.value = slider.value + 500
            event.accepted = true;
        }
        Keys.onLeftPressed: {
            slider.value = slider.value - 500
            event.accepted = true;
        }
        Keys.onSpacePressed: {
            if (timer.running)
            {
                console.log("Pausa!");
                timer.stop()
            }
            else
            {
                console.log("Continuar!");
                timer.restart()
            }
            event.accepted = true;
        }
        Component.onCompleted: {
            if (botonModo.modoPrograma)
            {
                texto.text = randNoteGen.getRandomChord()
            }
            else
            {
                texto.text = randNoteGen.getRandomNote()
            }
        }
    }

    Slider {
        id: slider
        from: 500
        to: 9500
        stepSize: 500
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        Component.onCompleted: slider.value = 500*10

    }

    Timer{
        id: timer
        interval: slider.to + slider .stepSize - slider.value;
        running: true;
        repeat: true
        onTriggered: {
            if (botonModo.modoPrograma)
            {
                texto.text = randNoteGen.getRandomChord()
            }
            else
            {
                texto.text = randNoteGen.getRandomNote()
            }
            texto.siguienteColor = !texto.siguienteColor
        }
    }
}
