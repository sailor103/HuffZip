#pragma once

class haffnode
{
public:
	haffnode(void);
    haffnode *left,*right;  //���Һ���
	char  m_ch;                //Ҷ�ڵ���ַ�
	int   weight;              //Ȩֵ
	CString  m_node;           //����������
	int  haveornot;
	~haffnode(void);
};
