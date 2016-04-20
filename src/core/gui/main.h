/***************************************************************
 * Name:      _23Main.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2016-04-19
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef _23MAIN_H
#define _23MAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "app.h"


#include <wx/button.h>
#include <wx/statline.h>
class _23Dialog: public wxDialog
{
    public:
        _23Dialog(wxDialog *dlg, const wxString& title);
        ~_23Dialog();

    protected:
        enum
        {
            idBtnQuit = 1000,
            idBtnAbout
        };
        wxStaticText* m_staticText1;
        wxButton* BtnAbout;
        wxStaticLine* m_staticline1;
        wxButton* BtnQuit;

    private:
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};

#endif // _23MAIN_H
