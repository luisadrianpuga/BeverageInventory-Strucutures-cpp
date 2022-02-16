//Luis Puga
// December 5, 2021
// This Program calculates inventory profit, needed restock amoungs, and value of inevebtory

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

//Constants
const double TAX = 0.06;//sales tax
const double PRICE = .73;//Wholesale price per beverage
const int SIZE = 24; //MAX Size of Name and MIN inventory to be stored
const int NAMESIZE = 50; //holdd name




//Structure to Hold Following Items
struct Kiosk {
	char name[SIZE] = "none";
	int numBeverages = 0;
	double inventory = 0;
	bool restock = false;

};




void welcome();// Program title
void display(Kiosk* , int ); //Display the stuff

int main() {
	cout << setprecision(2) << fixed << showpoint;

	welcome();//Welcome User
	int number = 0; //Hold the number of beverages that need to be put in.
	Kiosk* stu = nullptr; 

	//Get number of beverages
	cout << "\nPlease enter the number of beverages: ";
	cin >> number;
	
	//TEST VALUE IS GREATER THAN 0
	while (number <= 0) {
		cout << "Error: Please enter a value greater than zero 0: " << endl;
		cout << "\nPlease enter the number of beverages: ";
		cin >> number;
	}
	stu = new Kiosk[number];

	//Get User Input
	for (int i = 0; i < number; i++) {

		cin.ignore();
		cout << "\nPlease enter the beverage name: ";	//Input the loads for each day
		cin.getline(stu[i].name, NAMESIZE);
		//validate input
		cout << "Please enter the number of bottles in invetory for " << stu[i].name << ": ";
		cin >> stu[i].numBeverages;
		while (stu[i].numBeverages <= 0) {
			cout << "Error: Please enter a value greater than zero 0: " << endl;
			cout << "Please enter the number of bottles in invetory for " << stu[i].name << ": ";
			cin >> stu[i].numBeverages;
		}
		//determine the cost of inventory
		stu[i].inventory = stu[i].numBeverages * PRICE;
		//determine if there is a restock needed
		if (stu[i].numBeverages < SIZE) {
			stu[i].restock = true;
		}
		else {
			stu[i].restock;
		}
	}

	display(stu, number);
	
	
	//Free allocated memory
	delete[] stu;
	stu = nullptr;
	//bye bye now
	cout << "\nThank you for using the food kiosk Profit Calculator. Goodbye!" << endl;
	
	return 0;
}

// Program title
void welcome() {

	cout << "CE - Structures\n";
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.\n\n";
	cout << right << setw(5) << "             Welcome to CMSY-141 Beverage Inventory Calculator" << right << endl;

}
//Display the contents of the array
void display(Kiosk * stu, int number){
	
	cout << "\nBeverage Inventory Calculator" << endl;
	cout << "          Inventory Report" << endl;
	for (int i = 0; i < number; i++) {
		//figure out beverage count
			int needed = (SIZE - stu[i].numBeverages);
			double cost = ((static_cast<double>(needed) * PRICE) * TAX) + static_cast<double>(needed);
		
			
		
		cout << "\n          Beverage Name: " << stu[i].name << endl; //name
		cout << "          Number in Inventory: " << stu[i].numBeverages << endl;//inventory
		cout <<"          Value of Inventory: $" << stu[i].inventory << endl;//inventory
	
		if (stu[i].restock == true){ // here we are showing how much is needed to set our bool to false

			cout << "          WARNING:Inventory is below one case. "<< endl;
			cout << "          You must order "<< needed << " more " << stu[i].name << endl;
			cout << setprecision(2) << fixed << showpoint;

			cout << "          The cost with tax will be:  $" << cost << endl;
		}
		 else{
				 cout << right << setw(24) << "          Inventory is greater than a case. No need to order additional " << stu[i].name << "." << endl;
		}
	}
	

}