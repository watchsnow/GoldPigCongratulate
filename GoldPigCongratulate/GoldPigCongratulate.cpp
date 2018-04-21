#include "stdafx.h"
#include "GoldPigDlg.h"

class CGolgPigApp : public CWinApp
{
public:
    virtual BOOL InitInstance()
    {
        CGoldPigDlg dlg;
        dlg.DoModal();
        return TRUE;
    }
};

CGolgPigApp theApp;