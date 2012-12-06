#ifndef OTHER_H_H
#define OTHER_H_H
#include "haffnode.h"

//*****************最小堆************************************


template <class T>

class MinHeap

{

private:

   T * nodes;               //用来存放二叉树的每一个节点的数组

   int currentsize;        //当前堆中有的元素个数

   int maxsize;              //堆中允许存放的最大的元素个数

public:

	void makeHeap(int n);           //建堆，创建一个空堆

	MinHeap<T> & insert(T & t);     //向堆中插入一个元素，保持堆得性质不变

	MinHeap<T>&  del(T& t);         //从堆中删除最下的那个元素保持堆的性质不变，同时将这个元素放到t中

MinHeap(){currentsize=0;maxsize=256;nodes=NULL;}//构造函数
~MinHeap(){delete []nodes;}
   

    int getsize(){return currentsize;}
	T & get(int index )
		
	{
		
		return nodes[index] ;
		
	}

};



template <class T> 

void MinHeap<T> ::makeHeap(int maxsize)

{

    nodes = new  T[maxsize+1];  //这边是一个小的技巧，开辟的一个数组的大小比最大元素个数多一个，这样堆中       //元素就是从下标1开始的，不需要进行复杂的判断了

	this->maxsize = maxsize;           

	this->currentsize = 0;

}



/**

向堆中插入一个元素，基本的算法是这样的，首先将这个元素添加到数组的最后，然后沿着树向根方向一直查找直到这个元素应该存放的位置为止

**/

template <class T>

MinHeap<T> & MinHeap<T>::insert(T & t)          

{

	this ->currentsize ++;

	nodes[currentsize] = t;

	int index = this ->currentsize ;

		while(index >1 && nodes[index].weight < nodes[index/2].weight)

		{

			   nodes [ index ] = nodes[index/2];

		  index = index / 2 ;

		}

	nodes [index ] = t;

	return * this;

}



/**

删除的过程和插入的过程类似，只不过是逆过来的，从根向叶方向判断，直到找到了合适的位置。

**/

template <class T>

MinHeap<T> & MinHeap<T>::del(T&t )

{

	t = nodes[1] ;

	T tem = nodes[this->currentsize] ;            //将最后一个元素取出来，然后放到根上

	this ->currentsize --;

	int index = 1;                           //这个是放置tem元素的位置的下标。

	int  sonindex = 2;                            //这个变量是用来存放较小元素的子节点的下标的

	while(sonindex <= this ->currentsize ) 

	{

		if(sonindex < this ->currentsize &&  nodes[sonindex].weight > nodes[sonindex+1].weight) 

			sonindex ++;

		if(tem.weight < nodes[sonindex].weight)

			  break;

			nodes[index] = nodes[sonindex]; 

			index = sonindex;

			sonindex *= 2;

	}

	nodes [index] = tem;

	return * this;

}


//****这是用来统计字符的两个函数************************************

int appear(haffnode s[],char c,int n);
//void faccount(huffmanNode s[], int l,int &n,char str[]);
//void encode(huffmanNode *t,int n,huffmanNode code[]);




void faccount(haffnode s[], int l,int &n,char str[]) 
//n就是出现的字符串的种类 l是总字符数 str[]是初始的字符集合
{
	int j,t;
    for(j=0;j<l;j++)
	{
	
		t=appear(s,str[j],n);
		if(t>=0)
			s[t].weight++;
		else
		{
			s[n].m_ch=str[j];
			s[n].weight++;
			s[n].left=NULL;
			s[n].right=NULL;
			s[n].haveornot=1;
			n++;
		}

	}
}

int appear(haffnode s[],char c,int n)
{
	int i;
	for(i=0;i<=n;i++)
	{
		if(c==s[i].m_ch&&s[i].haveornot==1)
			return i;
	}
	return -1;
}

//获取编码的函数

void encode(haffnode *t,int n,haffnode code[])
{
    if (t->left!=NULL)
    {
         t->left->m_node=t->m_node+'0';
		 encode(t->left,n,code);
    }
	if (t->right!=NULL)
	{
		t->right->m_node=t->m_node+'1';
		encode(t->right,n,code);
	}
	if (t->left==NULL&&t->right==NULL)
	{
        for (int i=0;i<n;i++)
        {
			if (t->m_ch==code[i].m_ch)
			{
				code[i].m_node=t->m_node;
			}
        }

		return;
	}
}

//*******将二进制转换为十进制的函数*******
int Huanshi(int a[],int x,int n);
int Power(int x,int n);
int ertoshi(CString tem)
{
	int n_count_01=0;
	int shi[100];
	for (n_count_01=0;n_count_01<tem.GetLength();n_count_01++)
	{
        if(tem[n_count_01]=='0')
			shi[n_count_01]=0;
		else
			shi[n_count_01]=1;
	}
    return Huanshi(shi,2,tem.GetLength());
}


int Huanshi(int a[],int x,int n)//其他进制转换十进制
{
	int tem=0;
	int i;
	for(i=0;i<n;i++)
		tem=tem+a[i]*Power(x,n-i-1);
	return tem;
	
}

int Power(int x,int n)//乘方函数
{
	int val=1;
	while(n--)
		val*=x;
	return val;
}

/*CString tran(int x,int m)//十进制转换二进制
{
	
	char yuan[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int a[100];
	int i=0;
	if (x==0)
	{
		a[0]=0;
		i=1;
	}
	while(x>0)
	{
		a[i]=x%m;
		x=x/m;
		i++;
	}
	
	CString tem;
	for(i=i-1;i>=0;i--)
	{
		tem+=yuan[a[i]];
	}
	
		return tem;

	
	
}*/

CString tran(int x,int m)//十进制转换二进制
{
	
	char yuan[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int a[100];
	int i=0;
	if (x==0)
	{
		a[0]=0;
		i=1;
	}
	while(x>0)
	{
		a[i]=x%m;
		x=x/m;
		i++;
	}
	
	CString tem;
	for(i=i-1;i>=0;i--)
	{
		tem+=yuan[a[i]];
	}
	if (tem.GetLength()==8)
	{
		return tem;
	}
	
	else
	{
		int n_if7=8-tem.GetLength();
		if (n_if7==1)
		{
			CString str_add0=_T("0");
			str_add0+=tem;
			return str_add0;
		}
		if (n_if7==2)
		{
			CString str_add02=_T("00");
			str_add02+=tem;
			return str_add02;
		}
		if (n_if7==3)
		{
			CString str_add03=_T("000");
			str_add03+=tem;
			return str_add03;
		}
		if (n_if7==4)
		{
			CString str_add04=_T("0000");
			str_add04+=tem;
			return str_add04;
		}
		if (n_if7==5)
		{
			CString str_add05=_T("00000");
			str_add05+=tem;
			return str_add05;
		}
		if (n_if7==6)
		{
			CString str_add06=_T("000000");
			str_add06+=tem;
			return str_add06;
		}
		if (n_if7==7)
		{
			CString str_add06=_T("0000000");
			str_add06+=tem;
			return str_add06;
		}
		
	}
}
	
	



CString tran_1(int x,int m)//十进制转换二进制
{
	
	char yuan[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int a[100];
	int i=0;
	if (x==0)
	{
		a[0]=0;
		i=1;
	}
	while(x>0)
	{
		a[i]=x%m;
		x=x/m;
		i++;
	}
	
	CString tem;
	for(i=i-1;i>=0;i--)
	{
		tem+=yuan[a[i]];
	}
	return tem;	
}

#endif