#ifndef SIMPLETOOLBARFRAME_H_
#include <wx/wx.h>

class SimpleToolBarFrame : public wxFrame
{
public:
    SimpleToolBarFrame(const wxString& title, int width, int height);

    void OnQuit(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnReload(wxCommandEvent& event);
};

#endif // SIMPLETOOLBARFRAME_H_

