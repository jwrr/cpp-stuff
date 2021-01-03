#include <wx/wx.h>
#include "SimpleToolBarApp.h"
#include "SimpleToolBarFrame.h"

bool SimpleToolBarApp::OnInit() {

    SimpleToolBarFrame *toolbar = new SimpleToolBarFrame(wxT("SimpleToolBar"), 800, 600 );
    toolbar->Show(true);

    return true;
}

