#pragma once
#include "afxcmn.h"


// CJIEYASUO �Ի���

class CJIEYASUO : public CDialog
{
	DECLARE_DYNAMIC(CJIEYASUO)

public:
	CJIEYASUO(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CJIEYASUO();

// �Ի�������
	enum { IDD = IDD_DIALOG_J };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_pathname;
	afx_msg void OnBnClickedButtonJSel();
	afx_msg void OnBnClickedButtonJExl();
	CProgressCtrl m_pro_J;
};
