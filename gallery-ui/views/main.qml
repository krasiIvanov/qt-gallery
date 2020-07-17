import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.2
import QtQml.Models 2.2
import GALLERY 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Gallery")
    Rectangle{
        anchors.fill: parent
        GridView{
            id:image_grid
            width: parent.width
            height: parent.height
            clip: true
            cellWidth: parent.width*0.2;
            cellHeight: parent.width*0.2
            model:DelegateModel{
                id:viewModel
                model: ImageListModel{
                }
                delegate: Rectangle{
                    id: root
                    width: image_grid.cellWidth
                    height: image_grid.cellHeight
                    Image {
                        id: icon
                        height: root.height*0.9
                        width: root.height*0.7
                        source: "file:" + model.name
                        anchors.horizontalCenter: root.horizontalCenter
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: parent.height*0.15                        
                    }
                }
            }
        }
    }
}
