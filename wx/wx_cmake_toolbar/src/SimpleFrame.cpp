
#include <wx/wx.h>
#include "SimpleMenuBar.h"
#include "SimpleFrame.h"

SimpleFrame::SimpleFrame(const wxString title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(640, 480))
{

  wxMenuBar* simpleBar = new SimpleMenuBar;
  SetMenuBar(simpleBar);

  Center();
}

