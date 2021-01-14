
// Created by Leen Al-Hamdan on 09/01/2021.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Address.h"
#include "LinkedListRecords.h"
#include "LinkedListMotorcycles.h"

using namespace std;

void insertCustomer(Customer &customer);

void updateFile(LinkedListMotorcycles &motorcycles, LinkedListRecords &records);

void handOver(LinkedListRecords &records, LinkedListMotorcycles &motorcycles);

Record getRecordFromMotorcycle(Motorcycle motorcycle, LinkedListRecords &records);

Motorcycle getMotorcycleByName(LinkedListMotorcycles &motorcycles, string name);

void readFromFile(LinkedListMotorcycles &motorcycles, LinkedListRecords &records);

void defineAvailMotorcycle(string chooseString[], LinkedListMotorcycles &motorcycles);

int main() {
	int choice;

	LinkedListRecords records = LinkedListRecords();

	LinkedListMotorcycles motorcycles = LinkedListMotorcycles();//to set all motorcycle and define them avail

	readFromFile(motorcycles, records);     //get data from file

	//to make definition dynamic
	string chooseString[] = {"Choose motorcycle type: \n",
							 "1 for Suzuki Bandit, ",
							 "2 for Honda TransAlp, ",
							 "3 for BMW F 650GS, ",
							 "4 for Kawasaki ZZR1400, ",
							 "",//no motorcycles to hand over it in the begging
							 "or -1 to exit"};

	choosing:
	defineAvailMotorcycle(chooseString, motorcycles); //define available motorcycle

	if (chooseString[1] == ("") && chooseString[2] == "" && chooseString[3] == "" && chooseString[4] == "") {
		cout << "There is no avail motorcycles to reserved enter 5 to hand over a motorcycle -1 to exit" << endl;
	} else
		cout << chooseString[0] + chooseString[1] + chooseString[2] + chooseString[3] + chooseString[4] +
				chooseString[5] + chooseString[6] << endl; //to easily delete one of choices

	cin >> choice;

    while (!cin) // or if(cin.fail())
    {
        // user didn't input a number
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        // next, request user reinput
        cout << "Please Enter a valid choice:";
        cin >> choice;
    }
	//local variables
	Motorcycle motorcycle;
	string motorcycleName;

	switch (choice) {
		case 1:
			motorcycleName = "Suzuki Bandit";
			motorcycle = getMotorcycleByName(motorcycles, motorcycleName);

			if (!motorcycle.isBooked1()) {
				Customer customer;

				chooseString[5] = "5 for hand over a motorcycle";//add choice

				motorcycles.updateMotorcycle(motorcycleName); //reverse available value
				chooseString[1] = "";//remove it from options

				insertCustomer(customer);

				if (customer.getHasDriveLicence()) {
					if (records.isCustomerHasAlreadyReserved(customer)) {
						cout
								<< "This customer is already reserved a motorcycle,hand over reserved motorcycle before try to reserved another\n";
						chooseString[1] = "1 for Suzuki Bandit, ";//back it from options
						motorcycles.updateMotorcycle(motorcycleName); //reverse available value
						goto choosing;
					}
					records.insert(Record(motorcycle, customer));

					updateFile(motorcycles, records);

					cout<<motorcycleName<<" successfully reserved\n";
				} else {
					cout << "The reservation for this customer is canceled because he has no drive's license. \n";
					chooseString[1] = "1 for Suzuki Bandit, ";//back it from options
					motorcycles.updateMotorcycle(motorcycleName); //reverse available value
					updateFile(motorcycles, records);
				}
			} else cout << "Please choose one of avail motorcycles\n";
			goto choosing;
			break;
		case 2:
			motorcycleName = "Honda TransAlp";
			motorcycle = getMotorcycleByName(motorcycles, motorcycleName);
			if (!motorcycle.isBooked1()) {
				Customer customer;

				chooseString[5] = "5 for hand over a motorcycle";//add choice

				motorcycles.updateMotorcycle(motorcycleName); //reverse available value
				chooseString[2] = "";//remove it from options

				insertCustomer(customer);

				if (customer.getHasDriveLicence()) {
					if (records.isCustomerHasAlreadyReserved(customer)) //to make sure customer reserved only one at time
					{
						cout<< "This customer is already reserved a motorcycle,hand over reserved motorcycle before try to reserved another\n";
						chooseString[2] = "2 for Honda TransAlp, ";//back it from options
						motorcycles.updateMotorcycle(motorcycleName); //reverse available value
						goto choosing;
					}
					records.insert(Record(motorcycle, customer));

					updateFile(motorcycles, records);

				} else {
					cout << "The reservation for this customer is canceled because he has no drive's license. \n";
					chooseString[2] = "2 for Honda TransAlp, ";//back it from options
					motorcycles.updateMotorcycle(motorcycleName); //reverse available value
					updateFile(motorcycles, records);
				}
			} else cout << "Please choose one of avail motorcycles\n";
			goto choosing;
			break;
		case 3:
			motorcycleName = "BMW F 650GS";
			motorcycle = getMotorcycleByName(motorcycles, motorcycleName);
			if (!motorcycle.isBooked1()) {
				Customer customer;

				chooseString[5] = "5 for hand over a motorcycle";//add choice

				motorcycles.updateMotorcycle(motorcycleName); //reverse available value
				chooseString[3] = "";//remove it from options

				insertCustomer(customer);

				if (customer.getHasDriveLicence()) {
					if (records.isCustomerHasAlreadyReserved(customer)) {
						cout<< "This customer is already reserved a motorcycle,hand over reserved motorcycle before try to reserved another\n";
						chooseString[3] = "3 for BMW F 650GS, ";//back it from options
						motorcycles.updateMotorcycle(motorcycleName);//reverse available value
						goto choosing;
					}

					records.insert(Record(motorcycle, customer));

					updateFile(motorcycles, records);

				} else {
					cout << "The reservation for this customer is canceled because he has no drive's license. \n";
					chooseString[3] = "3 for BMW F 650GS, ";//back it from options
					motorcycles.updateMotorcycle(motorcycleName); //reverse available value
					updateFile(motorcycles, records);
				}
			} else cout << "Please choose one of avail motorcycles\n";
			goto choosing;
			break;
		case 4:
			motorcycleName = "Kawasaki ZZR1400";
			motorcycle = getMotorcycleByName(motorcycles, motorcycleName);
			if (!motorcycle.isBooked1()) {
				Customer customer;

				chooseString[5] = "5 for hand over a motorcycle";//add choice

				motorcycles.updateMotorcycle(motorcycleName); //reverse available value
				chooseString[4] = "";//remove it from options

				insertCustomer(customer);

				if (customer.getHasDriveLicence()) {
					if (records.isCustomerHasAlreadyReserved(customer)) {
						cout
								<< "This customer is already reserved a motorcycle,hand over reserved motorcycle before try to reserved another\n";
						chooseString[4] = "4 for Kawasaki ZZR1400, ";//back it from options
						motorcycles.updateMotorcycle(motorcycleName); //reverse available value
						goto choosing;
					}
					records.insert(Record(motorcycle, customer));

					updateFile(motorcycles, records);
				} else {
					cout << "The reservation for this customer is canceled because he has no drive's license. \n";
					chooseString[4] = "4 for Kawasaki ZZR1400, ";//back it from options
					motorcycles.updateMotorcycle(motorcycleName); //reverse available value
					updateFile(motorcycles, records);
				}
			} else cout << "Please choose one of avail motorcycles\n";
			goto choosing;
			break;
		case 5:
			handOver(records, motorcycles);
			goto choosing;
			break;
		case -1:
			goto after;
			break;
		default:
			cout << "please enter valid choice\n \n";
			goto choosing;
			break;
	}

	after:
	return 0;
}

void insertCustomer(Customer &customer) {
	string surName, firstName, telephoneNumber, city, street;
	int yearOfBirth, number;
	bool hasDriveLicence;
	long postcode;
	Address address;

	cout << "Enter customer surName:";
	cin.ignore();//to not confuse between cin and getLine(cin)
	getline(cin, surName);

	cout << "Enter customer first name:";
	getline(cin, firstName);

	cout << "Enter Address information:" << endl;
	cout << "Enter street name:";
	getline(cin, street);

	cout << "Enter street number:";
	cin >> number;
	while (!cin) // or if(cin.fail())
	{
		// user didn't input a number
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		// next, request user reinput
		cout << "Please Enter a valid street number:";
		cin >> number;
	}

	cout << "Enter postcode number:";
	cin >> postcode;
	while (!cin) // or if(cin.fail())
	{
		// user didn't input a number
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		// next, request user reinput
		cout << "Please Enter a valid postcode number:";
		cin >> postcode;
	}

	cout << "Enter city:   ";
	cin.ignore();//to not confuse between cin and getLine(cin)
	getline(cin, city);
	address = Address(street, number, city, postcode);

	cout << "Enter year of birth:";
	cin >> yearOfBirth;
	while (!cin) // or if(cin.fail())
	{
		// user didn't input a number
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		// next, request user reinput
		cout << "Please Enter a valid year of birth:";
		cin >> yearOfBirth;
	}

	cout << "Enter telephone number:";
	cin >> telephoneNumber;
	while (!cin) // or if(cin.fail())
	{
		// user didn't input a number
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		// next, request user reinput
		cout << "Please Enter a valid telephone number:";
		cin >> telephoneNumber;
	}

	ll:
	cout << "Does he have a driving license?"<<endl<<" 1 for yes 0 for no:";
	int x;
	cin >> x;
	if (x == -1)
		return;
	if (x == 0) hasDriveLicence = false;
	else if (x == 1) {

		cout << "Enter driving license class:";
		char licenceClass;
		cin >> licenceClass;
		hasDriveLicence = tolower(licenceClass) == 'a';
	} else {
		cout << "Please enter 0 or 1 only or -1 to exit\n";
		goto ll;
	}
	customer = Customer(surName, firstName, yearOfBirth, telephoneNumber, hasDriveLicence, address);

}

void updateFile(LinkedListMotorcycles &motorcycles, LinkedListRecords &records) {
	ofstream data;
	data.open("reservierungen.txt", ios::out);

	MotorcycleNode *currNode = motorcycles.getHead();
	for (int i = 0; i < motorcycles.getSize(); i++) {
		if (currNode->motorcycle.isBooked1()) {
			Record record = getRecordFromMotorcycle(currNode->motorcycle, records);
			data << currNode->motorcycle.getMotorcycleName() << endl
				 << "status:" << "reserved"
				 << "\nCustomer surname: " << record.getCustomer().getSurName()
				 << "\nCustomer first name: " << record.getCustomer().getFirstName()
				 << "\nCustomer telephone number: " << record.getCustomer().getTelephneNumber()
				 << "\nStreet name: " << record.getCustomer().getAdress().getStreet()
				 << "\nStreet number: " << record.getCustomer().getAdress().getNumber()
				 << "\nPostcode number: " << record.getCustomer().getAdress().getPostcode()
				 << "\nCity: " << record.getCustomer().getAdress().getCity()
				 << "\nCustomer year of birth: " << record.getCustomer().getYearOfBirth() << endl;
		} else
			data << currNode->motorcycle.getMotorcycleName() << endl
				 << "status: " << "not reserved\n";

		currNode = currNode->next;
	}

	data.close();
}

void readFromFile(LinkedListMotorcycles &motorcycles, LinkedListRecords &records) {
	ifstream data;
	data.open("reservierungen.txt", ios::in);

	if (!data)//if file does not exist
	{
		data.close();//close file to open it as outputFile
		ofstream print;
		print.open("reservierungen.txt", ios::out);
		print << "Suzuki Bandit" << endl << "status: " << "not reserved\n";
		print << "Honda TransAlp" << endl << "status: " << "not reserved\n";
		print << "BMW F 650GS" << endl << "status: " << "not reserved\n";
		print << "Kawasaki ZZR1400" << endl << "status: " << "not reserved\n";
		print.close();
		data.open("reservierungen.txt", ios::in);
	}

	string motorcycleName;
	while (getline(data, motorcycleName)) {
		{
			string statusWithTitle;
			getline(data, statusWithTitle);

			string status = statusWithTitle.substr((statusWithTitle.find(":")) + 1);
			if (status == "reserved") {
				Motorcycle motorcycle = Motorcycle(motorcycleName, true);
				motorcycles.insert(motorcycle);

				string surnameWithTitle, firstNameWithTitle, telephoneNumberWithTitle, streetNameWithTitle, streetNumberWithTitle, postcodeWithTitle, cityWithTitle, birthYearWithTitle;

				getline(data, surnameWithTitle);
				string surname = surnameWithTitle.substr((surnameWithTitle.find(":")) + 2);

				getline(data, firstNameWithTitle);
				string firstName = firstNameWithTitle.substr((firstNameWithTitle.find(":")) + 2);

				getline(data, telephoneNumberWithTitle);
				string telephoneNumber = telephoneNumberWithTitle.substr((telephoneNumberWithTitle.find(":")) + 2);

				getline(data, streetNameWithTitle);
				string streetName = streetNameWithTitle.substr((streetNameWithTitle.find(":")) + 2);

				getline(data, streetNumberWithTitle);
				string streetNumber = streetNumberWithTitle.substr((streetNumberWithTitle.find(":")) + 2);

				getline(data, postcodeWithTitle);
				string postcode = postcodeWithTitle.substr((postcodeWithTitle.find(": ")) + 2);

				getline(data, cityWithTitle);
				string city = cityWithTitle.substr((cityWithTitle.find(": ")) + 2);

				Address address = Address(streetName, stoi(streetNumber), city, stol(postcode));

				getline(data, birthYearWithTitle);
				string birthYear = birthYearWithTitle.substr((birthYearWithTitle.find(": ")) + 2);

				Customer customer = Customer(surname, firstName, stoi(birthYear), telephoneNumber, true, address);

				records.insert(Record(motorcycle, customer));
			} else {
				motorcycles.insert(Motorcycle(motorcycleName, false));
			}
		}
	}
	data.close();
}

void handOver(LinkedListRecords &records, LinkedListMotorcycles &motorcycles)
{
	string firstName, surname;
	tryAgain:
	cout << "Enter the customer surname:";
	cin >> surname;
	cout << "Enter the customer first name:";
	cin >> firstName;


	RecordNode *currNode = records.getHead();
	for (int i = 0; i < records.getSize(); i++) {
		if ((currNode->record).getCustomer().getFirstName() == firstName &&
			(currNode->record).getCustomer().getSurName() == surname) {
			records.remove(currNode);//the index of node that we need to remove it
			motorcycles.updateMotorcycle((currNode->record).getMotorcycle().getMotorcycleName()); //reverse available value
			updateFile(motorcycles, records);
			cout<<"Hand over Successfully"<<endl;
			return;
		}
		currNode = currNode->next;
	}
	cout << "There is no reserved motorcycles by this customer, enter 1 to try again or any key to exit" << endl;
	int n;
	cin >> n;
	if (n == 1)
		goto tryAgain;
	else return;
}

Record getRecordFromMotorcycle(Motorcycle motorcycle, LinkedListRecords &records) {
	RecordNode *currNode = records.getHead();
	for (int i = 0; i < records.getSize(); i++) {
		if ((currNode->record).getMotorcycle() == motorcycle)
			return (currNode->record);
		currNode = currNode->next;
	}
	return Record();
}

Motorcycle getMotorcycleByName(LinkedListMotorcycles &motorcycles, string name) {
	MotorcycleNode *currNode = motorcycles.getHead();
	for (int i = 0; i < motorcycles.getSize(); i++) {
		if ((currNode->motorcycle).getMotorcycleName() == name)
			return (currNode->motorcycle);
		currNode = currNode->next;
	}
	/*if (motorcycle.getMotorcycleName() == name)
		return motorcycle;*/
	return Motorcycle();
}

void defineAvailMotorcycle(string chooseString[], LinkedListMotorcycles &motorcycles)
{
    chooseString[5] = "";

    if (getMotorcycleByName(motorcycles, "Suzuki Bandit").isBooked1()) {
		chooseString[1] = "";
		chooseString[5] = "5 for hand over a motorcycle";//add choice
	} else if(!getMotorcycleByName(motorcycles, "Suzuki Bandit").isBooked1())
    {
        chooseString[1] = "1 for Suzuki Bandit, ";
    }
	if (getMotorcycleByName(motorcycles, "Honda TransAlp").isBooked1()) {
		chooseString[2] = "";
		chooseString[5] = "5 for hand over a motorcycle";//add choice
	}else if(!getMotorcycleByName(motorcycles, "Honda TransAlp").isBooked1())
    {
        chooseString[2] = "2 for Honda TransAlp, ";
    }
	if (getMotorcycleByName(motorcycles, "BMW F 650GS").isBooked1()) {
		chooseString[3] = "";
		chooseString[5] = "5 for hand over a motorcycle";//add choice
	}else if(!getMotorcycleByName(motorcycles, "BMW F 650GS").isBooked1())
    {
        chooseString[3] = "3 for BMW F 650GS, ";
    }
	if (getMotorcycleByName(motorcycles, "Kawasaki ZZR1400").isBooked1()) //define available motorcycle
	{
		chooseString[4] = "";
		chooseString[5] = "5 for hand over a motorcycle";//add choice
	}else if(!getMotorcycleByName(motorcycles, "Kawasaki ZZR1400").isBooked1())
    {
        chooseString[4] = "4 for Kawasaki ZZR1400, ";
    }
}