#include <wx/wx.h>
#include <iostream>
#include "SimpleMenuBar.h"
#include "SimpleToolBar.h"
#include "SimpleLayout.h"
#include "SimpleFrame.h"

SimpleFrame::SimpleFrame(const wxString& title, int width, int height) :
wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(width, height))
{
    Center();
    SimpleMenuBar::Create(this);
    SimpleToolBar::Create(this);
    SimpleLayout::Create(this, width, height);
}

// ----------------------------------------------------------------------------
// Event Handers


void SimpleFrame::OnClose(wxCommandEvent& event)
{
    std::cout << "Event: Close" << std::endl;
}

void SimpleFrame::OnExit(wxCommandEvent& event)
{
    std::cout << "Event: Exit" << std::endl;
    Close(true);
}

void SimpleFrame::OnNew(wxCommandEvent& event)
{
    std::cout << "Event: New" << std::endl;
}

void SimpleFrame::OnOpen(wxCommandEvent& event)
{
    std::cout << "Event: Open" << std::endl;
}

void SimpleFrame::OnRefresh(wxCommandEvent& event)
{
    std::cout << "Event: Refresh" << std::endl;
}

void SimpleFrame::OnSave(wxCommandEvent& event)
{
    std::cout << "Event: Save" << std::endl;
}

void SimpleFrame::OnSaveAs(wxCommandEvent& event)
{
    std::cout << "Event: SaveAs" << std::endl;
}


void SimpleFrame::OnCopy(wxCommandEvent& event)
{
    std::cout << "Event: Copy" << std::endl;
}

void SimpleFrame::OnFind(wxCommandEvent& event)
{
    std::cout << "Event: Find" << std::endl;
}

void SimpleFrame::OnPaste(wxCommandEvent& event)
{
    std::cout << "Event: Paste" << std::endl;
}

void SimpleFrame::OnRedo(wxCommandEvent& event)
{
    std::cout << "Event: Redo" << std::endl;
}

void SimpleFrame::OnReplace(wxCommandEvent& event)
{
    std::cout << "Event: Replace" << std::endl;
}

void SimpleFrame::OnSelectAll(wxCommandEvent& event)
{
    std::cout << "Event: SelectAll" << std::endl;
}

void SimpleFrame::OnUndo(wxCommandEvent& event)
{
    std::cout << "Event: Undo" << std::endl;
}



void SimpleFrame::OnBottom(wxCommandEvent& event)
{
    std::cout << "Event: Bottom" << std::endl;
}

void SimpleFrame::OnDown(wxCommandEvent& event)
{
    std::cout << "Event: Down" << std::endl;
}

void SimpleFrame::OnFirst(wxCommandEvent& event)
{
    std::cout << "Event: First" << std::endl;
}

void SimpleFrame::OnHome(wxCommandEvent& event)
{
    std::cout << "Event: Home" << std::endl;
}

void SimpleFrame::OnJumpTo(wxCommandEvent& event)
{
    std::cout << "Event: JumpTo" << std::endl;
}

void SimpleFrame::OnLast(wxCommandEvent& event)
{
    std::cout << "Event: Last" << std::endl;
}

void SimpleFrame::OnTop(wxCommandEvent& event)
{
    std::cout << "Event: Top" << std::endl;
}

void SimpleFrame::OnUp(wxCommandEvent& event)
{
    std::cout << "Event: Up" << std::endl;
}



void SimpleFrame::OnAbout(wxCommandEvent& event)
{
    std::cout << "Event: About" << std::endl;
}

void SimpleFrame::OnHelp(wxCommandEvent& event)
{
    std::cout << "Event: Help" << std::endl;
}

void SimpleFrame::OnInfo(wxCommandEvent& event)
{
    std::cout << "Event: Info" << std::endl;
}




