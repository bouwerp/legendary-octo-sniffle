#include <wx/wxprec.h>
#include <wx/setup.h>

#include <opencv2/opencv.hpp>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyFrame : public wxFrame
{
public:
    MyFrame();

private:
    void OnHello(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
};
