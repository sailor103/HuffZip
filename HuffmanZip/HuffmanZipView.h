
// HuffmanZipView.h : CHuffmanZipView ��Ľӿ�
//


#pragma once


class CHuffmanZipView : public CView
{
protected: // �������л�����
	CHuffmanZipView();
	DECLARE_DYNCREATE(CHuffmanZipView)

// ����
public:
	CHuffmanZipDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CHuffmanZipView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnYasuo();
	afx_msg void OnJieya();
};

#ifndef _DEBUG  // HuffmanZipView.cpp �еĵ��԰汾
inline CHuffmanZipDoc* CHuffmanZipView::GetDocument() const
   { return reinterpret_cast<CHuffmanZipDoc*>(m_pDocument); }
#endif

