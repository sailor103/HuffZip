#pragma once
#include "afxcmn.h"


// CJIEYASUO 对话框

class CJIEYASUO : public CDialog
{
	DECLARE_DYNAMIC(CJIEYASUO)

public:
	CJIEYASUO(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CJIEYASUO();

// 对话框数据
	enum { IDD = IDD_DIALOG_J };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_pathname;
	afx_msg void OnBnClickedButtonJSel();
	afx_msg void OnBnClickedButtonJExl();
	CProgressCtrl m_pro_J;
};
