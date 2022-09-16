// POS System 

#include<iostream>
#include<fstream>
#define DISCOUNT 10 

using namespace std;
class POS_System {
	

	string product; 
	float price; 
public : 
	void create_Product() {

		cout << "Product name:"<<endl; 
		cin >> product; 

		cout << product << "'s price:" << endl; 
		cin >> price; 

		ofstream Productlist;
		
		Productlist.open("Productrecords.txt"); 
		Productlist << "Product name: " << product << endl; 
		Productlist << product << "'s price: " << price << endl;

		Productlist.close();

	}

};
int main()
{
	
	POS_System p;
	p.create_Product();
	p.create_Product(); 


}