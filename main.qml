import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import "routines.js" as Logic


ApplicationWindow {
    title: qsTr("Protolyzer")
    width: 400
    height: 400
    visible: true
    minimumHeight: 400
    minimumWidth: 400



    function write_to_log(line){
        log_output.text += line
    }


    ColumnLayout{
            spacing: 2
            height:300
            width: parent.width
            id: app
            x: 10

            GridLayout {
                id: grid
                columns: 3

                Label { text: "Input pcap file";  }
                TextField {
                    id: input_file_field

                }
                Button {
                    text: "..."
                    onClicked: fileDialogInputFile.open()
                }

                Label { text: "Output directory";  }
                TextField {id: output_dir_field}
                Button {
                    text: "..."
                    onClicked: fileDialogOutputDir.open()
                }

                Label { text: "Size";  }
                TextField {id: size_field; text:"100"}
                Label { text: "MB";  }

                Label { text: "Analysis";  }
                ComboBox {
                    width: 500
                    model: [ "ip", "sip+rtp", "tcp+ip", "dns" ]
                    id: analysis_type
                }
            }


                Button {

                    signal doAnalyzeSignal(string filter_cmd, string worker_cmd, string filter_output)
                    objectName: "myButton"

                    text: "Analyze"
                    onClicked: {                        
                        // Bundle function
                        doAnalyzeSignal(Logic.filter_cmd(), Logic.worker_cmd(), Logic.filter_output())
                        analyzeSignal.writeToLogOutput.connect(write_to_log)
                    }
                }

        }

        TextArea {
            id: log_output
            width: parent.width
            height: parent.height - app.height
            y: app.height
            readOnly: true
        }

        FileDialog {
            id: fileDialogInputFile
            title: "Please choose a file"
            onAccepted: {
                input_file_field.text = fileDialogInputFile.fileUrl
            }
        }

        FileDialog {
            id: fileDialogOutputDir
            title: "Please select output directory"
            selectFolder: true
            onAccepted: {
                output_dir_field.text = fileDialogOutputDir.fileUrl
                console.log("You chose: " + fileDialogOutputDir.fileUrl)
            }
        }

}
