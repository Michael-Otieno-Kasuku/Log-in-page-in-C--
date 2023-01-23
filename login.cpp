#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){
	int c;
	cout<<"\t\t\t---------------------------------------------\n\n\n";
	cout<<"\t\t\t                Welcome to the login page    \n\n\n";
	cout<<"\t\t\t---------------------MENU---------------------\n\n";
	cout<<"                                                     \n\n";
	cout<<"\t|Press 1 to LOGIN                                            |"<<endl;
	cout<<"\t|Press 2 to REGISTER                                         |"<<endl;
	cout<<"\t|Press 3 if you forgot your PASSWORD                         |"<<endl;
	cout<<"\t|Press 4 to EXIT                                             |"<<endl;
	cout<<"\n\t\t\tPlease enter your choice: ";
	cin>>c;
	cout<<endl;
	switch(c){
		case 1:
			login();
			break;
		case 2:
			registration();
			break;
	    case 3:
	    	forgot();
	    	break;
	    case 4:
	    	cout<<"\t\t\t\t Thank you! \n\n";
	    	break;
	    default:
	    	system("CLS");
	    	cout<<"Please select from the options given above \n"<<endl;
	    	main();
	}
}
void login(){
	int count;
	string userId, password, id, pass;
	system("CLS");
	cout<<"\t\t\tPlease enter the user name and password : "<<endl;
	cout<<"\t\t\tUSERNAME ";
	cin>>userId;
	cout<<"PASSWORD ";
	cin>>password;
	
	ifstream input("record.txt");//ifstream is for reading the data
	while(input>>id>>pass){
		if(id==userId&&pass==password){
			count = 1;
			system("CLS");
		}
	}
	input.close();
	if(count==1){
		cout<<userId<<"\n Your login is successful thanks for logging in! \n";
		main();
	}
	else{
		cout<<"LOG IN ERROR\n Please check your user name and password";
		main();
	}
}

void registration(){
	string ruserId, rpassword,rid, rpass;
	system("CLS");
	cout<<"Enter the user name: ";
	cin>>ruserId;
	cout<<"Enter the password: ";
	cin>>rpassword;
	
	ofstream f1("records.txt",ios::app);//ofstream helps to write inside the file
	f1<<ruserId<<rpassword<<endl;
	system("CLS");
	cout<<"\t\t\t\tRegistration is successful";
	main();
}

void forgot(){
	int option;
	system("CLS");
	cout<<"\t\t\tYou forgot the password no worries \n";
	cout<<"Press 1 to search your id by username "<<endl;
	cout<<"Press 2 to go back to the main menu"<<endl;
	cout<<"\t\t\tEnter your choice";
	cin>>option;
	switch(option){
		case 1:{
			int count=0;
			string suserid, sid, spass;
			cout<<"\n\t\t\tEnter the user name which you remembered: ";
			cin>>suserid;
			
			ifstream f2("records.txt");
			while(f2>>sid>>spass){
				if(sid==suserid){
					count=1;
				}
			}
			f2.close();
			if(count==1){
				cout<<"\n\nYour account is found\n";
				cout<<"Your password is : "<<spass;
			}
			else{
				cout<<"\n\tSorry your account is not found!\n";
				main();
			}
			break;
		}
	   case 2:{
	   	main();
		break;
	   }
	   default:
	   	cout<<"\t\t\tWrong choice please try again "<<endl;
	   	forgot();
	}
}
