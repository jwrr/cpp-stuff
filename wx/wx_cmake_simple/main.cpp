
#include <wx/wx.h>

class SimpleFrame : public wxFrame
{
public:
    SimpleFrame(const wxString title);

};


SimpleFrame::SimpleFrame(const wxString title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(640, 480))
{
  Center();
}


class SimpleApp : public wxApp
{
  public:
    virtual bool OnInit();
};


bool SimpleApp::OnInit()
{
    wxString title("Hello");
    SimpleFrame *simpleframe = new SimpleFrame(title);
    simpleframe->Show(true);
    return true;
}


// main polling loop
IMPLEMENT_APP(SimpleApp)

