// YASUO.cpp : ʵ���ļ�
//


#include "stdafx.h"
#include "HuffmanZip.h"
#include "YASUO.h"

#include "other.h"

#define CRTDBG_MAP_ALLOC   
#include <stdlib.h>   
#include <crtdbg.h>   

// CYASUO �Ի���

IMPLEMENT_DYNAMIC(CYASUO, CDialog)

CYASUO::CYASUO(CWnd* pParent /*=NULL*/)
	: CDialog(CYASUO::IDD, pParent)
	, m_YASUO_INPUT(_T(""))
{

}

CYASUO::~CYASUO()
{
}

void CYASUO::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PATHNAME_Y, m_YASUO_INPUT);
	DDX_Control(pDX, IDC_PROGRESS_Y, m_pro_Y);
}


BEGIN_MESSAGE_MAP(CYASUO, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_Y_SEL, &CYASUO::OnBnClickedButtonYSel)
	ON_BN_CLICKED(IDC_BUTTON_Y_EXL, &CYASUO::OnBnClickedButtonYExl)
END_MESSAGE_MAP()


// CYASUO ��Ϣ�������

CString pathname=_T(" ");
CString pathname_save;
void CYASUO::OnBnClickedButtonYSel()
{
	

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog fileDialog(TRUE,_T("Text File(*.txt)|*.txt|Doc File(*.doc)|*.doc"),
		NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T( "Text File(*.txt)|*.txt|Doc File(*.doc)|*.doc||"));

//��������˴��ļ��ĶԻ���
	if(fileDialog.DoModal()==IDOK)
	{
	    
		pathname=fileDialog.GetPathName();//�õ�·��
		this->m_YASUO_INPUT=pathname;
		this->UpdateData(FALSE);
		pathname_save=pathname+_T(".Haf");
        
	}
}



void CYASUO::OnBnClickedButtonYExl()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
 
    _CrtDumpMemoryLeaks();   
    _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	 CFile myFile;//���ļ�
    if(pathname!=' ')
		{
			if(!myFile.Open(pathname,CFile::modeRead,NULL))
				{			
					AfxMessageBox(_T("�ļ��򿪴���"),MB_ICONEXCLAMATION);
				
				}
		
			   
			     m_pro_Y.SetRange(0,600);
				 m_pro_Y.SetPos(0);
				 m_pro_Y.SetStep(100);
			//******�����ȡ�ļ�************

			   SetDlgItemText(IDC_STATIC_Y,_T("���ڶ�ȡ�ļ�..."));

				
				//���ǽ��ļ��е����ݶ���һ���ַ���
				unsigned long  n_file;
				n_file=myFile.GetLength();
				char *t_file;
				t_file=new char[n_file+1];
				myFile.Read(t_file,n_file);
				t_file[n_file]='\0';  
				myFile.Close(); //�ر��ļ�

				m_pro_Y.StepIt();

			//******���濪ʼ���ַ������д���*****

				SetDlgItemText(IDC_STATIC_Y,_T("��ʼ���������ڵ���Ϣ..."));
				
				haffnode t_node[256];
				int t_n=0;
				faccount(t_node,n_file,t_n,t_file);//��ʼ��huffman����
               
			    m_pro_Y.StepIt();
				
			//******���ڵ����weightֵ������С��****

				SetDlgItemText(IDC_STATIC_Y,_T("����weight������С��..."));
				
				MinHeap<haffnode>t;
				t.makeHeap(t_n);
				
				for (int n_counter=0;n_counter<t_n;n_counter++)//��huffman����ѹ����С��
				{
					t.insert(t_node[n_counter]);
				}
                
				m_pro_Y.StepIt();

			//******������������******************

                SetDlgItemText(IDC_STATIC_Y,_T("������������..."));

                haffnode root;
				
			
				while(t.getsize()>1)
				{
					
					haffnode  a,b,huff;
					haffnode *t_a,*t_b;
					t_a=new haffnode;
					t_b=new haffnode;

					t.del(a);
					t_a->left=a.left;
					t_a->right=a.right;
					t_a->weight=a.weight;
					t_a->m_ch=a.m_ch;
					huff.left=t_a;

					t.del(b);
					t_b->left=b.left;
					t_b->right=b.right;
					t_b->weight=b.weight;
					t_b->m_ch=b.m_ch;
					huff.right=t_b;
                    

					huff.weight=t_a->weight+t_b->weight;
                    t.insert(huff);
				
				}
                t.del(root);

				m_pro_Y.StepIt();


         //***********��û���������***********************

                SetDlgItemText(IDC_STATIC_Y,_T("��ȡ����������..."));
				
               
				encode(&root,t_n,t_node);
				
				m_pro_Y.StepIt();

		
           
         //***********������д���ļ�***********************

                SetDlgItemText(IDC_STATIC_Y,_T("��ʼд���ļ�..."));

                SetDlgItemText(IDC_STATIC_Y,_T("д��ÿ���ַ��Լ�����Ȩֵ..."));

			 

			  myFile.Open(pathname_save,CFile::modeCreate|CFile::modeWrite,NULL);//��д��ÿ���ַ��Լ�����Ȩֵ����ѹ��
			  CString t_str;
			  CString b;
			  int filelength=0;
			  int i;
			  int x1,iCount1;
			  char *t_write;
			  for ( i=0;i<t_n;i++)
			  {
				 
                 // myFile.Write(&t_node[i].m_ch,sizeof(char));
				  filelength++;
				  b.Format(_T("%d"),t_node[i].weight);
				 // myFile.Write(b,b.GetLength());
				  filelength+=b.GetLength();
				  if (i!=t_n-1)
				  {
					  char temp_char=' ';
					//  myFile.Write(&temp_char,sizeof(char));
					  filelength++;
				  }
	  
			  }

			  b.Format(_T("%d"),filelength);
			  b+=' ';
			 // myFile.Write(b,b.GetLength());
			  x1=b.GetLength();
			  t_write=new char[x1];
			  for(iCount1=0;iCount1<x1;iCount1++)
			  {
			      t_write[iCount1]=b[iCount1];
			  }
			  myFile.Write(t_write,x1);
			  delete t_write;

			  for ( i=0;i<t_n;i++)
			  {
				  
				  myFile.Write(&t_node[i].m_ch,sizeof(char));
				  
				  b.Format(_T("%d"),t_node[i].weight);
				  x1=b.GetLength();
				  t_write=new char[x1];
				  for(iCount1=0;iCount1<x1;iCount1++)
				  {
					  t_write[iCount1]=b[iCount1];
				  }
				  myFile.Write(t_write,x1);

			      delete t_write;

				 
				 // myFile.Write(b,b.GetLength());
				  
				  if (i!=t_n-1)
				  {
					  char temp_char=' ';
					  myFile.Write(&temp_char,sizeof(char));
					  
				  }
				  
			  }

		
			
			 

              //*****д�����������***

             


			  CString t_01;
			                                     
              for (int j=0;j<n_file;j++)
              {
				  for (int k=0;k<t_n+1;k++)
				  {
					  if (t_node[k].m_ch==t_file[j]&&t_node[k].haveornot==1)
					  {
						   t_01+=t_node[k].m_node;
					  }
				  }
              }
               

         /*   CString content_str;
			  int n_last;
			  unsigned char t_char;
			  for (int t_content=0;t_content<t_01.GetLength();t_content++)
              {
				  if (content_str.GetLength()==8)
				  {
					  
					  
						  t_content--;
						  t_char=ertoshi(content_str);
						  //content_str.Format("%c",t_char);
						  //myFile.Write(content_str,content_str.GetLength());
						  myFile.Write(&t_char,sizeof(unsigned char));
						  
						  content_str.Empty();

						  
					       //content_str='0';
					       continue;
				  }
				  content_str+=t_01[t_content];
              }
              
			  if (content_str.GetLength()!=0)
			  {
                  n_last=content_str.GetLength();

				  unsigned char t_char=ertoshi(content_str);
				  
				  myFile.Write(&t_char,sizeof(unsigned char));
				  
			  }

			  
			  CString str_last;
			  str_last.Format(_T("%d"),n_last);
			  myFile.SeekToEnd();
			  myFile.Write(str_last,str_last.GetLength());
		      myFile.Close();*/

			  //����λ�ķ�ʽʵ��ѹ��


			  SetDlgItemText(IDC_STATIC_Y,_T("��λ�ķ�ʽʵ��ѹ��..."));
			  
			  unsigned char t_move=0;
		

			  for (int iCount_2=0;iCount_2<t_01.GetLength();iCount_2++)
			  {
				  
				  if(t_01[iCount_2]=='0')
				  {
				      t_move=t_move<<1;
				  }
				  else 
				  {
				      t_move=t_move<<1;
					  t_move=t_move+1;
				  }

				  if((iCount_2+1)%8==0)
				  {
					  myFile.Write(&t_move,sizeof(unsigned char));
					  t_move=0;
				  }

				  if(iCount_2==t_01.GetLength()-1&&(iCount_2+1)%8!=0)
				  {
					  myFile.Write(&t_move,sizeof(unsigned char));

					//  char   temp_char1=' ';
					//  myFile.Write(&temp_char1,sizeof(char));

					  int t_last=t_01.GetLength()%8;
				      
					  b.Format(_T("%d"),t_last);
					  x1=b.GetLength();
					  t_write=new char[x1];
					  for(iCount1=0;iCount1<x1;iCount1++)
					  {
						  t_write[iCount1]=b[iCount1];
					  }
					  myFile.Write(t_write,x1);
					  delete t_write;


				  }

			  }


			  myFile.Close();
              
			  m_pro_Y.StepIt();
			  

              SetDlgItemText(IDC_STATIC_Y,_T("ѹ���ɹ�..."));

			  
		
			 AfxMessageBox(_T("ѹ���ɹ�"),MB_ICONINFORMATION);
		   	  OnOK();//�رմ���
			  delete []t_file;


			
			  

		}

		if (pathname==' ')
		{
			AfxMessageBox(_T("����ѡ���ļ�"),MB_ICONEXCLAMATION);
			OnOK();
		}


}
