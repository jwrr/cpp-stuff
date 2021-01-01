#include "wx/wx.h"
#include "SimpleFrame.h"
#include "SimpleApp.h"


bool SimpleApp::OnInit()
{
    wxString title("Hello");
    SimpleFrame *simpleframe = new SimpleFrame(title);
    simpleframe->Show(true);
    return true;
}


