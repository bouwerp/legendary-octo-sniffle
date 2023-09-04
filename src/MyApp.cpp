#include "MyApp.hpp"

bool MyApp::OnInit()
{
    wxImage::AddHandler(new wxPNGHandler()); /* plus any others needed, e.g. JPG */

    auto frame = new MyFrame();
    frame->Show();

    return true;
}