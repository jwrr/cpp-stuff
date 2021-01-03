#include <iostream>
#include <wx/wx.h>
#include "SimpleToolBar.h"
#include "SimpleFrame.h"


void SimpleToolBar::Create(wxFrame* frame)
{
    wxToolBar* toolbar = frame->CreateToolBar();
    wxImage::AddHandler(new wxPNGHandler);
    
    // EXIT
    wxBitmap bmp_exit(wxT("img/exit.png"), wxBITMAP_TYPE_PNG);
    toolbar->AddTool(wxID_EXIT, wxT("Exit application"), bmp_exit);
    frame->Connect(wxID_EXIT, wxEVT_COMMAND_TOOL_CLICKED, 
        wxCommandEventHandler(SimpleFrame::OnQuit));
        
    // OPEN
    wxBitmap bmp_open(wxT("img/open.png"), wxBITMAP_TYPE_PNG);
    toolbar->AddTool(wxID_OPEN, wxT("Open File"), bmp_open);
    frame->Connect(wxID_OPEN, wxEVT_COMMAND_TOOL_CLICKED, 
    wxCommandEventHandler(SimpleFrame::OnOpen));
    
    // RELOAD
    wxBitmap bmp_reload(wxT("img/reload.png"), wxBITMAP_TYPE_PNG);
    toolbar->AddTool(wxID_REFRESH, wxT("Reload File"), bmp_reload);
    frame->Connect(wxID_REFRESH, wxEVT_COMMAND_TOOL_CLICKED, 
    wxCommandEventHandler(SimpleFrame::OnReload));
    
    toolbar->Realize();
}








