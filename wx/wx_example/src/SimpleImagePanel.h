#ifndef SIMPLEIMAGEPANEL_H_
#define SIMPLEIMAGEPANEL_H_

#include <wx/wx.h>
#include <wx/sizer.h>

class SimpleImagePanel : public wxPanel
{
    wxBitmap image;
    
public:
    SimpleImagePanel(wxFrame* parent, wxString file, wxBitmapType format);
    
    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    
    void render(wxDC& dc);
    
    // some useful events
    /*
     void mouseMoved(wxMouseEvent& event);
     void mouseDown(wxMouseEvent& event);
     void mouseWheelMoved(wxMouseEvent& event);
     void mouseReleased(wxMouseEvent& event);
     void rightClick(wxMouseEvent& event);
     void mouseLeftWindow(wxMouseEvent& event);
     void keyPressed(wxKeyEvent& event);
     void keyReleased(wxKeyEvent& event);
     */
    
    DECLARE_EVENT_TABLE()
};

#endif  // SIMPLEIMAGEPANEL_H_


