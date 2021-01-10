#include "SimpleImagePanel.h"



BEGIN_EVENT_TABLE(SimpleImagePanel, wxPanel)
// some useful events
/*
 EVT_MOTION(SimpleImagePanel::mouseMoved)
 EVT_LEFT_DOWN(SimpleImagePanel::mouseDown)
 EVT_LEFT_UP(SimpleImagePanel::mouseReleased)
 EVT_RIGHT_DOWN(SimpleImagePanel::rightClick)
 EVT_LEAVE_WINDOW(SimpleImagePanel::mouseLeftWindow)
 EVT_KEY_DOWN(SimpleImagePanel::keyPressed)
 EVT_KEY_UP(SimpleImagePanel::keyReleased)
 EVT_MOUSEWHEEL(SimpleImagePanel::mouseWheelMoved)
 */

// catch paint events
EVT_PAINT(SimpleImagePanel::paintEvent)

END_EVENT_TABLE()


// some useful events
/*
 void SimpleImagePanel::mouseMoved(wxMouseEvent& event) {}
 void SimpleImagePanel::mouseDown(wxMouseEvent& event) {}
 void SimpleImagePanel::mouseWheelMoved(wxMouseEvent& event) {}
 void SimpleImagePanel::mouseReleased(wxMouseEvent& event) {}
 void SimpleImagePanel::rightClick(wxMouseEvent& event) {}
 void SimpleImagePanel::mouseLeftWindow(wxMouseEvent& event) {}
 void SimpleImagePanel::keyPressed(wxKeyEvent& event) {}
 void SimpleImagePanel::keyReleased(wxKeyEvent& event) {}
 */
 


SimpleImagePanel::SimpleImagePanel(wxFrame* parent, wxString file, wxBitmapType format) :
wxPanel(parent)
{
    // load the file... ideally add a check to see if loading was successful
    image.LoadFile(file, format);
}

/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */

void SimpleImagePanel::paintEvent(wxPaintEvent & evt)
{
    // depending on your system you may need to look at double-buffered dcs
    wxPaintDC dc(this);
    render(dc);
}

/*
 * Alternatively, you can use a clientDC to paint on the panel
 * at any time. Using this generally does not free you from
 * catching paint events, since it is possible that e.g. the window
 * manager throws away your drawing when the window comes to the
 * background, and expects you will redraw it when the window comes
 * back (by sending a paint event).
 */
void SimpleImagePanel::paintNow()
{
    // depending on your system you may need to look at double-buffered dcs
    wxClientDC dc(this);
    dc.DrawBitmap( image, 0, 0, false );
}

void SimpleImagePanel::render(wxDC&  dc)
{
    dc.DrawBitmap( image, 0, 0, false );
}


