#include"Header.h"
#include<iostream>
using namespace std;


int main()
{
	Rectangle r1;
	r1.setlength(2);
	r1.setwidth(3);
	cout<<endl;
	cout<<"The length of the rectangle is :"<<r1.getlength()<<endl;
	cout<<"The width of the rectangle is :"<<r1.getwidth()<<endl;
	cout<<"The area of the rectangle is :"<<r1.getarea()<<endl;
	cout<<"The drawn rectangle is :"<<endl;
    r1.draw();
	r1.rotaterectangle();
	cout<<"After rotation the drawn rectangle is :"<<endl;
	 r1.draw();
	system("pause");
	return 0;
}