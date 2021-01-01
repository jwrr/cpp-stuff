
#include <wx/wx.h>
#include "SimpleFrame.h"

SimpleFrame::SimpleFrame(const wxString title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(640, 480))
{
  Center();
}

