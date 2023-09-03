#include <wx/setup.h>
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MyFrame.hpp"

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};
