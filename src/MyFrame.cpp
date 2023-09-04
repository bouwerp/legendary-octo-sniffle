#include "MyFrame.hpp"

using namespace cv;

enum MenuIDs {
    Open = 1,
    Exit,
};

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "Hello All!!")
{
    // create the menu
    auto fileMenu = new wxMenu;

    fileMenu->Append(MenuIDs::Open, "&Open file...\tCtrl+O", "Open an image file to load");
    fileMenu->AppendSeparator();
    fileMenu->Append(MenuIDs::Exit, "&Exit...\tCtrl+Q", "Exit");

    auto menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "&File");

    wxFrame::SetMenuBar(menuBar);

    wxFrame::Bind(wxEVT_MENU, &MyFrame::OnOpenFile, this, MenuIDs::Open);
    wxFrame::Bind(wxEVT_MENU, [](wxCommandEvent&) -> void { exit(0); }, MenuIDs::Exit);
}

void MyFrame::OnOpenFile(wxCommandEvent &event)
{
    auto fileDialog = new wxFileDialog(
            this,
            "Select image file to open",
            "",
            "",
            "Images *.png|*.PNG|*.jpg|*.JPG|*.jpeg|*.JPEG",
            wxFD_OPEN|wxFD_FILE_MUST_EXIST
    );

    if (fileDialog->ShowModal() == wxID_CANCEL) return;

    // load the image into open  CV
    cv::Mat image = cv::imread(fileDialog->GetPath().ToStdString(), cv::IMREAD_UNCHANGED);
    if (image.empty()) {
        wxLogError("failed to load image");
        return;
    }

    // convert the OpenCV image to a wxWidgets image
    cv::Size s = image.size();
    cv::cvtColor(image, image, cv::COLOR_RGB2BGR);
    auto im = wxImage(s.width, s.height, image.data, TRUE);

    // display the bitmap
    auto staticBitmap = new wxStaticBitmap(this, wxID_ANY, wxBitmap(im, -1), wxDefaultPosition, wxDefaultSize);
    staticBitmap->Show();
}
