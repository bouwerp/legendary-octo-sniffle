#include "MainFrame.h"
#include "helpers.h"

#include <utility>

using namespace cv;
using namespace std;

enum MenuIDs {
    Open = 1,
    Exit,
};

MainFrame::MainFrame(string frameTitle) : wxFrame(nullptr, wxID_ANY, this->title)
{
    // handle title setting
    this->title = std::move(frameTitle);
    this->SetTitle(this->title);

    // create the 'File' menu with all of its options
    auto fileMenu = new wxMenu;
    fileMenu->Append(MenuIDs::Open, "&Open file...\tCtrl+O", "Open an image file to load");
    fileMenu->AppendSeparator();
    fileMenu->Append(MenuIDs::Exit, "&Exit...\tCtrl+Q", "Exit");
    auto menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "&File");
    this->SetMenuBar(menuBar);

    // controls
    this->thresholdSlider = new wxSlider(
            this, // parent window
            wxID_ANY,
            this->thresholdValue, // initial value
            0,
            255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL, wxDefaultValidator, "Threshold"
    );
    this->thresholdSlider->Enable(false);

    this->controlsSizer = new wxFlexGridSizer( 2, 10, 10 );

    this->controlsSizer->Add(this->thresholdSlider, 0, wxALIGN_LEFT);

    // layout with sizer
   this->mainSizer = new wxFlexGridSizer( 1 );
   this->mainSizer->Add(
           this->controlsSizer,
           0,
           wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL
   );
    this->imageSizer = new wxBoxSizer( wxHORIZONTAL );
    this->mainSizer->Add(this->imageSizer, wxSizerFlags(0).Center());
    this->mainSizer->SetMinSize(1200, 700);

    // create an initially black image as a placeholder
    auto convertOpenCVImageToWXBitmapOutput = convertOpenCVImageToWXBitmap(
            ConvertOpenCVImageToWXBitmapInput{.image = Mat::zeros(Size(700,500),CV_8UC1)});

    // creat the bitmap component where images will be loaded
    this->staticBitmap = new wxStaticBitmap(
            this,
            wxID_ANY,
            convertOpenCVImageToWXBitmapOutput.bitmap,
            wxDefaultPosition,
            wxDefaultSize);

    this->imageSizer->Add(
            this->staticBitmap,
            wxEXPAND,
            wxALL,
            10);

    SetSizerAndFit(this->mainSizer);

    // bind events
    this->Bind(wxEVT_MENU, &MainFrame::onOpenFile, this, MenuIDs::Open);
    this->Bind(wxEVT_MENU, [](wxCommandEvent&) -> void { exit(0); }, MenuIDs::Exit);
    this->Bind(wxEVT_SIZING, [&](wxSizeEvent &event) -> void {
        this->SetTitle(this->title +
                       std::to_string(event.m_size.GetWidth()) + ", " + std::to_string(event.m_size.GetHeight()));
        event.Skip();
    });
    this->Bind(wxEVT_SLIDER, [&](wxCommandEvent &event) -> void {
        this->thresholdValue = event.GetSelection();
        this->updateImage();
    });
}

/**
 * updateImage
 */
void MainFrame::updateImage() {
    cv::Mat image_threshold;
    MainFrame::originalImage.copyTo(image_threshold);
//    cv::cvtColor(image_threshold, image_threshold, cv::COLOR_RGB2GRAY);
//    cv::threshold(image_threshold, image_threshold, this->thresholdValue, 255, cv::THRESH_BINARY);

    // convert the OpenCV image to a wxWidgets image
    auto convertOpenCVImageToWXBitmapOutput =
            convertOpenCVImageToWXBitmap(ConvertOpenCVImageToWXBitmapInput{.image = image_threshold});

    this->staticBitmap->SetBitmap(convertOpenCVImageToWXBitmapOutput.bitmap);

    Fit();

    // display the bitmap
    this->thresholdSlider->Enable(true);
}


void MainFrame::onOpenFile(wxCommandEvent&)
{
    auto fileDialog = new wxFileDialog(
            this,
            "Select image file to open",
            "",
            "",
            "Images *.png|*.PNG",
            wxFD_OPEN|wxFD_FILE_MUST_EXIST
    );

    if (fileDialog->ShowModal() == wxID_CANCEL) return;

    // load the image into open CV
    this->originalImage = cv::imread(fileDialog->GetPath().ToStdString(), cv::IMREAD_UNCHANGED);
    if (this->originalImage.empty()) {
        wxLogError("failed to load image");
        return;
    }

    this->updateImage();
}
