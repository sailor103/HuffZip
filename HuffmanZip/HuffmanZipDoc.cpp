
// HuffmanZipDoc.cpp : CHuffmanZipDoc ���ʵ��
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


// CHuffmanZipDoc ����/����

CHuffmanZipDoc::CHuffmanZipDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CHuffmanZipDoc::~CHuffmanZipDoc()
{
}

BOOL CHuffmanZipDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CHuffmanZipDoc ���л�

void CHuffmanZipDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CHuffmanZipDoc ���

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


// CHuffmanZipDoc ����
