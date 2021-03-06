#include "stdafx.h"
#include "mind_map_model.h"
#include "mind_map_presentation_model.h"
#include "mind_map_window.h"
#include "text_ui_view.h"
#include "text_ui_controller.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    int mode = 1;
    cout <<
         "Choose UI mode:\n"
         "1. GUI window\n"
         "2. Console\n";
    cin >> mode;
    MindMapModel mindMapModel;
    if (mode == 1) {
        QApplication a(argc, argv);
        MindMapPresentationModel mindMapPresentationModel(&mindMapModel);
        MindMapWindow window(&mindMapPresentationModel);
        window.show();
        return a.exec();
    } else if (mode == 2) {
        TextUIView textUIView(cout);
        TextUIController textUIController(&mindMapModel, &textUIView);
        textUIController.run();
    }
    return 0;
}
