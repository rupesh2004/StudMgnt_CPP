#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
#include<stdlib.h>
# define max 50

int ch, size;
int roll[max], marks1[max], marks2[max], marks3[max];
char firstname[max][40], lastname[max][40];

void getStudentRecord();
void displayAllRecords();
void displayRecordRollWise();
void updateRecord();
void deleteRecord();
void update(int r);
void updateRoll(int r);
void updateName(int r);
void updateMarks(int r);
int main()
{
	do
	{
		cout<<"\n------------------Student Record Management-------------------------------------";
		cout<<"\n1.Insert student record\n2.Display all records\n3.Display record roll no wise\n4.Update student record\n5.Delete record";
		cout<<"\n6.Press 6 to exit ";
		cout<<"\n--------------------------------------------------------------------------------";
		cout<<"\nEnter Your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				getStudentRecord();
				break;
			case 2:
				displayAllRecords();
				break;
			case 3:
				displayRecordRollWise();
				break;
			case 4:
				updateRecord();
				break;
			case 5:
				deleteRecord();
				break;
			case 6:
				exit(0);
			default:
				cout<<"\nInvalid choice...!";
		}
	}while(ch!=0);
	return 0;
}

void getStudentRecord()
{
	cout<<"\nEnter number of student records to be inserted : ";
	cin>>size;

	for(int i=0;i<size;i++)
	{
		cout<<"\nEnter details of "<<i+1<<"th student -->\n ";
		cout<<"\nEnter Roll No: ";
		cin>>roll[i];
		cout<<"\nEnter First Name and Last Name: ";
		cin>>firstname[i]>>lastname[i];
		cout<<"\nEnter marks of JAVA: ";
		cin>>marks1[i];
		cout<<"\nEnter marks of CPP: ";
		cin>>marks2[i];
		cout<<"\nEnter marks of C: ";
		cin>>marks3[i];
	}
}

void displayAllRecords()
{
	cout<<"\n<------------------------------ Student Records ------------------------------>\n";
	cout<<"\nRoll No\t\tName\t\t\t\t\t\tMarks\n\t\t\t\t\t\t\tJava\tCPP\tC";
	for(int i=0;i<size;i++)
	{

		cout<<"\n"<<roll[i];
		cout<<"\t\t"<<firstname[i]<<" "<<lastname[i];
		cout<<"\t\t\t\t"<<marks1[i];
		cout<<"\t"<<marks2[i];
		cout<<"\t"<<marks3[i];
		cout<<endl;
	}
	cout<<endl;
}

void displayRecordRollWise()
{
	int r;
	cout<<"\nEnter roll number to find record: ";
	cin>>r;
	for(int i=0;i<size;i++)
	{
		if(roll[i] == r)
		{
			cout<<"\nRoll No\t\tName\t\t\t\t\t\tMarks\n\t\t\t\t\t\t\tJava\tCPP\tC";
				cout<<"\n"<<roll[i];
				cout<<"\t\t"<<firstname[i]<<" "<<lastname[i];
				cout<<"\t\t\t\t"<<marks1[i];
				cout<<"\t"<<marks2[i];
				cout<<"\t"<<marks3[i];
				cout<<endl;
		}
	}
}

void updateRecord()
{
	int r;
	cout<<"\nEnter roll number to be updated: ";
	cin>>r;
	for(int i=0;i<size;i++)
	{
		if(roll[i] == r)
		{
			cout<<"\nRoll No\t\tName\t\t\t\tMarks\n\t\t\t\t\tJava\tCPP\tC";
				cout<<"\n"<<roll[i];
				cout<<"\t\t"<<firstname[i]<<" "<<lastname[i];
				cout<<"\t\t"<<marks1[i];
				cout<<"\t"<<marks2[i];
				cout<<"\t"<<marks3[i];
				cout<<endl;
		}
	}

	update(r);
}

void update(int r)
{
	int c;
	do
	{

		cout<<"\nSelect option to update data: ";
		cout<<"\n1.Roll No\n2.Name\n3.Marks\n4.Press 0 to exit";

		cout<<"\nEnter Your choice: ";
		cin>>c;
		switch(c)
		{
			case 1:
				updateRoll(r);
				break;
			case 2:
				updateName(r);
				break;
			case 3:
				updateMarks(r);
				break;
			default:
				cout<<"\nInvalid choice...!";
		}
	}while(c!=0);

}

void updateRoll(int r)
{

	int rl;
	cout<<"\nEnter roll no:";
	cin>>rl;
	for(int i=0;i<size;i++)
	{
		if(roll[i]==r)
		{
			roll[i] = rl;
			cout<<"\nRoll No Updated Successfully";
		}
	}
	cout<<endl;
}

void updateName(int r)
{
	int n;
	char nm[20];
	cout<<"\nPress 0 to update FirstName / Press 1 to update Last Name ";
	cin>>n;
	if(n==0)
	{
		cout<<"\nEnter first name: ";
		cin>>nm;
	}
	else if(n==1)
	{
		cout<<"\nEnter last name: ";
		cin>>nm;
	}
	for(int i=0;i<size;i++)
	{
		if(roll[i] == r)
		{
			if(n == 0 && strlen(nm)!= 0)
			{
				strcpy(firstname[i], nm);
			}
			else if(n ==1 && strlen(nm)!= 0)
			{
				strcpy(lastname[i], nm);
			}
			cout<<"\nName Updated Successfully"<<endl;
		}
	}
}

void updateMarks(int r)
{
	int n, m;
	cout<<"\nPress 0 to update Marks of Java / Press 1 to Marks of CPP / Press 2 to Marks of C ";
	cin>>n;
	cout<<"\nEnter marks to update : ";
	if(n==0)
	{
		cin>>m;
	}
	else if(n==1)
	{
		cin>>m;
	}
	else if(n==2)
	{
		cin>>m;
	}
	for(int i=0;i<size;i++)
	{
		if(roll[i] == r)
		{
			if(n == 0)
			{
				marks1[i] = m;
			}
			else if(n==1)
			{
				marks2[i] = m;
			}
			else if(n==2)
			{
				marks3[i] = m;
			}
			cout<<"\nMarks Updated Successfully"<<endl;
		}
	}
}
void deleteRecord()
{
	int r;
	char ch;
	cout<<"Enter roll no to delete record : ";
	cin>>r;
	cout<<"\nAre you sure, you want to delete record (y/n): ";
	cin>>ch;
	if(ch=='y')
	{
		for(int i=0;i<size;i++)
		{
			if(roll[i] == r)
			{
				for(int j=i; j<=size; j++)
		{
				roll[j]=roll[j+1];
				strcpy(firstname[j],firstname[j+1]);
				strcpy(lastname[j],lastname[j+1]);
				marks1[j]=marks1[j+1];			
				marks2[j]=marks2[j+1];
				marks3[j]=marks3[j+1];
		}
		cout<<"\nRecord deleted successfully\n";
			}
		}
	}
	else if(ch=='n')
	{
		cout<<"\nNo Record deleted\n";
	}
}

