#pragma once
#include "afxcmn.h"


// CYASUO �Ի���

class CYASUO : public CDialog
{
	DECLARE_DYNAMIC(CYASUO)

public:
	CYASUO(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CYASUO();

// �Ի�������
	enum { IDD = IDD_DIALOG_Y };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_YASUO_INPUT;
	afx_msg void OnBnClickedButtonYSel();
	afx_msg void OnBnClickedButtonYExl();
	CProgressCtrl m_pro_Y;
};
