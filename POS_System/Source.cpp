// POS System 

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#define MIN_PAY 15
#define SUPERVISOR_PAY 18
#define MANAGER_PAY 25
#define DISCOUNT 10 
#include <ctime>



using namespace std;
class POS_System {
	
public : 
	string product;
	float price;
	string firstname, lastname, email;
	long int contact;
	void create_Product() {
		POS_System ps;

		cout << "Product name:"<<endl; 
		cin >> ps.product; 

		cout << product << "'s price:" << endl; 
		cin >> ps.price; 

		ofstream myfile;
		myfile.open("ProductList.txt",fstream::app);

		myfile << "Product Name: " << ps.product << endl;
		myfile << "Product Price: " << ps.price << endl;
		myfile << endl;

		myfile.close();
	}
};

class customerRecords :public POS_System
{
public : 

	void customerDetails()
	{
		customerRecords cr;
		ofstream customerdetails;
		customerdetails.open("CustomerRecords.txt", fstream::app);

		cout << "First Name: " << endl;
		cin >> cr.firstname;

		cout << "Last Name: " << endl;
		cin >> cr.lastname;

		cout << "Email Id: " << endl;
		cin >> cr.email;

		cout << "Phone Number: " << endl;
		cin >> cr.contact;

		customerdetails << "First Name: " << cr.firstname << endl;
		customerdetails << "Last Name: " << cr.lastname << endl;
		customerdetails << "Email Id: " << cr.email << endl;
		customerdetails << "Phone Number: " << cr.contact << endl;
		customerdetails << endl;

		customerdetails.close();
	}

	
};


class Employee: public POS_System {
public : 

	
	string sinNumber;
	int employee_number;

	void add_Employee() {
		Employee e;

		cout << "Employee's first Name :" << endl;
		cin >>e.firstname ;
		cout << "Employee's last Name : "<<endl; 
		cin >> e.lastname; 
		cout << "Employee's Sin number " <<   endl;
		cin >>e.sinNumber;
		cout << "\nGenerating Your Employee Number" << endl;
		e.employee_number = 1 + (rand() % 150);
		cout << "Your Employee Number is: " << e.employee_number<<endl;
	     
		ofstream EmployeeRecord;
		EmployeeRecord.open("ProductList.txt", fstream::app);

		EmployeeRecord << "Employee's  first Name: " << e.firstname << endl;
		EmployeeRecord << "Employee's  last Name " << e.lastname << endl;
		EmployeeRecord << "Employee's sinNumber : " << e.sinNumber << endl;
		EmployeeRecord << "Employee Number : " << e.employee_number << endl;
		

		EmployeeRecord.close(); 

	}


};
class TimeShark : public POS_System ,public Employee{
	 
public: 
	double punch_in;
	double punch_out;
	double pay, hours;
	double clock_in() {
		time_t now = time(0);
		char* date = ctime(&now);
		
		cout << "You have clocked in for shift on " <<date << "at" << now << endl;
		return punch_in = now; 
		

	}

	double clock_out() {
		time_t now = time(0);
		char* date = ctime(&now);

		cout << "You have clocked out for shift on " << date << "at" << now << endl;
		return punch_out = now;
		
	}

	void salary_calculator(int employee_id)
	{
		TimeShark t;
		t.punch_in = clock_in();
		t.punch_out = clock_out();
		employee_id = t.employee_number;
		t.hours = punch_out - punch_in;

		if (employee_id <= 50)
		{
			t.pay = hours * MIN_PAY;
		}
		else if (employee_id > 50 && employee_id <= 100)
		{
			t.pay = hours * SUPERVISOR_PAY;
		}
		else if(employee_id >100 && employee_id<=150)
		{
			t.pay = hours * MANAGER_PAY;
		}
		ofstream salary_chart;
		salary_chart.open("salaryChart.txt", fstream::app);

		salary_chart << "Employee ID: " << t.employee_number << endl;
		salary_chart << "Employee Name: " << t.firstname <<" " <<t.lastname<< endl;
		salary_chart << "Employee SIN: " << t.sinNumber << endl;
		salary_chart << "Employee Hours Worked: " << t.hours << endl;
		salary_chart << "Employee Pay: " << t.pay << endl;
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