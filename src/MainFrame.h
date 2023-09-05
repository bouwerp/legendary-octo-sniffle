#ifndef MY_FRAME_HPP
#define MY_FRAME_HPP

#include <opencv2/opencv.hpp>

#include <wx/wxprec.h>
#include <wx/setup.h>
#include <wx/mstream.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

using namespace cv;
using namespace std;

class MainFrame : public wxFrame
{
public:
    explicit MainFrame(string);

private:
    // data
    string title;
    cv::Mat originalImage;
    int thresholdValue = 100;

    // components
    wxFlexGridSizer *mainSizer;
    wxFlexGridSizer *controlsSizer;
    wxBoxSizer *imageSizer;
    wxBoxSizer *consoleSizer;

    wxSlider *thresholdSlider;
    wxStaticBitmap *staticBitmap;

    // methods
    void onOpenFile(wxCommandEvent &event);
    void updateImage();
};

#endif
