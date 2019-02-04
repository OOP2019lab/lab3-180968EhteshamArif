#include "Header.h"
#include<iostream>
using namespace std;

void Rectangle::setlength(int l)
{
	if(l>0)
	{
		length=l;
	}
	else
	{
		length=0;
	}
}
void Rectangle::setwidth(int w)
{
	if(w>0)
	{
	  width=w;
	}
	else
	{
		width=0;
	}
}
void Rectangle::rotaterectangle()
	{
		int temp=width;
		width=length;
		length=temp;
	}
void Rectangle::draw()
{
	for(int i=0;i<length;i++)
	{
		cout<<"*";
		for(int j=0;j<width;j++)
		{
			cout<<"*";
		
		}
		cout<<endl;
	}
}