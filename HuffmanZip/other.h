#ifndef OTHER_H_H
#define OTHER_H_H
#include "haffnode.h"

//*****************��С��************************************


template <class T>

class MinHeap

{

private:

   T * nodes;               //������Ŷ�������ÿһ���ڵ������

   int currentsize;        //��ǰ�����е�Ԫ�ظ���

   int maxsize;              //���������ŵ�����Ԫ�ظ���

public:

	void makeHeap(int n);           //���ѣ�����һ���ն�

	MinHeap<T> & insert(T & t);     //����в���һ��Ԫ�أ����ֶѵ����ʲ���

	MinHeap<T>&  del(T& t);         //�Ӷ���ɾ�����µ��Ǹ�Ԫ�ر��ֶѵ����ʲ��䣬ͬʱ�����Ԫ�طŵ�t��

MinHeap(){currentsize=0;maxsize=256;nodes=NULL;}//���캯��
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

    nodes = new  T[maxsize+1];  //�����һ��С�ļ��ɣ����ٵ�һ������Ĵ�С�����Ԫ�ظ�����һ������������       //Ԫ�ؾ��Ǵ��±�1��ʼ�ģ�����Ҫ���и��ӵ��ж���

	this->maxsize = maxsize;           

	this->currentsize = 0;

}



/**

����в���һ��Ԫ�أ��������㷨�������ģ����Ƚ����Ԫ����ӵ���������Ȼ���������������һֱ����ֱ�����Ԫ��Ӧ�ô�ŵ�λ��Ϊֹ

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

ɾ���Ĺ��̺Ͳ���Ĺ������ƣ�ֻ������������ģ��Ӹ���Ҷ�����жϣ�ֱ���ҵ��˺��ʵ�λ�á�

**/

template <class T>

MinHeap<T> & MinHeap<T>::del(T&t )

{

	t = nodes[1] ;

	T tem = nodes[this->currentsize] ;            //�����һ��Ԫ��ȡ������Ȼ��ŵ�����

	this ->currentsize --;

	int index = 1;                           //����Ƿ���temԪ�ص�λ�õ��±ꡣ

	int  sonindex = 2;                            //���������������Ž�СԪ�ص��ӽڵ���±��

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


//****��������ͳ���ַ�����������************************************

int appear(haffnode s[],char c,int n);
//void faccount(huffmanNode s[], int l,int &n,char str[]);
//void encode(huffmanNode *t,int n,huffmanNode code[]);




void faccount(haffnode s[], int l,int &n,char str[]) 
//n���ǳ��ֵ��ַ��������� l�����ַ��� str[]�ǳ�ʼ���ַ�����
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

//��ȡ����ĺ���

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

//*******��������ת��Ϊʮ���Ƶĺ���*******
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


int Huanshi(int a[],int x,int n)//��������ת��ʮ����
{
	int tem=0;
	int i;
	for(i=0;i<n;i++)
		tem=tem+a[i]*Power(x,n-i-1);
	return tem;
	
}

int Power(int x,int n)//�˷�����
{
	int val=1;
	while(n--)
		val*=x;
	return val;
}

/*CString tran(int x,int m)//ʮ����ת��������
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

CString tran(int x,int m)//ʮ����ת��������
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
	
	



CString tran_1(int x,int m)//ʮ����ת��������
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