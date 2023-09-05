//
// Created by Pieter Bouwer on 2023/09/05.
//

#ifndef LEGENDARY_OCTO_SNIFFLE_CONSOLE_H
#define LEGENDARY_OCTO_SNIFFLE_CONSOLE_H

#include <wx/wxprec.h>
#include <wx/setup.h>
#include <wx/mstream.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class LogConsole : wxTextAreaBase {
public:
    LogConsole();
};

#endif //LEGENDARY_OCTO_SNIFFLE_CONSOLE_H
