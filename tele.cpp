#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<iomanip>
using namespace std;

 class customer
{
	protected:
	char name[30];
	int age;
	char service[10];
	char plan[20];
	float total;
	float due;
	float balance;
	float amount;
	int time;
	public:
		long int number;
		void get_data();
		void show_data();
		void postpaid();
		void bill();
		void lists();
		
};
void customer :: lists()
{
	cout<<number<<"\t\t"<<name<<"\t\t"<<age<<"\t\t"<<service<<"\t\t"<<plan<<"\t\t"<<amount<<"\t\t"<<due<<"\t\t"<<balance<<endl;
}
 void customer :: get_data()
{
	int ch;
	cout<<"Enter the mobile number of the customer : ";
	cin>>number;
	cout<<"\n Enter the name of the customer : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n Enter the age of the customer : ";
	cin>>age;
	cout<<"\n Enter the service customer wants to choice i.e., ";
	cout<<"\n 1. Prepaid \t\t\t 2.Postpaid \n";
	cin>>ch;
	if(ch == 1)
	{
		strcpy(service, "Prepaid");
		int ch;
		float t;
		cout<<"\t Availabe Plans : \n";
		cout<<"Plan 1 (Unlimited @ 499/month)\t\t Plan 2 (500 minutes @ 399/month)";
		cout<<"Plan 3 (350 minutes @ 249/month)\t\t Plan 4 (250 minutes @ 149/month)";
		cout<<"\n Note :- The final amount will be including GST .";
		label:
		cout<<"\n Enter the plan customer chosed : \n";
		cin>>ch;
		switch(ch)
		{
			case 1 : strcpy(plan, "499/month");
		
					 amount = (499 + ((18 * 499) / 100)  );
					 due = 0;
					 balance = 0;
					 total = amount + due - balance;
					 break;
			case 2 : strcpy(plan, "399/month");					 
					 amount = (399 + ((18 * 399) / 100)  );
					 due = 0;
					 balance = 0;
					 total = amount + due - balance;
					 break;
			case 3 : strcpy(plan, "249/month");					
					 total = (249 + ((18 * 249) / 100)  );
					 due = 0;
					 balance = 0;
					 total = amount + due - balance;
					 break;
			case 4 : strcpy(plan, "149/month");
					 amount = (149 + ((18 * 149) / 100) );
					 due = 0;
					 balance = 0;
					 total = amount + due - balance;
					 break;
			default : cout<<"\n You have entered invalid choice.";
					 goto label;		 
		}
	}
	else
	{
		strcpy(service, "Postpaid");
		strcpy(plan, "As per Consumption");
		postpaid();
	}
}
void customer::show_data()
{
	cout<<"\n Customer Number : "<<number;
	cout<<"\n Customer Name : "<<name;
	cout<<"\n Customer Age : "<<age;
	cout<<"\n Service Provided : "<<service;
	cout<<"\n Service Plan : "<<plan;
}
void customer ::bill()
{
	float pay;
	cout<<"Number          Name             Total_Amount          Due Amount       Balance Amount\n ";
	cout<<number<<"        "<<name<<"          "<<total<<"       "<<due<<"          "<< balance <<endl;
	cout<<"Enter the amount to be paid : ";
	cin>>pay;
	if ( pay < total)
	{
		due = total - pay ;	
	}
	else if ( pay >total)
	{	
		due = 0;
		balance = amount - due;
	}
	else
	{
		due = 0;
		balance = 0;
	}
	cout<<" Bill Generation : \n";
	cout<<"Number          Name             Amount         Amount_Paid     Due_Amount       Balance_Amount\n ";
	cout<<number<<"\t\t"<<name<<"\t\t"<<total<<"\t\t"<<pay<<"\t\t"<<due<<"\t\t"<<balance<<endl;
	cout<<"\n\n Making Digital India \n So Do not print the bill \n As the Bill invoice is sent to the customer.";
}
void customer :: postpaid()
{
	cout<<"Enter the time used by the customer : ";
	cin>>time;
	amount = (time * 0.5);
	due = 0;
	balance =0;
	total = amount + due - balance;
}
int main()
{
	void intro();
	intro();
}
void intro()
{
	void login();
	char key;
	cout<<"################################################################################################################################################"<<endl;
	cout<<" ####################################****************** WELCOME TO TELECOM BILLING SYSTEM ******************######################################\n";
	cout<<"################################################################################################################################################"<<endl;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t   Press Any Key To Go To Login Page: ";
	cin>>key;
	login();
}
void menu();
void login()
{	
	system("cls");
	string username, password;
	cout<<"\t\t\t\t WELCOME TO TELECOM BILLING SYSTEM   "<<endl;
	cout<<"\t\t\t LOGIN PAGE :-\n\n"<<endl;
	cout<<"Enter username :- \t";
	cin>>username;
	cout<<"\n Enter password :-\t";
	cin>>password;
	if(username == "user")
	{
		if(password == "pass")
		{system("cls");
		menu();
		}
	}
	else
	{
		cout<<"\nSorry invalid username or password, please try again.";
		login();
	}
}

void add_records();
void delete_records();
void search_records();
void modify_records();
void list_records();
void payment();
void menu()
{
	int ch;
	cout<<"\t\t\t\t WELCOME TO TELECOM BILLING SYSTEM   "<<endl;
	cout<<"\t\t\t\tMAIN MENU\n\n";
	cout<<"\t\t\t 1. Add Records \n ";
	cout<<"\t\t\t 2. Delete Records \n ";
	cout<<"\t\t\t 3. Search Records \n ";
	cout<<"\t\t\t 4. Modify Records \n ";
	cout<<"\t\t\t 5. List Records \n ";
	cout<<"\t\t\t 6. Payment \n ";
	cout<<"\t\t\t 7. Exit \n ";
	cout<<"\t\t\t Enter Your Choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1: system("cls");
				add_records();
				break;
		case 2: delete_records();
				break;
		case 3: search_records();
				break;
		case 4: modify_records();
				break;
		case 5: list_records();
				break;
		case 6: payment();
				break;
		case 7: exit(1);
				break;
	}
}
void add_records()
{
	char ch;
	customer c;
	fstream File;
	File.open("customer.dat",ios::out | ios::app);
	cout<<"Enter the details of the customer : "<<endl;
	c.get_data();
	File.write((char*)&c, sizeof(c));
	File.close();
	cout<<"Do you want to enter more records: (Y/N) "<<endl;
	cin>>ch;
	if( ch == 'Y' || ch == 'y')
	{
	 system("cls");
	 add_records();	
	}
	else
	{
	 system("cls");
	 menu();	
	}
}

void delete_records()
{
	system("cls");
	long int number;
	char ch;
	customer c;
	fstream File;
	ofstream Temp;
	cout<<"\n Enter the number whose record u want  to delete : ";
	cin>>number;
	File.open("customer.dat",ios::in);
	Temp.open("temp.dat",ios::out);
	while(File.read((char*)&c, sizeof(c)))
	{
		if(c.number!=number)
		{
			Temp.write((char*)&c, sizeof(c));
		}
	}
	File.close();
	Temp.close();
	cout<<"\n Record has been deleted.";
	remove("customer.dat");
	rename("temp.dat", "customer.dat");
	cout<<"\n Do you want to delete more records: (Y/N) : ";
	cin>>ch;
	if(ch == 'Y' || ch == 'y')
	{
		system("cls");
		delete_records();
		}	
	else
	{
		system("cls");
		menu();
	}
}

void search_records()
{
	system("cls");
	long int number;
	int flag=0;
	char ch;
	customer c;
	cout<<"\n Enter the number of the customer whose record u want to search : ";
	cin>>number;
	fstream File;
	File.open("customer.dat",ios::in);	
	while(File.read((char*)&c, sizeof(c)))
	{
		if(c.number == number)
		{
			flag = 1;
			c.show_data();
		}
	}
	File.close();
	if(flag == 1)
	{
	 cout<<"\n Search has been done successfully.";	
	}
	else
	{
		cout<<"\n Sorry Record Not Found.";
	}
	cout<<"\n Do you want to search more records: (Y/N) : ";
	cin>>ch;
	if(ch == 'Y' || ch == 'y')
	{
		system("cls");
		search_records();
	}	
	else
	{
		system("cls");
		menu();
	}
}

void modify_records()
{
	system("cls");
	long int number;
	int flag = 0;
	char ch;
	customer c;
	cout<<"\n Enter the number of the customer whose record u want to search : ";
	cin>>number;
	fstream File;
	File.open("customer.dat",ios::in | ios::out);
	File.seekg(ios::beg);	
	while(File.read((char*)&c, sizeof(c)))
	{
		if(c.number == number)
		{
			flag = 1;
			c.show_data() ;
			cout<<"\n Enter new details of the customer : \n";
			c.get_data();
			File.seekg(File.tellg()-sizeof(c));
			File.write((char*)&c, sizeof(c));	
		}
	}
	File.close();
	if(flag == 1)
	{
	 cout<<"\n Record Updated Successfully.";	
	}
	else
	{
		cout<<"\n Record Not Found.";
	}
	cout<<"\n Do you want to modify more records: (Y/N) : ";
	cin>>ch;
	if(ch == 'Y' || ch == 'y')
	{
		system("cls");
		modify_records();
	}	
	else
	{
		system("cls");
		menu();
	}
}

void list_records()
{	
	char ch; 
	customer c;
	cout<<"**********************************************************************************************************************************\n";
	cout<<"Number         Name            Age        Service          Plan              Amount         Due Amount            Balance Amount\n";
	cout<<"**********************************************************************************************************************************\n";	
	fstream File;
	File.open("customer.dat",ios::in);
	while(File.read((char*)&c, sizeof(c)))
	{
		c.lists();
		cout<<endl;
	}
	File.close();
	cout<<"\n\n Press any key to go back to main menu: ";
	cin>>ch;
	system("cls");
	menu();
}

void payment()
{
	system("cls");
	long int number;
	int flag =0;
	char ch;
	customer c;
	cout<<"\n Enter the number of the customer whose record u want to search : ";
	cin>>number;
	fstream File;
	File.open("customer.dat",ios::in | ios::out);
	File.seekg(ios::beg);
	while(File.read((char*)&c, sizeof(c)))
	{
		if(c.number == number)
		{
			flag = 1;
			c.bill();
			File.seekg(File.tellg()-sizeof(c));
			File.write((char*)&c, sizeof(c));	
		}
	}
	File.close();
	if(flag == 1)
	{
	 cout<<"\n Payment Done Successfully.";	
	}
	else
	{
		cout<<"\n Record Not Found.";
	}
	cout<<"\n Do you want to make another payment : (Y/N) : ";
	cin>>ch;
	if(ch == 'Y' || ch == 'y')
	{
		system("cls");
		payment();
	}	
	else
	{
		system("cls");
		menu();
	}
}

