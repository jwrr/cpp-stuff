#ifndef SIMPLEMENUBAR_H_
#define SIMPLEMENUBAR_H_

#include <string>
#include <functional>
#include <wx/wx.h>

namespace SimpleMenuBar
{
    void Create(wxFrame* frame);
    void addItem(wxFrame* frame, wxMenu* menuDropDown, int id, std::string name,  std::function<void()> handler, std::string help="");
};

#endif // SIMPLEMENUBAR_H_

