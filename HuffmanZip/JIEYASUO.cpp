// JIEYASUO.cpp : 实现文件
//

#include "stdafx.h"
#include "HuffmanZip.h"
#include "JIEYASUO.h"

#include "other.h"

// CJIEYASUO 对话框

IMPLEMENT_DYNAMIC(CJIEYASUO, CDialog)

CJIEYASUO::CJIEYASUO(CWnd* pParent /*=NULL*/)
	: CDialog(CJIEYASUO::IDD, pParent)
	, m_pathname(_T(""))
{

}

CJIEYASUO::~CJIEYASUO()
{
}

void CJIEYASUO::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_J, m_pathname);
	DDX_Control(pDX, IDC_PROGRESS_J, m_pro_J);
}


BEGIN_MESSAGE_MAP(CJIEYASUO, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_J_Sel, &CJIEYASUO::OnBnClickedButtonJSel)
	ON_BN_CLICKED(IDC_BUTTON_J_Exl, &CJIEYASUO::OnBnClickedButtonJExl)
END_MESSAGE_MAP()


// CJIEYASUO 消息处理程序

CString pathname_j=_T(" ");
CString pathname_j_save;

void CJIEYASUO::OnBnClickedButtonJSel()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog fileDialog(TRUE,_T("Haf File(*.Haf)|*.Haf"),
		NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T( "Haf File(*.Haf)|*.Haf||"));

//下面调用了打开文件的对话框
	if(fileDialog.DoModal()==IDOK)
	{
	    
		pathname_j=fileDialog.GetPathName();//得到路径
		this->m_pathname=pathname_j;
		this->UpdateData(FALSE);
        
	}


}

void CJIEYASUO::OnBnClickedButtonJExl()
{
	// TODO: 在此添加控件通知处理程序代码
    CFileDialog fileDialog(FALSE,_T("Text File(*.txt)|*.txt|Doc File(*.doc)|*.doc"),
		NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("Text File(*.txt)|*.txt|Doc File(*.doc)|*.doc||"));
	
	
	
	if(fileDialog.DoModal()==IDOK)
	{
		
		pathname_j_save=fileDialog.GetPathName();//得到路径
		
        
	}

	    CFile myFile_j;


		this->m_pro_J.SetRange(0,900);
		m_pro_J.SetStep(100);
		m_pro_J.SetPos(0);

		if(pathname_j!=' ')
		{
			myFile_j.Open(pathname_j,CFile::modeRead,NULL);//打开文件
		   
			 SetDlgItemText(IDC_STATIC_J,_T("正在读取文件..."));

			DWORD t_file_long;
			t_file_long=myFile_j.GetLength();
            char *t_file_str;
			t_file_str=new char[t_file_long+1];
			myFile_j.Read(t_file_str,t_file_long);
			t_file_str[t_file_long]='\0';
			myFile_j.Close();
             
			m_pro_J.StepIt();


			 SetDlgItemText(IDC_STATIC_J,_T("提取压缩码..."));

			CString yasuoma;//提取压缩码
			int n_counter_ma;
			CString temp_yasuoma;
			int yasuoma_length;
			int i;
			for ( i=0;;i++)
			{
				if (t_file_str[i]==' ')
				{
					break;
				}
                temp_yasuoma+=t_file_str[i];
			}
       
			int x2,iCounter;
			char * p_char;
			x2=temp_yasuoma.GetLength();
			p_char=new char[x2];
			for(iCounter=0;iCounter<x2;iCounter++)
			{
				p_char[iCounter]=temp_yasuoma[iCounter];
			}
	
			
			yasuoma_length=atoi(p_char);
			delete []p_char;

			

			for ( n_counter_ma=i+1;n_counter_ma<yasuoma_length+i+1;n_counter_ma++)
			{
				
				yasuoma+=t_file_str[n_counter_ma];
			}
           
			m_pro_J.StepIt();

			
			 
            //******重构哈弗曼树*********

			 SetDlgItemText(IDC_STATIC_J,_T("重构哈弗曼树..."));

            
			haffnode t_node_j[256];
			int t_n_j=0;
			yasuoma+=' ';
			
		    for (int count_i=0;count_i<yasuoma_length;count_i++)
		    {
				CString temp_int;
				t_node_j[t_n_j].m_ch=yasuoma[count_i];//先把ch赋值
				int count_j;
				for (count_j=count_i+1;yasuoma[count_j]!=' '&&count_j!=yasuoma_length;count_j++)
				{
                    
					temp_int+=yasuoma[count_j];
                    
				}
				x2=temp_int.GetLength();
				p_char=new char[x2];
				for(iCounter=0;iCounter<x2;iCounter++)
				{
					p_char[iCounter]=temp_int[iCounter];
				}
				
				int t_int_weight=atoi(p_char);
				delete []p_char;

				t_node_j[t_n_j].weight=t_int_weight;
				count_i=count_j;
				if (count_j==yasuoma_length)
				{
					break;
				}
				t_n_j++;
		    }
		    t_n_j++;	
			
			m_pro_J.StepIt();



       //****************构建最小堆************************

			 SetDlgItemText(IDC_STATIC_J,_T("构建最小堆..."));


	        MinHeap<haffnode>heap_j;
			heap_j.makeHeap(t_n_j);
            for (int n_counter_heap=0;n_counter_heap<t_n_j;n_counter_heap++)
            {
				heap_j.insert(t_node_j[n_counter_heap]);
            }
        
			m_pro_J.StepIt();



       //***************构建哈弗曼树***********************

			 SetDlgItemText(IDC_STATIC_J,_T("构建哈弗曼树..."));


			haffnode root_j;
			while(heap_j.getsize()>1)
			{
				haffnode *t_a,*t_b;
				haffnode  a,b,huff;
				t_a=new haffnode;
				t_b=new haffnode;
				
				heap_j.del(a);
				t_a->left=a.left;
				t_a->right=a.right;
				t_a->weight=a.weight;
				t_a->m_ch=a.m_ch;
				huff.left=t_a;
				
				heap_j.del(b);
				t_b->left=b.left;
				t_b->right=b.right;
				t_b->weight=b.weight;
				t_b->m_ch=b.m_ch;
				huff.right=t_b;
				
				
				huff.weight=t_a->weight+t_b->weight;
				heap_j.insert(huff);
			}
            
			heap_j.del(root_j);

			m_pro_J.StepIt();

		
		//******恢复0101的状态了***********

			 SetDlgItemText(IDC_STATIC_J,_T("恢复二进制代码..."));


		    int *n_temp;
			int n_n_temp;//数组的大小
			unsigned char *c_temp;
			n_temp=new int[t_file_long-yasuoma_length-i-1];
			c_temp=new unsigned char[t_file_long-yasuoma_length-i-1];
			int count_char;
			for ( count_char=yasuoma_length+1+i;count_char<t_file_long-1;count_char++)
		    {
				c_temp[count_char-yasuoma_length-1-i]=t_file_str[count_char];
				n_temp[count_char-yasuoma_length-1-i]=c_temp[count_char-yasuoma_length-1-i];
		    }
		    n_n_temp=count_char-yasuoma_length-1-i;//记录下数组的大小


			m_pro_J.StepIt();




		//*****恢复成010101样式的文件*********
 
			 SetDlgItemText(IDC_STATIC_J,_T("保存二进制代码..."));


			CString content_str;
			for (int n_counter_to01=0;n_counter_to01<n_n_temp-1;n_counter_to01++)
			{
                CString str_temp= tran(n_temp[n_counter_to01],2);
				content_str+=str_temp;
			}


			m_pro_J.StepIt();



			//**最后一个特殊处理*******

			 SetDlgItemText(IDC_STATIC_J,_T("最后一个特殊处理字符..."));


			CString str_temp=tran_1(n_temp[n_n_temp-1],2);
			if (str_temp.GetLength()==atoi(&t_file_str[t_file_long-1]))
			{
				content_str+=str_temp;
			}
			else
			{
				int temp_int_0=atoi(&t_file_str[t_file_long-1])-str_temp.GetLength();
				if (temp_int_0==1)
				{
					CString str_add=_T("0");
					str_add+=str_temp;
				    content_str+=str_add;
				}
				else if (temp_int_0==2)
				{
					CString str_add=_T("00");
					str_add+=str_temp;
				    content_str+=str_add;
				}
				else if (temp_int_0==3)
				{
					CString str_add=_T("000");
					str_add+=str_temp;
			    	content_str+=str_add;
				}
				else if (temp_int_0==4)
				{
					CString str_add=_T("0000");
					str_add+=str_temp;
				    content_str+=str_add;
				}
				else if (temp_int_0==5)
				{
					CString str_add=_T("00000");
					str_add+=str_temp;
				    content_str+=str_add;
				}
				else if(temp_int_0==6)
				{
					CString str_add=_T("000000");
					str_add+=str_temp;
				    content_str+=str_add;
				}
				else 
				{
					CString str_add=_T("0000000");
					str_add+=str_temp;
				    content_str+=str_add;
				}

			}


			m_pro_J.StepIt();


           	//delete []c_temp;
			//delete []n_temp;
			

		/*	CFile t_file_01;
			t_file_01.Open("0101_01.txt",CFile::modeCreate|CFile::modeWrite,NULL);
			t_file_01.Write(content_str,content_str.GetLength());
			t_file_01.Close();*/
			
		//*****现在可以恢复文件了********
			//myFile_j.Open(pathname_j_save,CFile::modeCreate|CFile::modeWrite|CFile::typeBinary,NULL);

			 SetDlgItemText(IDC_STATIC_J,_T("恢复源文件..."));


			haffnode temp_node;
			temp_node=root_j;
			CString content_str1;
			for (int counter_01=0;counter_01<content_str.GetLength();counter_01++)
			{
				if (temp_node.left==NULL&&temp_node.right==NULL)
				{
					content_str1+=temp_node.m_ch;
					temp_node=root_j;
				//	myFile_j.SeekToEnd();
				//	myFile_j.Write(&temp_node.m_ch,sizeof(char));
				}
				if (content_str[counter_01]=='0')
				{
					temp_node=*temp_node.left;
					continue;
				}
				if (content_str[counter_01]=='1')
				{
					temp_node=*temp_node.right;
					continue;
				}
			}
			


			if (temp_node.left==NULL&&temp_node.right==NULL)
			{
				content_str1+=temp_node.m_ch;
				//myFile_j.SeekToEnd();
				//myFile_j.Write(&temp_node.m_ch,sizeof(char));

				temp_node=root_j;
			}
       
			myFile_j.Open(pathname_j_save,CFile::modeCreate|CFile::modeWrite|CFile::typeBinary,NULL);

			unsigned long x3;
			x3=content_str1.GetLength();
			p_char=new char[x3];
			for(iCounter=0;iCounter<x3;iCounter++)
			{
			    p_char[iCounter]=content_str1[iCounter];
			}
			myFile_j.Write(p_char,x3);
			delete []p_char;
		
			//myFile_j.Write(content_str1,content_str1.GetLength());
			myFile_j.Close();

			m_pro_J.StepIt();

			 SetDlgItemText(IDC_STATIC_J,_T("解压成功..."));

             

            AfxMessageBox(_T("解压缩成功"),MB_ICONINFORMATION);
			OnOK();

			delete []t_file_str;

		
			
		 
		}
 
		if (pathname_j==' ')
		{
			AfxMessageBox(_T("请你选择文件"),MB_ICONEXCLAMATION);
			OnOK();
		}


}
