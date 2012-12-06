#include "StdAfx.h"
#include "haffnode.h"

haffnode::haffnode(void)
{
  weight=0;
  left=NULL;
  right=NULL;
  haveornot=0;//¹¹Ôìº¯Êý

}

haffnode::~haffnode(void)
{
	weight=0;
	left=NULL;
	right=NULL;
	haveornot=0;
}
