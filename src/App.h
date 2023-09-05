#ifndef APP_HPP
#define APP_HPP

#include <wx/setup.h>
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MainFrame.h"

class App : public wxApp
{
public:
    bool OnInit() override;
};

#endif