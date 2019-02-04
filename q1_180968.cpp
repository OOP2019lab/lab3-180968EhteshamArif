#include<iostream>
#include<fstream>
#include "Header2.h"
#include<fstream>
#include<string>
using namespace std;
//Display function to Display all
void Display(gitHubUser* arr, int size)
{
	  cout<<endl<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"The First name of User "<<i+1<<" is :"<<arr[i].firstname<<endl;
		cout<<"The Username of User "<<i+1<<" is :"<<arr[i].username<<endl;
		cout<<"The Email for User "<<i+1<<" is :"<<arr[i].email<<endl;
		for(int j=0;j<arr[i].foldercount;j++)
		{
			cout<<"The Folders for User are :"<<arr[i].gitHubFolders[j]<<endl;
		}
		
	}
}
//function to print educational background
void print(gitHubUser &user)
{
	cout<<"The name of educational institution of the user is :"<<user.institute_name<<endl;
	cout<<"The qualification level of the user is :"<<user.qualification_level<<endl;
}
//function to set educational background
void setEduBckGrnd(gitHubUser &user)
{
	int input;
	int input2;

	      cout<<"Enter your Institusion Name (Optional), Press y for 'Yes' or n for 'No'"<<endl;
	      cin>>input;
	      if(input=='y'|| input=='Y')
	      {
			  cout<<"Now Enter the name :"<<endl;
			  user.institute_name=new string;
			  cin>>*user.institute_name;
			 // getline(cin,*user.institute_name);
	      }
		  else if(input=='N'||input=='n')
		  {
			  cout<<"Enter your Qualification Level (Optional), press y for 'Yes' or n for 'No'"<<endl;
			  cin>>input2;
			   if(input2=='y'|| input2=='Y')
	          {
				  user.qualification_level=new string;

				  cin>>*user.qualification_level;
				 // getline(cin,*user.qualification_level);
	          }
			   else if(input2=='N'|| input2=='n')
			   {
				   cout<<"-----That's it-----"<<endl;  
			   }
		  }
}
//function to remove educational background for the user
void remove(gitHubUser &user)
{
	int input;
	cout<<"Do you want to remove the educational background ?"<<" Press y for 'Yes' and n for 'N' :";
	cin>>input;
	if(input=='y'|| input=='Y')
	{
		delete[] user.qualification_level;
		delete[] user.institute_name;
		user.qualification_level=nullptr;
		user.institute_name=nullptr;
	}
	if(input=='N'||input=='n')
	{
	cout<<"You opt to not to delete your information "<<endl;
	}
}
//fucntion to read data
void readDataFromFile( gitHubUser * users, string filepath)
{
	users=new gitHubUser[2];
	ifstream fin;
	fin.open(filepath);
	if(!fin)
	{
		cout<<"--------Could not load File-------"<<endl;
	
	}
	else
	{
		int size=0;
		int folder;
		fin >> size;
		//cout<<size;
		for(int i=0;i<size;i++)
		{
			fin>>users[i].firstname;
			fin>>users[i].username;
			fin>>users[i].email;
			fin>>users[i].foldercount;
			folder=users[i].foldercount;
			users[i].gitHubFolders=new string[folder];
			fin.ignore();
			for(int j=0;j<folder;j++)
			{
				getline(fin, users[i].gitHubFolders[j]);
			}
		
		}
		Display(users,size);
	}
}
//function to backup data
void backup(gitHubUser *originalArry, gitHubUser *&backupArry, int userCount)
{
	for(int i=0;i<userCount;i++)
	{
		originalArry[i]=backupArry[i];
		for(int j=0;j<originalArry[i].foldercount;j++)
		{
			backupArry[i].gitHubFolders=new string[originalArry[i].foldercount];
			backupArry[i].gitHubFolders[j]=originalArry[i].gitHubFolders[j];
			backupArry[i].gitHubFolders=new string;
			backupArry[i].institute_name=originalArry[i].institute_name;
			backupArry[i].qualification_level=new string;
			backupArry[i].qualification_level=originalArry[i].qualification_level;
		}
	}
}
//respective main
int main()
{
	gitHubUser arr[2];
	gitHubUser *backUp;
	string filepath="save.txt";
	int user;
	int i;
	readDataFromFile(arr,filepath);
	cout<<"Enter the user you want to set Educational background with (1 or 2):";
	cin>>user;
	if(user==1)
	{
		 i=0;
	}
	if(user==2)
	{
		i=1;
	}
	setEduBckGrnd(arr[1]);
	print(arr[1]);
	remove(arr[1]);
	backup(arr,backUp,2);
}
