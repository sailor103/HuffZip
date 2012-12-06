
// HuffmanZipDoc.cpp : CHuffmanZipDoc 类的实现
//

#include "stdafx.h"
#include "HuffmanZip.h"

#include "HuffmanZipDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHuffmanZipDoc

IMPLEMENT_DYNCREATE(CHuffmanZipDoc, CDocument)

BEGIN_MESSAGE_MAP(CHuffmanZipDoc, CDocument)
END_MESSAGE_MAP()


// CHuffmanZipDoc 构造/析构

CHuffmanZipDoc::CHuffmanZipDoc()
{
	// TODO: 在此添加一次性构造代码

}

CHuffmanZipDoc::~CHuffmanZipDoc()
{
}

BOOL CHuffmanZipDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CHuffmanZipDoc 序列化

void CHuffmanZipDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CHuffmanZipDoc 诊断

#ifdef _DEBUG
void CHuffmanZipDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHuffmanZipDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHuffmanZipDoc 命令
