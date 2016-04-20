/***************************************************************
 * Name:      _23App.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2016-04-19
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "app.h"
#include "main.h"

IMPLEMENT_APP(_23App);

bool _23App::OnInit()
{
    
    _23Dialog* dlg = new _23Dialog(0L, _("wxWidgets Application Template"));
    
    dlg->Show();
    return true;
}
