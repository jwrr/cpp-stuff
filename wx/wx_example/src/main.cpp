#include <wx/wx.h>
#include "SimpleFrame.h"

class SimpleApp : public wxApp {
    public:
        virtual bool OnInit();
};

bool SimpleApp::OnInit() {
    SimpleFrame *frame = new SimpleFrame(wxT("SimpleApp"), 640, 480 );
    frame->Show(true);
    return true;
}

// --------------------------------------------------------------------

// main polling loop
IMPLEMENT_APP(SimpleApp)

