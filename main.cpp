//START
#include<iostream>		//input/output objects c++
#include<stdio.h>		//standard input/output c
#include<stdlib.h>
#include <sstream>		//standard library
#include<conio.h>		//getch function
#include<dos.h>			//delay function
#include<windows.h>		//Sleep,gotoxy coordinate functions
#include<iomanip>		//output manipulatons
#include<fstream>		//file handling
#include<string.h>		//string abstract datatype
#include<math.h>		//mathematical operations
#include<time.h>
#include<string>		//system current time and date
#include"MMSystem.h"
using namespace std;
using namespace std;
char loc[20];			//holds time ad date 
//void play(int);			//function for playing audio track
//void delr1();			//delete file 
//void delr2();			//rename file
void gotoxy (int x, int y);	//handle output on screen
void frame ();			//frame for every dialog box
void frame_fix();
char *date_time ();
void scroll_note();		
void flow(char *ch);
COORD coord = {0, 0};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class System
{
	public:
		string user,pass,u,p;
	string User_Name,address,first_Name,last_Name,ph_no;
	int found;
	string password,confirm_pass,ch;
	std::string buffer1,buffer2,buffer,s,key,buffer3,modelno,buffer4;
	void main_menu();
	void Owner_login();
	void New_Register();
	void User_Login();
	void read_data();
	void pack_data();
	void pack_account();
	void account_write_to_file();
	void data_write_to_file();
	void new_register_option();
	int vehicle_no;
	void unpack_account();
	void unpack_data();
	void unpack_vehicle();
	void find_users();
	void pack_user_details();
	void unpack_user_details();
	int search_user_details(string);
	int delete_user_details(string);
	void search_vehicle_detail(string);
	int search_account(string);
	int account_delete_file(string);
	void account_modify(string);
	int search_data(string);
	int data_delete_file(string);
	void login_user2();
	void owner_option();
	void owner_view();
	void pack_user_model_details();
	void unpack_user_model_details();
	int search_user_model_details(string);
	int delete_user_model_details(string);
	void modify_user_medel_details(string);
	string phoneValidation (string);
	string check_username_exist(string);
	//void user_login_option();
};
class date		//class current date and time of system
{
	
	
	public:
		int aday,amonth,ayear,ahour,amin,asec;
	void date_times()
	{
		SYSTEMTIME t;		//pre defined in time.h header
 		GetLocalTime(&t);
		aday=t.wDay,amonth=t.wMonth,ayear=t.wYear,ahour=t.wHour,amin=t.wMinute,asec=t.wSecond;
		
	}
};
void gotoxy (int x, int y)	//defining/initializing to predefined objects
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void frame()
{
	int i,j=150;
	for(i = 40;i<150,j>=40;i++,j--)
	{
		gotoxy(i,5);
		Sleep(10);
		cout<<"_";
		gotoxy(j,30);
		Sleep(10);
		cout<<"_";
	}
	gotoxy(120,4);
	char s[20];
	strcpy(s,date_time());
	cout<<s;		//every frame has date on the right top 
	
}
void frame_fix()	//instead of flow line fixing the frame
{
	int i,j=79;
	for(i = 0;i<80,j>=0;i++,j--)
	{
		gotoxy(i,3);
		cout<<"_";
		gotoxy(j,20);
		cout<<"_";
	}
	gotoxy(56,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;
}
char *date_time()
{
	time_t t;
	time(&t);
	char *loc=ctime(&t);
	return loc;	//returns local time and date
}
void flow(char *ch)	//flow of instructions
{
	char *str=ch;
	for(int i=0;i<strlen(str);i++)
	{
		Sleep(20);
		cout<<str[i];
	}
}
void scroll_note()	//welcome note
{
	system("color 0");
	int j,i,x,y;
	for(i=0;i<80;i++)
	{
		gotoxy(i,20);cout<<" ";
		cout<<" AUTO RENTAL MANAGEMNET SYSTEM";
		Sleep(40);
	}

	for(j=100;j>84;j--)
	{
		gotoxy(j,22);
		cout<<"WELCOMES YOU";cout<<"            ";
		Sleep(40);
	}

	for (int c = 1; c <= 20; c++)  //randomly printing "$"
	{

		x = rand() % 70 + 1;  y = rand() % 20 + 1;
		gotoxy(x,y);cout<<"$";
		Sleep(180);gotoxy(x,y);cout<<" ";
	}
	
	gotoxy(80,20);cout<<"AUTO RENTAL MANAGEMENT SYSTEM";
	gotoxy(85,22);cout<<"WELCOMES YOU";
	for(int j=160;j>=50;j--)
	{
		
		gotoxy(j,30);cout<<"|";
		gotoxy(j,10);cout<<"|";
		Sleep(30);
	}
	gotoxy(180,50);cout<<"Anusha     4SF17IS010";
	gotoxy(180,52);cout<<"Deekshitha 4SF17IS018";
	Sleep(2000);

}

string System::phoneValidation(string ph_no)
{
	bool invalidFormat = false;
	static const std::string pattern = "dddddddddd";
	
	while (!invalidFormat)
	{
		// initial loop to check the users phone number. One character at a time
	    for( int i = 0 ; i < ph_no.size() ; ++i )
	    {
	        if( pattern[i] == 'd' ) 			// digit expected
	        {
	            if( !isdigit( ph_no[i] ) ) 		//If there is not a digit return false
					invalidFormat = false ;
				else							
					invalidFormat = true ;
	        }
	        else if( pattern[i] != ph_no[i] ) 	//if the const PATTERN (ddd-ddd-dddd) doesn't = the phone number return false
				invalidFormat = false ;
			else 
				invalidFormat = true ;
	    }
	    if( ph_no.size() != pattern.size() ) 	// if the number of characters in the phone number doesn't = the pattern size return false
			invalidFormat = false;
		else
			invalidFormat = true ;
		
        if (!invalidFormat)						// if false than re-prompt question
		{
			cout << endl;
			//gotoxy(25,14);
			cout << "      ERROR! Invalid phone number. Re-enter phone number: ";
			cin>>ph_no;
		}
		else	
			invalidFormat = true;	
	}
    return ph_no;
}
string System::check_username_exist(string user)
{
        bool invalidFormat=false;
	//static const std::string pattern = "dddddddddd";
	int ch;
	
	while(!invalidFormat)
	{	// initial loop to check the users phone number. One character at a time
	   /* for( int i = 0 ; i < user.size() ; ++i )
	    {
	        
	        if( pattern[i] != user[i] ) 	//if the const PATTERN (ddd-ddd-dddd) doesn't = the phone number return false
				invalidFormat = false ;
			else 
				invalidFormat = true ;
	    }
	    if( user.size() != pattern.size() ) 	// if the number of characters in the phone number doesn't = the pattern size return false
			invalidFormat = false ;
		else
			invalidFormat = true ;*/
		
	 /*ifstream input("data.txt");
        while(input>>u)
        {
                if(u==user)
        
                {
                       invalidFormat = false; 
                }
                else
                	invalidFormat = true;
        }
        input.close();*/
        ch=search_data(user);
        if(ch==-1)
        	invalidFormat = true ;
        else
        	invalidFormat = false ;
        if (!invalidFormat)						// if false than re-prompt question
		{
			cout << endl;
			//gotoxy(25,18);
			cout << "The user name exist...please enter another username ";
			cin >> user;
			
		}
		else	
		invalidFormat = true;	
	}
    return user;
	
}

void System:: main_menu()	//main menu for all functios included
{
	system("cls");
	system("COLOR 0");
	frame();
	
	gotoxy(85,14);
	cout<<"OWNER";
	gotoxy(70,20);
	cout<<"USER";
	gotoxy(100,20);
	cout<<"NEW REGISTER";
	char op;
	gotoxy(40,32);
	cout<<"O : Owner Login------U: User-----N : New Register ";
	gotoxy(40,34);
	cout<<"E : Exit ";
	gotoxy(54,34);cout<<"";
	op=getch();
	if(op=='O' || op=='o')
	{
		Owner_login();	
	}
	else if(op=='n' || op=='N')
	{
		New_Register();
	}
	else if(op=='U' || op=='u')
	{
		User_Login();	
	}
	
	else if(op=='e'||op=='E')
	{
		system("cls");
		scroll_note();
	}
	else 
	{ 
		cout<<" \a\a\aINVALID OPTION ";
		Sleep(1000);
		main_menu();
	}
}
void System::Owner_login()
{
	string OWNER_NAME="Deeksha",OWNER_PASS="test@123";
	string owner_name="\0",owner_pass="\0";
	system("cls");
	system("COLOR 0");
	gotoxy(40,2);
	cout<<"*************************************************************OWNER LOGIN*********************************************************************";
	gotoxy(25,8);
	cout<<"Enter the Name:";
	cin>>owner_name;
	gotoxy(25,10);
	cout<<"Enter the Password:";
	cin>>owner_pass;
	if(owner_name==OWNER_NAME && owner_pass==OWNER_PASS)
	{
		gotoxy(25,14);
		cout<<"Login successfull";
		Sleep(1000);
		owner_option();
	}
	else
	gotoxy(25,14);
	cout<<"_____Login Unsuccessfull______";
	Sleep(5500);
	main_menu();
	
	
		
}
void System::owner_option()
{
	system("cls");
	ifstream file;
	int i=0,pos;
	gotoxy(20,4);
	cout<<"---All  users details---\n\n";
		ifstream MyFile("userdetails.txt");
					char ch,o;
			
					while(!MyFile.eof())
					{
						/*pos=MyFile.tellg();
						getline(file,buffer4);
						find_users();*/
						MyFile.get (ch);
						cout<<ch;
					
					}
					
					MyFile.close();
	//cout<<"\nEnter the User Name to know More About User:";
	cout<<"\nUSER NAME WITH '*' ARE DELETED ACCOUNTS";
	cout<<"\n\tB: Back N:Next Page --";
	cin>>o;
	if(o=='B'|| o=='b')
	{
		Sleep(1000);
		main_menu();
	}
	else if(o=='n'|| o=='N')
	{
		Sleep(1000);
		owner_view();
	}
	else
	{
			system("cls");
		scroll_note();
	}
					getch();
					
				
}
void System::owner_view()
{
	system("cls");
	string uname;
	int ch;
	gotoxy(20,4);
	cout<<"Enter user Name to know to more about user--";
	cin>>uname;
//	Sleep(5500);
	while(1)
	{
	system("cls");
	gotoxy(25,8);
	cout<<"1. View User Account Information";
	gotoxy(25,10);
	cout<<"2. View User Vehicle Informtion";
	gotoxy(25,12);
	cout<<"3.Go back";
	gotoxy(25,14);
	cout<<"4.Exit";
	gotoxy(25,16);
	cout<<"Enter your choice--";
	cin>>ch;
	switch(ch)
				{
					case 1:search_account(uname);
					Sleep(10000);
					break;
				
					case 2:search_vehicle_detail(uname);
					Sleep(10000);
					break;
					case 3:
							Sleep(1000);
							owner_option();
							
					break;
					case 4:	Sleep(1000);
								main_menu();
					break;
					
			}
	}
}
void System::User_Login()
{
	
		int count,ch;
        system("cls");
        gotoxy(40,2);
        cout<<"*************************************************************USER_LOGIN*********************************************************************\n";
        gotoxy(25,4);
        cout<<"Please Enter the Following details"<<endl;
        gotoxy(25,8);
        cout<<"USERNAME :";
        cin>>user;
        gotoxy(25,10);
        cout<<"PASSWORD :";
        cin>>pass;
        	
		
        ifstream input("data.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)
        
                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
			  
            
        
        //input.close();
       if(count==1)
        {
        	gotoxy(25,8);
	        cout<<"Hello  "<<user;
	        gotoxy(25,10);
			cout<<"LOGIN SUCESS";
			gotoxy(25,12);
			cout<<"We're glad that you're here.....Thanks for logging in";
	        Sleep(2500);
	        // user_login_option();
	        while(1)
	        {
			
			 
		            system("cls");
		            
					
		            gotoxy(25,8);
		        	cout<<"1.Account Information";
		        	gotoxy(25,10);
					cout<<"2.Vehicle Informtion";
					gotoxy(25,12);
					cout<<"3.Update Account Info";
					gotoxy(25,14);
					cout<<"4.Delete Account";
					gotoxy(25,16);
					cout<<"5.Exit";
					gotoxy(25,18);
					cout<<"Enter your choice--";
					cin>>ch;
				switch(ch)
				{
					case 1:search_account(user);
					Sleep(10000);
					break;
				
					case 2:search_vehicle_detail(user);
					Sleep(10000);
					break;
					case 3:account_modify(user);
					Sleep(10000);
					break;
					case 4:
					account_delete_file(user);
							data_delete_file(user);
							delete_user_model_details(user);
							delete_user_details(user);
							delete_user_details(user);
							Sleep(10000);
					break;
					case 5:		Sleep(10000);
								main_menu();	
					break;
			}
		
    	
    }
}
        else
        {
        		gotoxy(25,8);
                cout<<"LOGIN ERROR ...Please check your username and password";
                Sleep(1000);
                User_Login();
                
                
        }
        
}
/*void System::user_login_option()
{
	 system("cls");
		         int ch;    
					
		            gotoxy(25,8);
		        	cout<<"1.Account Information";
		        	gotoxy(25,10);
					cout<<"2.Vehicle Informtion";
					gotoxy(25,12);
					cout<<"3.Update Account Info";
					gotoxy(25,14);
					cout<<"4.Delete Account";
					gotoxy(25,16);
					cout<<"5.Exit";
					gotoxy(25,18);
					cout<<"Enter your choice";
					cin>>ch;
				switch(ch)
				{
					case 1:search_account(user);
					break;
					case 2:search_vehicle_detail(user);
					break;
					case 3:account_modify(user);
					break;
					case 4:account_delete_file(user);
							data_delete_file(user);
							delete_user_model_details(user);
					break;
					case 5:		Sleep(1000);
								main_menu();	
					break;
			}
    	
}*/
void System::New_Register()
{
	system("cls");
	system("COLOR 0");
	read_data();
		//if(strcmp(password,confirm_pass)==0)
		if(!(password!=confirm_pass))
		{
			pack_data();
			pack_account();
			pack_user_details();
			data_write_to_file();
			account_write_to_file();
			new_register_option();

		}
}
void System::read_data()
{
	fstream file; 
	ifstream ifile;
	char s[100],o;
	gotoxy(50,2);
	cout<<"*************************************NEW_REGISTER**********************************";
	gotoxy(25,8);
	cout<<"Enter the Your  First Name:";
	cin>>first_Name;
	gotoxy(25,10);
	cout<<"Select the Your  Last  Name:";
	cin>>last_Name;
	gotoxy(25,12);
	cout<<"Enter your Phone Number:";
	cin>>ph_no;
	 ph_no=phoneValidation(ph_no);
	gotoxy(25,16);
	cout<<"User Name:";
	cin>>User_Name;
	User_Name=check_username_exist(User_Name);
	gotoxy(25,20);
	cout<<"Enter the password:";
	cin>>password;
	gotoxy(25,22);
	cout<<"Re-enter the password:";
	cin>>confirm_pass;
	
}
void System::find_users()
{
	int ch=1,i=0;
	User_Name.erase();
	buffer4.erase();
	while(buffer4[i]!='$')
	User_Name+=buffer4[i++];
	found=1;
	cout<<User_Name;
}
void System::pack_user_details()
{
	buffer4+=User_Name+'$'+"\n";
	fstream file; 
	file.open("userdetails.txt",ios::out|ios::app);
	file<<buffer4<<endl;
	file.close();
}
void System::unpack_user_details()
{
	int ch=1,i=0;
	User_Name.erase();
	while(buffer4[i]!='$') 
	User_Name+=buffer4[i++];
}
int System::search_user_details(string key)
{
		ifstream file;
	int flag=0,pos=0;
	file.open("userdetails.txt",ios::in);
	while(!file.eof())
	{
		 buffer4.erase();
		 pos=file.tellg(); 
		 getline(file,buffer4);
		 unpack_user_details();
		 if(key==User_Name)
		 	{
			
			 return pos;
			 flag=1;
			}
	}
		file.close();
		if(flag==0)
		{
		//	cout<<"\nnot found..\n";
			return -1;
		}
}
int System::delete_user_details(string key)
{
	fstream file;
		int pos, flag=0;
		pos=search_user_details(key);
		if(pos>=0)
		{
			file.open("userdetails.txt");
			file.seekp(pos,ios::beg);
			file.put('*');
			flag=1;
			file.close();
		}
		if(flag==1)
		return 1;
		else
		return 0;
	
}
void System::pack_data()
{
	
	buffer1+=User_Name+" "+password+"\n";
	
	
}
void System::data_write_to_file()
{
	fstream file; 
	ifstream ifile;
	file.open("data.txt",ios::out|ios::app);
		file<<buffer1<<endl;
			file.close();
	 

			
}
void System::unpack_data()
{
	int ch=1,i=0;
	User_Name.erase();
	while(buffer1[i]!=' ') 
	User_Name+=buffer1[i++];
	password.erase();
	i++;
	while(buffer1[i]!='\n')
	password+=buffer1[i++];
	

}
int System::search_data(string key)
{
		ifstream file;
	int flag=0,pos=0;
	file.open("data.txt",ios::in);
	while(!file.eof())
	{
		 buffer1.erase();
		 pos=file.tellg(); 
		 getline(file,buffer1);
		 unpack_data();
		 if(key==User_Name)
		 	{
			 
			 return pos;
			 flag=1;
			}
	}
		file.close();
		if(flag==0)
		{
		//	cout<<"\nnot found..\n";
			return -1;
		}
}
int System::data_delete_file(string key)
{
	fstream file;
		int pos, flag=0;
		pos=search_data(key);
		if(pos>=0)
		{
			file.open("data.txt");
			file.seekp(pos,ios::beg);
			file.put('*');
			flag=1;
			file.close();
		}
		if(flag==1)
		return 1;
		else
		return 0;
}
void System::pack_account()
{
		buffer2.erase();  
	 buffer2+=User_Name+"|"+first_Name+"|"+last_Name+"|"+ph_no+"$"+"\n"; 
}

void System::account_write_to_file()
{
			fstream file; 
			 file.open("account.txt",ios::out|ios::app);
			 	file<<buffer2;
			file.close();
}
void System::unpack_account()
{
	int ch=1,i=0;
	User_Name.erase();
	while(buffer2[i]!='|') 
	User_Name+=buffer2[i++];
	first_Name.erase();
	i++;
	while(buffer2[i]!='|')
	first_Name+=buffer2[i++];
	last_Name.erase();
	i++;
	while(buffer2[i]!='|') 
	last_Name+=buffer2[i++];
	ph_no.erase();
	i++;
	while(buffer2[i]!='$') 
	ph_no+=buffer2[i++];

}
int System::search_account(string key)
{
	ifstream file;
	int flag=0,pos=0;
	file.open("account.txt",ios::in);
	while(!file.eof())
	{
		 buffer2.erase();
		 pos=file.tellg(); 
		 getline(file,buffer2);
		 unpack_account();
		 if(key==User_Name)
		 	{
			 //cout<<"\nfound the key .the record is...\n";
			 gotoxy(20,20);
			 cout<<"First_Name:"<<first_Name<<endl;
			 gotoxy(20,22);
			cout<<"Last_Name:"<<last_Name<<endl;
			gotoxy(20,24);
			 cout<<"Phone_Number:"<<ph_no<<endl;
			 return pos;
			 flag=1;
			 
			}
	}
		file.close();
		if(flag==0)
		{
			cout<<"\nData  Not Found\n";
			return -1;
			//user_login_option();
		}
}
int System::account_delete_file(string key)
{
		fstream file;
		int pos, flag=0;
		pos=search_account(key);
		if(pos>=0)
		{
			file.open("account.txt");
			file.seekp(pos,ios::beg);
			file.put('*');
			flag=1;
			file.close();
			
		}
		if(flag==1)
			{
			cout<<"         Account Deleted Successfully";
			//user_login_option();
			return 1;
		}
		else
		cout<<"Account could not be deleted at this momemt ";
		return 0;
}
void System::account_modify(string key)
{
			int c;
			system("cls");
		if(account_delete_file(key) && delete_user_model_details(key))
		{
		gotoxy(50,2);
		cout<<"*****************************Account Modification*****************************";	
		gotoxy(20,10);	
		cout<<"what you want  to update";
		gotoxy(20,12);
		cout<<"1:First_Name";
		gotoxy(20,14);
		cout<<"2:Last_Name";
		gotoxy(20,16);
		cout<<"3:Phone Number";
		gotoxy(20,18);
		cout<<"Your Previous Data";
		gotoxy(20,28);
		cout<<"Enter your Choice:";
		cin>>c;
		switch(c)
		{
			case 1:gotoxy(20,30);
				cout<<"First_Name:";
				cin>>first_Name;
			break;
			case 2:
				gotoxy(20,30);
				cout<<"Last_Name:";
				cin>>last_Name;
			
			break;
				
			case 3:gotoxy(20,30);
				cout<<"ph_no:";
				cin>>ph_no;
				ph_no=phoneValidation(ph_no);
			break;
			default:gotoxy(20,30);
			cout<<"Invalid Option";
		}
		cout<<"\n               Account is Modified Successfully";
		buffer2.erase();
		pack_account();
		account_write_to_file();
		buffer3.erase();
		pack_user_model_details();
		
}

}
void System::pack_user_model_details()
{
		fstream file; 
	buffer3.erase();
	buffer3+=User_Name+"|"+first_Name+"|"+last_Name+"|"+ ph_no+"|"+modelno+"$"+"\n";
						
						file.open("user_model_details.txt",ios::out|ios::app);
							file<<buffer3<<endl;
								file.close();
}
void System::unpack_user_model_details()
{
	int ch=1,i=0;
	User_Name.erase();
	while(buffer3[i]!='|') 
	User_Name+=buffer3[i++];
	first_Name.erase();
	i++;
	while(buffer3[i]!='|')
	first_Name+=buffer3[i++];
	last_Name.erase();
	i++;
	while(buffer3[i]!='|') 
	last_Name+=buffer3[i++];
	ph_no.erase();
	i++;
	while(buffer3[i]!='|') 
	ph_no+=buffer3[i++];
	modelno.erase();
	i++;
	while(buffer3[i]!='$')
	modelno+=buffer3[i++];
}
int System::search_user_model_details(string key)
{
		ifstream file;
	int flag=0,pos=0;
	file.open("user_model_details.txt",ios::in);
	while(!file.eof())
	{
		 buffer3.erase();
		 pos=file.tellg(); 
		 getline(file,buffer3);
		unpack_user_model_details();
		 if(key==User_Name)
		 	{
			 //cout<<"\nfound the key .the record is...\n";
			 /*cout<<"First_Name:"<<first_Name<<endl;
			cout<<"Last_Name:"<<last_Name<<endl;
			 cout<<"Phone_Number:"<<ph_no<<endl;*/
			 return pos;
			 flag=1;
			}
	}
		file.close();
		if(flag==0)
		{
			cout<<"Record is not found..\n";
			return -1;
		}
}
int System::delete_user_model_details(string key)
{
		fstream file;
		int pos, flag=0;
		pos=search_user_model_details(key);
		if(pos>=0)
		{
			file.open("user_model_details.txt");
			file.seekp(pos,ios::beg);
			file.put('*');
			flag=1;
			file.close();
		}
		if(flag==1)
		return 1;
		else
		return 0;
}

void System::new_register_option()
{
	system("cls");
	ifstream ifile;
	fstream file; 
	char o;
			gotoxy(0,3);
	        cout<<"Registration Sucessfull";
	        gotoxy(2,5);
	    	cout<<" -----To Select the Vehicle Press V ------ ";
	    	cin>>o;
	    	if(o=='v'|| o=='V')
	    	{
			    ifstream MyFile("vehiclemodel.txt");
				char ch;
			
				while(!MyFile.eof())
				{
					MyFile.get (ch);
					cout<<ch;
				}
				MyFile.close();
				 /*std::ifstream f("vehiclemodel.txt");

    			if (f.is_open())
        		std::cout << f.rdbuf();*/
			}
			
			
        cout<<"\n\nEnter the vehicle Number to know more details:";
		cin>>vehicle_no;
		switch(vehicle_no)
		{
			
		
		case 1:
				{
					system("cls");
					ifstream MyFile("1.txt");
					char ch;
			
					while(!MyFile.eof())
					{
						MyFile.get (ch);
						cout<<ch;
					}
					MyFile.close();
					gotoxy(25,20);
					cout<<"Select vehicle 1(if yes press Y)";
					cin>>ch;
					if(ch=='y'|| ch=='Y')
					{
						
						modelno="1";
						pack_user_model_details();
						gotoxy(25,16);
						cout<<"Your Registration Details has been Recorded";
							Sleep(1000);
						main_menu();	
						/*buffer3.erase();
					
						buffer3+=User_Name+"|"+first_Name+"|"+last_Name+"|"+ ph_no+"|"+modelno+"$"+"\n";
						
						file.open("user_model_details.txt",ios::out|ios::app);
							file<<buffer3<<endl;
								file.close();*/
											
		        		/*	ifstream ifile("model1.txt", ios::in); 
	  
	    				if (!ifile.is_open()) { 
	  						cout << "file not found"; 
	    					} 
	    				else { 
	    					ofstream ofile("userdetails.txt", ios::out | ios::app); 
						//ofstream ofile("userderails.txt",ios::app);
		        			ofile<<User_Name<<'|'<<ph_no<<'|'<<ifile.rdbuf()<<"$"<<endl;*/
	        	
	    
	    					} 
    				
	        		}
		
				break;
				
				case 2:
					{
								system("cls");
							ifstream MyFile("2.txt");
							char ch;
					
							while(!MyFile.eof())
							{
								MyFile.get (ch);
								cout<<ch;
							}
							MyFile.close();
							cout<<"\nSelect vehicle 1(if yes press Y)";
							cin>>ch;
							if(ch=='y'|| ch=='Y')
							{
							
									modelno="2";
										pack_user_model_details();
				        		gotoxy(25,16);
						cout<<"Your Registration Details has been Recorded";
			        			Sleep(1000);
								main_menu();
			    
			    					} 
		    				
			        		}
			        	break;
			        	
					
					case 3:
						{
								system("cls");
							ifstream MyFile("3.txt");
							char ch;
					
							while(!MyFile.eof())
							{
								MyFile.get (ch);
								cout<<ch;
							}
							MyFile.close();
							cout<<"\nSelect vehicle 1(if yes press Y)";
							cin>>ch;
							if(ch=='y'|| ch=='Y')
							{
							
				        		
									modelno="3";
									pack_user_model_details();
					        	gotoxy(25,16);
								cout<<"Your Registration Details has been Recorded";
									Sleep(1000);
									main_menu();
			    
			    					} 
		    				
			        		}
			        		break;
			        		
						
						case 4:
							{
									system("cls");
									ifstream MyFile("4.txt");
									char ch;
							
									while(!MyFile.eof())
									{
										MyFile.get (ch);
										cout<<ch;
									}
									MyFile.close();
									cout<<"\nSelect vehicle 1(if yes press Y)";
									cin>>ch;
									if(ch=='y'|| ch=='Y')
									{
									
									modelno="4";
										pack_user_model_details();
					    				gotoxy(25,16);
										cout<<"Your Registration Details has been Recorded";
											Sleep(1000);
											main_menu();
					    			} 
				    				
					        		}
							
							break;
							
							case 5:
								{
													system("cls");
									ifstream MyFile("5.txt");
									char ch;
							
									while(!MyFile.eof())
									{
										MyFile.get (ch);
										cout<<ch;
									}
									MyFile.close();
									cout<<"\nSelect vehicle 1(if yes press Y)";
									cin>>ch;
									if(ch=='y'|| ch=='Y')
									{
										
									modelno="5";
									pack_user_model_details();
									gotoxy(25,16);
									cout<<"Your Registration Details has been Recorded";
										Sleep(1000);
										main_menu();
					    
					    					} 
				    				
					        		}
								break;
								
								case 6:
									{
											system("cls");
										ifstream MyFile("6.txt");
										char ch;
								
										while(!MyFile.eof())
										{
											MyFile.get (ch);
											cout<<ch;
										}
										MyFile.close();
										cout<<"\nSelect vehicle 1(if yes press Y)";
										cin>>ch;
										if(ch=='y'|| ch=='Y')
										{
											
							        			
												modelno="6";
													pack_user_model_details();
						        		gotoxy(25,16);
											cout<<"Your Registration Details has been Recorded";
												Sleep(1000);
												main_menu();
						    
						    					} 
					    				
						        		}
									break;
							
						
	
	}
}
			

void System::unpack_vehicle()
{
	
	int ch=1,i=0;
	User_Name.erase();
	while(buffer3[i]!='|') 
	User_Name+=buffer3[i++];
	first_Name.erase();
	i++;
	while(buffer3[i]!='|')
	first_Name+=buffer3[i++];
	last_Name.erase();
	i++;
	while(buffer3[i]!='|') 
	last_Name+=buffer3[i++];
	ph_no.erase();
	i++;
	while(buffer3[i]!='|') 
	ph_no+=buffer3[i++];
	modelno.erase();
	i++;
	while(buffer3[i]!='$') 
	modelno+=buffer3[i++];
		
}
void System::search_vehicle_detail(string key)
{
	
	ifstream file;
	int flag=0,pos=0;
	file.open("user_model_details.txt",ios::in);
	while(!file.eof())
	{
		 buffer3.erase();
		 pos=file.tellg(); 
		 getline(file,buffer3);
		 unpack_vehicle();
		 if(key==User_Name && modelno=="1")
		 	{
		 		system("cls");
		 		ifstream MyFile("model1.txt");
					char ch;
			
					while(!MyFile.eof())
					{
						
						MyFile.get (ch);
						cout<<ch;
					}
					MyFile.close();	
			 //cout<<"\nfound the key .the record is...\n"<<modelno;
			 //return pos;
			 //flag=1;
			}
		 if(key==User_Name && modelno=="2")
		{
			ifstream MyFile("model2.txt");
					char ch;
			
					while(!MyFile.eof())
					{
						MyFile.get (ch);
						cout<<ch;
					}
					MyFile.close();	
			 //cout<<"\nfound the key .the record is...\n"<<modelno;
			 //return pos;
			 flag=1;
		}
		 if(key==User_Name && modelno=="3")
		{
			ifstream MyFile("model3.txt");
					char ch;
			
					while(!MyFile.eof())
					{
						MyFile.get (ch);
						cout<<ch;
					}
					MyFile.close();	
			 //cout<<"\nfound the key .the record is...\n"<<modelno;
			 //return pos;
			 flag=1;
		}
		 if(key==User_Name && modelno=="4")
		{
			ifstream MyFile("model4.txt");
					char ch;
			
					while(!MyFile.eof())
					{
						MyFile.get (ch);
						cout<<ch;
					}
					MyFile.close();	
			 //cout<<"\nfound the key .the record is...\n"<<modelno;
			 //return pos;
			 flag=1;
		}
		if(key==User_Name && modelno=="5")
		{
			ifstream MyFile("model5.txt");
					char ch;
			
					while(!MyFile.eof())
					{
						MyFile.get (ch);
						cout<<ch;
					}
					MyFile.close();	
			 //cout<<"\nfound the key .the record is...\n"<<modelno;
			// return pos;
			 flag=1;
		}
		if(key==User_Name && modelno=="6")
		{
			ifstream MyFile("model6.txt");
					char ch;
			
					while(!MyFile.eof())
					{
						MyFile.get (ch);
						cout<<ch;
					}
					MyFile.close();	
			 //cout<<"\nfound the key .the record is...\n"<<modelno;
			 //return pos;
			 flag=1;
		}
	/*	else
		{
			cout<<"\nInformation could not find at the moment\n";
		}*/
	}
		file.close();
		if(flag==0)
		{
			cout<<"\nnot found..\n";
			
		}
}


int main(int argc, char** argv) 
{
	scroll_note();
	System s;
	s.main_menu();
	return 0;
}
