#pragma once
#include <afxdialogex.h>
class cmfcFindDlg :
    public CDialogEx
{
public:
    CString mStr = L"";
    DECLARE_MESSAGE_MAP()
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    virtual BOOL OnInitDialog();
};

