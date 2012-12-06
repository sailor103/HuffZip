#pragma once

class haffnode
{
public:
	haffnode(void);
    haffnode *left,*right;  //左、右孩子
	char  m_ch;                //叶节点的字符
	int   weight;              //权值
	CString  m_node;           //哈弗曼编码
	int  haveornot;
	~haffnode(void);
};
