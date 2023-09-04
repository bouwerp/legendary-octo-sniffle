#include <wx/wxprec.h>
#include <wx/setup.h>
#include <wx/mstream.h>

#include <opencv2/opencv.hpp>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyFrame : public wxFrame
{
public:
    char *imageData;
    MyFrame();

private:
    void OnOpenFile(wxCommandEvent &event);
};
