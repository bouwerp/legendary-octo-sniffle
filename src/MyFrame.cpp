#include "MyFrame.hpp"

using namespace cv;

enum MenuIDs {
    Hello = 1,
    Close,
};

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "Hello All!!")
{
    // create the menu
    auto fileMenu = new wxMenu;

    fileMenu->Append(MenuIDs::Hello, "&Hello o...\tCtrl+H", "Say hello");
    fileMenu->AppendSeparator();
    fileMenu->Append(wxID_EXIT, "Exit");

    auto menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "&File");

    wxFrame::SetMenuBar(menuBar);

    wxFrame::Bind(wxEVT_MENU, &MyFrame::OnHello, this, MenuIDs::Hello);
    wxFrame::Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnHello(wxCommandEvent &event)
{
    wxLogMessage("Hello!!!");
}
void MyFrame::OnExit(wxCommandEvent &event)
{
}
void MyFrame::OnAbout(wxCommandEvent &event)
{
}
