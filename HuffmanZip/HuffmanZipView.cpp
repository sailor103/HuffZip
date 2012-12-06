
// HuffmanZipView.cpp : CHuffmanZipView ���ʵ��
//

#include "stdafx.h"
#include "HuffmanZip.h"

#include "HuffmanZipDoc.h"
#include "HuffmanZipView.h"

#include "YASUO.h"
#include "JIEYASUO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHuffmanZipView

IMPLEMENT_DYNCREATE(CHuffmanZipView, CView)

BEGIN_MESSAGE_MAP(CHuffmanZipView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHuffmanZipView::OnFilePrintPreview)
	ON_COMMAND(ID_YASUO, &CHuffmanZipView::OnYasuo)
	ON_COMMAND(ID_JIEYA, &CHuffmanZipView::OnJieya)
END_MESSAGE_MAP()

// CHuffmanZipView ����/����

CHuffmanZipView::CHuffmanZipView()
{
	// TODO: �ڴ˴���ӹ������

}

CHuffmanZipView::~CHuffmanZipView()
{
}

BOOL CHuffmanZipView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CHuffmanZipView ����

void CHuffmanZipView::OnDraw(CDC* /*pDC*/)
{
	CHuffmanZipDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CHuffmanZipView ��ӡ


void CHuffmanZipView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CHuffmanZipView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CHuffmanZipView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CHuffmanZipView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CHuffmanZipView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHuffmanZipView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CHuffmanZipView ���

#ifdef _DEBUG
void CHuffmanZipView::AssertValid() const
{
	CView::AssertValid();
}

void CHuffmanZipView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHuffmanZipDoc* CHuffmanZipView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHuffmanZipDoc)));
	return (CHuffmanZipDoc*)m_pDocument;
}
#endif //_DEBUG


// CHuffmanZipView ��Ϣ�������

void CHuffmanZipView::OnYasuo()
{
	// TODO: �ڴ���������������
	CYASUO yDlg;
	yDlg.DoModal();
}

void CHuffmanZipView::OnJieya()
{
	// TODO: �ڴ���������������
	CJIEYASUO jDlg;
	jDlg.DoModal();
}
