#include <wx/wx.h>
#include "SimpleFrame.h"
#include "SimpleLayout.h"

void SimpleLayout::Create(wxFrame* frame, int width, int height)
{
    wxPanel *panel_top = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(width, 150));
    panel_top->SetBackgroundColour(wxColor(42, 42, 255));
  
    wxPanel *panel_mid = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(width, 150));
    panel_mid->SetBackgroundColour(wxColor(42, 255, 42));
    
    wxPanel *panel_bot = new wxPanel(frame, wxID_ANY, wxDefaultPosition, wxSize(width, 150));
    panel_bot->SetBackgroundColour(wxColor(255, 42, 42));
    
  
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
  
    // proportion - 0 = fixed size, 1 = scales proportionally with container
    // flag wxEXPAND
    // flag wxALL - margins on all sides (wxLEFT, wxRIGHT, wxTOP, wxBOTTOM)
    // border = 5
  
    sizer->Add(panel_top, 0, wxEXPAND | wxALL, 5);  // fixed
    sizer->Add(panel_mid, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 5);  // 1x
    sizer->Add(panel_bot, 2, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 5);  // 2x taller
  
    frame->SetSizerAndFit(sizer);

}








