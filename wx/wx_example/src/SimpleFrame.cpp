#include <wx/wx.h>
#include <iostream>
#include "SimpleMenuBar.h"
#include "SimpleToolBar.h"
#include "SimpleFrame.h"

SimpleFrame::SimpleFrame(const wxString& title, int width, int height)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(width, height))
{
    SimpleMenuBar::Create(this);
    SimpleToolBar::Create(this);
    Center();
}


// Event Handers

void SimpleFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    std::cout << "Event: Quit" << std::endl;
    Close(true);
}

void SimpleFrame::OnOpen(wxCommandEvent& WXUNUSED(event))
{
    std::cout << "Event: Open" << std::endl;
}

void SimpleFrame::OnReload(wxCommandEvent& WXUNUSED(event))
{
    std::cout << "Event: Reload/Refresh" << std::endl;
}


