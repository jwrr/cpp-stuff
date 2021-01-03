#include <wx/wx.h>
#include <iostream>
#include "SimpleToolBarFrame.h"

SimpleToolBarFrame::SimpleToolBarFrame(const wxString& title, int width, int height)
       : wxFrame(NULL, wxID_ANY, title, 
                 wxDefaultPosition, wxSize(width, height)) {

    wxToolBar *toolbar = CreateToolBar();
    wxImage::AddHandler(new wxPNGHandler);

    // EXIT
    wxBitmap bmp_exit(wxT("img/exit.png"), wxBITMAP_TYPE_PNG);
    toolbar->AddTool(wxID_EXIT, wxT("Exit application"), bmp_exit);
    Connect(wxID_EXIT, wxEVT_COMMAND_TOOL_CLICKED, 
        wxCommandEventHandler(SimpleToolBarFrame::OnQuit));
        
    // OPEN
    wxBitmap bmp_open(wxT("img/open.png"), wxBITMAP_TYPE_PNG);
    toolbar->AddTool(wxID_OPEN, wxT("Open File"), bmp_open);
    Connect(wxID_OPEN, wxEVT_COMMAND_TOOL_CLICKED, 
    wxCommandEventHandler(SimpleToolBarFrame::OnOpen));
    
    // RELOAD
    wxBitmap bmp_reload(wxT("img/reload.png"), wxBITMAP_TYPE_PNG);
    toolbar->AddTool(wxID_REFRESH, wxT("Reload File"), bmp_reload);
    Connect(wxID_REFRESH, wxEVT_COMMAND_TOOL_CLICKED, 
    wxCommandEventHandler(SimpleToolBarFrame::OnReload));
  

    toolbar->Realize();
}

void SimpleToolBarFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
    std::cout << "Toolbar: Quit" << std::endl;
    Close(true);
}

void SimpleToolBarFrame::OnOpen(wxCommandEvent& WXUNUSED(event)) {
    std::cout << "Toolbar: Open" << std::endl;
}

void SimpleToolBarFrame::OnReload(wxCommandEvent& WXUNUSED(event)) {
    std::cout << "Toolbar: Reload/Refresh" << std::endl;
}


