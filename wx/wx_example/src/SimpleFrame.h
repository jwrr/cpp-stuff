#ifndef SIMPLEFRAME_H_
#define SIMPLEFRAME_H_

#include <wx/wx.h>

class SimpleFrame : public wxFrame
{
public:
    SimpleFrame(const wxString& title, int width, int height);

    void OnQuit(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnReload(wxCommandEvent& event);
};

#endif // SIMPLEFRAME_H_

