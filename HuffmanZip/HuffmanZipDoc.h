
// HuffmanZipDoc.h : CHuffmanZipDoc ��Ľӿ�
//


#pragma once


class CHuffmanZipDoc : public CDocument
{
protected: // �������л�����
	CHuffmanZipDoc();
	DECLARE_DYNCREATE(CHuffmanZipDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CHuffmanZipDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


