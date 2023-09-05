#include "App.h"

bool App::OnInit()
{
    // add image handlers
    wxImage::AddHandler(new wxPNGHandler());

    auto frame = new MainFrame("Legendary Octo Sniffle");
    frame->Show();

    return true;
}