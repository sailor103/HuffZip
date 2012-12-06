
// HuffmanZipView.cpp : CHuffmanZipView 类的实现
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHuffmanZipView::OnFilePrintPreview)
	ON_COMMAND(ID_YASUO, &CHuffmanZipView::OnYasuo)
	ON_COMMAND(ID_JIEYA, &CHuffmanZipView::OnJieya)
END_MESSAGE_MAP()

// CHuffmanZipView 构造/析构

CHuffmanZipView::CHuffmanZipView()
{
	// TODO: 在此处添加构造代码

}

CHuffmanZipView::~CHuffmanZipView()
{
}

BOOL CHuffmanZipView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHuffmanZipView 绘制

void CHuffmanZipView::OnDraw(CDC* /*pDC*/)
{
	CHuffmanZipDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CHuffmanZipView 打印


void CHuffmanZipView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CHuffmanZipView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHuffmanZipView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CHuffmanZipView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CHuffmanZipView 诊断

#ifdef _DEBUG
void CHuffmanZipView::AssertValid() const
{
	CView::AssertValid();
}

void CHuffmanZipView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHuffmanZipDoc* CHuffmanZipView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHuffmanZipDoc)));
	return (CHuffmanZipDoc*)m_pDocument;
}
#endif //_DEBUG


// CHuffmanZipView 消息处理程序

void CHuffmanZipView::OnYasuo()
{
	// TODO: 在此添加命令处理程序代码
	CYASUO yDlg;
	yDlg.DoModal();
}

void CHuffmanZipView::OnJieya()
{
	// TODO: 在此添加命令处理程序代码
	CJIEYASUO jDlg;
	jDlg.DoModal();
}
