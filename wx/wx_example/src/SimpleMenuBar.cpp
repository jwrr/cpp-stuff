#include "SimpleFrame.h"
#include "SimpleMenuBar.h"

using namespace std;

#define addItem(handler, id, name, help) \
  menuDropDown->Append(id, wxT(name), wxT(help)); \
  frame->Connect(id, wxEVT_COMMAND_TOOL_CLICKED,  wxCommandEventHandler(handler));

//SimpleMenuBar.cpp:11:57: error: no matching function for call to ‘wxFrame::Connect(int&, const wxEventTypeTag<wxCommandEvent>&, std::function<void()>&)’


void SimpleMenuBar::Create(wxFrame* frame)
{
  wxMenuBar* menuBar = new wxMenuBar;
  wxMenu* menuDropDown;
  
  int ii = 9999;
  
  
  frame->Connect(ii, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(SimpleFrame::OnNew));

  menuDropDown = new wxMenu;
  menuBar->Append(menuDropDown, wxT("&File"));
  addItem(SimpleFrame::OnOpen,    wxID_OPEN,    "&Open",    "Open file")
  addItem(SimpleFrame::OnRefresh, wxID_REFRESH, "&Refresh", "Refresh file")
  addItem(SimpleFrame::OnNew,     wxID_NEW,     "&New",     "Create new file")
  menuDropDown->AppendSeparator();
  addItem(SimpleFrame::OnSave,    wxID_SAVE,    "&Save",    "Save file")
  addItem(SimpleFrame::OnSaveAs,  wxID_SAVEAS,  "Save As",  "Save As")
  menuDropDown->AppendSeparator();
  addItem(SimpleFrame::OnClose,   wxID_CLOSE,   "&Close",   "Close file")
  addItem(SimpleFrame::OnExit,    wxID_EXIT,    "&Exit",    "Exit Program")
  
  
  menuDropDown = new wxMenu;
  menuBar->Append(menuDropDown,     wxT("&Edit"));
  addItem(SimpleFrame::OnUndo,      wxID_UNDO,      "&Undo",       "Undo Command")
  addItem(SimpleFrame::OnRedo,      wxID_REDO,      "&Redo",       "Redo Command")
  menuDropDown->AppendSeparator();
  addItem(SimpleFrame::OnSelectAll, wxID_SELECTALL, "&Select All", "SelectAll Command")
  addItem(SimpleFrame::OnCopy,      wxID_COPY,      "&Copy",       "Copy Command")
  addItem(SimpleFrame::OnPaste,     wxID_PASTE,     "&Paste",      "PasteCommand")
  menuDropDown->AppendSeparator();
  addItem(SimpleFrame::OnFind,      wxID_FIND,      "&Find",       "Find Command")
  addItem(SimpleFrame::OnReplace,   wxID_REPLACE,   "&Replace",    "Replace Command")
  
  

  menuDropDown = new wxMenu;
  menuBar->Append(menuDropDown, wxT("&Nav"));
  addItem(SimpleFrame::OnHome,    wxID_HOME,    "&Home",    "Home Command")
  addItem(SimpleFrame::OnFirst,   wxID_FIRST,   "&First",   "First Command")
  addItem(SimpleFrame::OnLast,    wxID_LAST,    "&Last",    "Last Command")
  addItem(SimpleFrame::OnJumpTo,  wxID_JUMP_TO, "&Jump To", "Jump To Command")
  addItem(SimpleFrame::OnTop,     wxID_TOP,     "&Top",     "Top Command")
  addItem(SimpleFrame::OnBottom,  wxID_BOTTOM,  "&Bottom",  "Bottom Command")
  addItem(SimpleFrame::OnUp,      wxID_UP,      "&Up",      "Up Command")
  addItem(SimpleFrame::OnDown,    wxID_DOWN,    "&Down",    "Down Command")


  menuDropDown = new wxMenu;
  menuBar->Append(menuDropDown,   wxT("&Help"));
  addItem(SimpleFrame::OnHelp,    wxID_HELP,    "&Help",    "Help Command")
  addItem(SimpleFrame::OnInfo,    wxID_INFO,    "&Info",    "Info Command")
  menuDropDown->AppendSeparator();
  addItem(SimpleFrame::OnAbout,   wxID_ABOUT,   "&About",   "About Command")


  frame->SetMenuBar(menuBar);

}

