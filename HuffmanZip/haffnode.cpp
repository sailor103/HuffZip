#include "StdAfx.h"
#include "haffnode.h"

haffnode::haffnode(void)
{
  weight=0;
  left=NULL;
  right=NULL;
  haveornot=0;//���캯��

}

haffnode::~haffnode(void)
{
	weight=0;
	left=NULL;
	right=NULL;
	haveornot=0;
}
