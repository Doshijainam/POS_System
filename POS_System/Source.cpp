// POS System 

#include<iostream>
#include<fstream>
#define DISCOUNT 10 

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
int main()
{
	
	POS_System p;
	p.create_Product();
	p.create_Product(); 


}