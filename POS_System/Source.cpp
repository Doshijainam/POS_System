// POS System 


#include<iostream>

#include<fstream>
#define DISCOUNT 10 
#include <ctime>



using namespace std;
class POS_System {
	

	string product; 
	float price;
public : 
	string firstname, lastname, email;
	long int contact;
	void create_Product() {

		cout << "Product name:"<<endl; 
		cin >> product; 

		cout << product << "'s price:" << endl; 
		cin >> price; 

		ofstream myfile;
		myfile.open("ProductList.txt",fstream::app);

		myfile << "Product Name: " << product << endl;
		myfile << "Product Price: " << price << endl;
		myfile << endl;

		myfile.close();
	}
};

class customerRecords :public POS_System
{
public : 

	void customerDetails()
	{
		ofstream customerdetails;
		customerdetails.open("CustomerRecords.txt", fstream::app);

		cout << "First Name: " << endl;
		cin >> firstname;

		cout << "Last Name: " << endl;
		cin >> lastname;

		cout << "Email Id: " << endl;
		cin >> email;

		cout << "Phone Number: " << endl;
		cin >> contact;

		customerdetails << "First Name: " << firstname << endl;
		customerdetails << "Last Name: " << lastname << endl;
		customerdetails << "Email Id: " << email << endl;
		customerdetails << "Phone Number: " << contact << endl;
		customerdetails << endl;

		customerdetails.close();
	}

	
};
// jignesh patel 


class Employee: public POS_System {
public : 

	
	string sinNumber; 

	void create_Product() {

		cout << "Employee's first Name :" << endl;
		cin >>firstname ;
		cout << "Employee's last Name : "<<endl; 

		cin >> lastname; 
		


		cout << "Employee's Sin number " <<   endl;
		cin >>sinNumber;
	     
		ofstream EmployeeRecord;
		EmployeeRecord.open("ProductList.txt", fstream::app);

		EmployeeRecord << "Employee's  first Name: " << firstname << endl;
		EmployeeRecord << "Employee's  last Name " << lastname << endl;
		EmployeeRecord<< "Employee's sinNumber : " << sinNumber << endl;
		// myfile << "Product Price: " << lastname << endl;
		

		EmployeeRecord.close(); 

	}


	


};
class TimeShark : public Employee ,POS_System{
	double clock_in; 
	double clock_out; 
public: 
	void clock_in() {
		time_t now = time(0);
		char* date = ctime(&now);
		
		cout << "You have clocked in for shift on " <<date << "at" << now << endl;
		clock_in = now; 


	}

	void clock_out() {
		time_t now = time(0);
		char* date = ctime(&now);

		cout << "You have clocked out for shift on " << date << "at" << now << endl;
		clock_out = now;


	}

	
		// calculate the time for which employee has worked 
		// what is the pay of that employee 
		/* this can be calculated by making some sort of list where specific groups of people will get specific pay
		 according to the pay contract */


     
};
int main()
{
	
	POS_System p;
	p.create_Product();
	p.create_Product(); 


}