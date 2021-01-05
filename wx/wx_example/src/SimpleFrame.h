#ifndef SIMPLEFRAME_H_
#define SIMPLEFRAME_H_

#include <wx/wx.h>

class SimpleFrame : public wxFrame
{
public:
    SimpleFrame(const wxString& title, int width, int height);

    void OnClose(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnNew(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnRefresh(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnSaveAs(wxCommandEvent& event);

    void OnCopy(wxCommandEvent& event);
    void OnFind(wxCommandEvent& event);
    void OnPaste(wxCommandEvent& event);
    void OnRedo(wxCommandEvent& event);
    void OnReplace(wxCommandEvent& event);
    void OnSelectAll(wxCommandEvent& event);
    void OnUndo(wxCommandEvent& event);

    void OnBottom(wxCommandEvent& event); 
    void OnDown(wxCommandEvent& event);   
    void OnFirst(wxCommandEvent& event);  
    void OnHome(wxCommandEvent& event);   
    void OnJumpTo(wxCommandEvent& event); 
    void OnLast(wxCommandEvent& event);   
    void OnTop(wxCommandEvent& event);    
    void OnUp(wxCommandEvent& event);     

    void OnHelp(wxCommandEvent& event);   
    void OnInfo(wxCommandEvent& event);   
    void OnAbout(wxCommandEvent& event);   

};

#endif // SIMPLEFRAME_H_

