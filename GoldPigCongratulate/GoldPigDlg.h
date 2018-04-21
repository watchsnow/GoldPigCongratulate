#pragma once
#include "stdafx.h"

// CGoldPigDlg 对话框

class CGoldPigDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CGoldPigDlg)

public:
    CGoldPigDlg(CWnd* pParent = NULL);   // 标准构造函数
    virtual ~CGoldPigDlg();

// 对话框数据
    enum { IDD = IDD_DIALOG_GOLDPIG };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

    DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    HICON m_hIcon;
    afx_msg void OnNcPaint();
};
