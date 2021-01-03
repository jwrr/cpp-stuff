#include <wx/wx.h>
#include "SimpleMenuBar.h"

SimpleMenuBar::SimpleMenuBar()
{
  wxMenu* menuDropDown;

  menuDropDown = new wxMenu;
  this->Append(menuDropDown, wxT("&File"));
  {
    menuDropDown->Append(wxID_OPEN,       wxT("&Open"),        wxT("Opens a file"));
    menuDropDown->Append(wxID_REFRESH,    wxT("&Refresh"),     wxT("Re-opens a file"));
    menuDropDown->Append(wxID_NEW,        wxT("&New"),         wxT("Create new file"));
    menuDropDown->AppendSeparator();
    menuDropDown->Append(wxID_SAVE,       wxT("&Save"),        wxT("Save file"));
    menuDropDown->Append(wxID_SAVEAS,     wxT("Save &As"),     wxT("Save As file"));
    menuDropDown->AppendSeparator();
    menuDropDown->Append(wxID_CLOSE,      wxT("&Close"),       wxT("Close file"));
    menuDropDown->Append(wxID_EXIT,       wxT("E&xit"),        wxT("Quits the program"));
  }

  menuDropDown = new wxMenu;
  this->Append(menuDropDown, wxT("&Edit"));
  {
    menuDropDown->Append(wxID_UNDO,       wxT("&Undo"),        wxT("Undo command"));
    menuDropDown->Append(wxID_REDO,       wxT("&Redo"),        wxT("Redo command"));
    menuDropDown->AppendSeparator();
    menuDropDown->Append(wxID_SELECTALL,  wxT("Select &All"),  wxT("Select All"));
    menuDropDown->Append(wxID_COPY,       wxT("&Copy"),        wxT("Copy selection"));
    menuDropDown->Append(wxID_CUT,        wxT("Cu&t"),         wxT("Cut  selection"));
    menuDropDown->Append(wxID_PASTE,      wxT("&Paste"),       wxT("Paste"));
    menuDropDown->AppendSeparator();
    menuDropDown->Append(wxID_FIND,       wxT("&Find"),        wxT("Find"));
    menuDropDown->Append(wxID_REPLACE,    wxT("Rep&lace"),     wxT("Replace"));
  }

  menuDropDown = new wxMenu;
  this->Append(menuDropDown, wxT("&Nav"));
  {
    menuDropDown->Append(wxID_HOME,       wxT("&Home"),        wxT("Help"));
    menuDropDown->Append(wxID_FIRST,      wxT("&First"),       wxT("Goto First"));
    menuDropDown->Append(wxID_LAST,       wxT("&Last"),        wxT("Goto Last"));
    menuDropDown->Append(wxID_JUMP_TO,    wxT("&Jump To"),     wxT("Jump to"));
    menuDropDown->AppendSeparator();
    menuDropDown->Append(wxID_TOP,        wxT("&Top"),         wxT("Goto Top"));
    menuDropDown->Append(wxID_BOTTOM,     wxT("&Bottom"),      wxT("Goto Bottom"));
    menuDropDown->AppendSeparator();
    menuDropDown->Append(wxID_UP,         wxT("&Up"),          wxT("Go Up"));
    menuDropDown->Append(wxID_DOWN,       wxT("&Down"),        wxT("Go Down"));
  }

  menuDropDown = new wxMenu;
  this->Append(menuDropDown, wxT("&Help"));
  {
    menuDropDown->Append(wxID_HELP,       wxT("&Help"),        wxT("Help"));
    menuDropDown->Append(wxID_INFO,       wxT("&Info"),        wxT("Information"));
    menuDropDown->AppendSeparator();
    menuDropDown->Append(wxID_ABOUT,      wxT("&About"),       wxT("Version"));
  }







}

