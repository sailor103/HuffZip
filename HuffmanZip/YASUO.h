#pragma once
#include "afxcmn.h"


// CYASUO 对话框

class CYASUO : public CDialog
{
	DECLARE_DYNAMIC(CYASUO)

public:
	CYASUO(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CYASUO();

// 对话框数据
	enum { IDD = IDD_DIALOG_Y };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_YASUO_INPUT;
	afx_msg void OnBnClickedButtonYSel();
	afx_msg void OnBnClickedButtonYExl();
	CProgressCtrl m_pro_Y;
};
