#pragma once
#include "stdafx.h"

// CGoldPigDlg �Ի���

class CGoldPigDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CGoldPigDlg)

public:
    CGoldPigDlg(CWnd* pParent = NULL);   // ��׼���캯��
    virtual ~CGoldPigDlg();

// �Ի�������
    enum { IDD = IDD_DIALOG_GOLDPIG };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

    DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    HICON m_hIcon;
    afx_msg void OnNcPaint();
};
