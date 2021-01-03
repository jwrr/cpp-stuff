#include <wx/wx.h>
#include "SimpleFrame.h"

class SimpleApp : public wxApp {
    public:
        virtual bool OnInit();
};

bool SimpleApp::OnInit() {
    SimpleFrame *toolbar = new SimpleFrame(wxT("SimpleApp"), 800, 600 );
    toolbar->Show(true);
    return true;
}


// main polling loop
IMPLEMENT_APP(SimpleApp)

