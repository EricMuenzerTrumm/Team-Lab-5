/***********************************************************************************
Header:
************************************************************************************
Author: Withheld
Organization: Withheld
File Name: Main.cpp
Date Created: May 18, 2018
Modifications: 05-22-18 12:00
***********************************************************************************

***********************************************************************************
Documentation:
***********************************************************************************
Lab Assignment: Lab 5 - Structured Files (Group)

Abstract: This program reads and writes structures to a file.

Input: Cstrings, Integers

Output: Write to File
***********************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ios;
using std::fixed;
using std::setw;
using std::setprecision;
using std::string;

// Structures
struct Account
{
	char name[32]; // Name
	char address[48]; // Address
	char city_state_zip[48]; // City, State, and ZIP
	char phone_number[16]; // Phone Number
	float balance; // Balance
	char last_payment_date[16]; // Last Payment Date
};

// Prototypes
void Menu();
void DisplayFile();
void AddRecord();
//void ChangeRecord();
//void DeleteRecord();
//void DisplayRecord();

// Main function
int main()
{
	Menu();

	system("pause");
	return 0;
}


// Menu function
void Menu()
{
	bool repeat = true, valid = true;
	unsigned short choice = 0;

	do // Repeat menu selection until user specifies.
	{
		do // Repeat while user choice is invalid.
		{
			valid = true;
			cout << endl << "--------------------------------------------------------" << endl;
			cout << "Menu:" << endl;
			cout << "--------------------------------------------------------" << endl;
			cout << "1: View All Records" << endl;
			cout << "2: View One Record" << endl;
			cout << "3: Add a Record" << endl;
			cout << "4: Delete a Record" << endl;
			cout << "5: Change a Record" << endl;
			cout << "6: Exit Program" << endl;
			cout << "--------------------------------------------------------" << endl;
			cout << endl << "Please select what you would like to do: ";
			cin >> choice;

			if (choice < 1 || choice > 6)
			{
				valid = false;
				cout << "Error: entry out of bounds, valid options are 1 - 6." << endl;
			}
		} while (!valid);

		switch (choice)
		{
		case 1:
			{
				DisplayFile();
				break;
			}
			
		case 2:
			{
				//DisplayRecord();
				break;
			}

		case 3:
			{
				AddRecord();
				break;
			}

		case 4:
			{
				//DeleteRecord();
				break;
			}

		case 5:
			{
				//ChangeRecord();
				break;
			}

		case 6:
			{
				cout << "Exiting program..." << endl;
				exit(EXIT_SUCCESS);
				break;
			}

		default:
			{
				cout << "Error: menu encountered invalid option." << endl;
				exit(EXIT_FAILURE);
				return;
			}
		}
	} while (repeat);
}


// DisplayFile function
void DisplayFile()
{
	int counter = 0;
	Account acc;
	fstream file;

	file.open("Database.dat", ios::in | ios::app | ios::binary); // Open file in read only mode.

	cout << endl << "--------------------------------------------------------" << endl;
	cout << "Database:" << endl;
	cout << "--------------------------------------------------------" << endl << endl;

	file.clear();
	file.seekg(0L, ios::beg); // Go to beggining of file.

	while (file) // While there is still something to read.
	{
		file.read(reinterpret_cast<char *>(&acc), sizeof(acc)); // Read the current structure in the file and place data into acc structure.

		if (file.tellg() < 0) // If file pointer goes to -1
		{
			break; // Exit loop to prevent duplicate output.
		}

		if (static_cast<string>(acc.name) != "null") // While deleted data is not found, display patch.
		{
			cout << "--------------------------------------------------------" << endl;
			cout << "Entry " << (counter + 1) << ": " << endl;
			cout << "--------------------------------------------------------" << endl;
			cout << "Name: " << acc.name << endl;
			cout << "Address: " << acc.address << endl;
			cout << "City, State, and ZIP: " << acc.city_state_zip << endl;
			cout << "Phone Number: " << acc.phone_number << endl;
			cout << "Accunt Balance: " << acc.balance << endl;
			cout << "Last Payment Date: " << acc.last_payment_date << endl;
			cout << "--------------------------------------------------------" << endl << endl;

			counter++;

			file.seekg(counter * sizeof(acc), ios::beg); // Go to file position (beggining + counter) and repeat.
		}

		else // If deleted data is found, do not display deleted patch.
		{
			counter++;
		}
	}
	file.close();
}

// AddRecord function
void AddRecord()
{
	bool replaced = false, valid = true;
	int counter = 0;
	Account read, write;
	fstream file;

	file.open("Database.dat", ios::in | ios::out | ios::ate | ios::binary); // Open the file in read and write mode.

	cout << "Please enter a Name: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(write.name, 32);

	cout << "Please enter a Address: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(write.address, 48);

	cout << "Please enter a City, State, and ZIP: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(write.city_state_zip, 48);

	cout << "Please enter a Phone Number: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(write.phone_number, 16);

	do // While choice is invalid
	{
		cout << "Please enter a Balance: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> write.balance;

		if (write.balance < 0 || write.balance > 4096000)
		{
			valid = false;
			cout << "Error: entry out of bounds, valid options are 0 - 4,096,000." << endl;
		}

	} while (!valid);

	cout << "Please enter a Last Payment Date: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(write.last_payment_date, 16);

	file.seekg(0L, ios::beg);

	while (file) // While there is still something to read.
	{
		file.read(reinterpret_cast<char *>(&read), sizeof(read)); // Read the current structure in the file and place data into read structure.

		if (file.tellg() < 0) // If file pointer goes to -1
		{
			break; // Exit loop to prevent duplicate output.
		}
		
		if (static_cast<string>(read.name) == "null") // If search encounters deleted data.
		{
			replaced = true;
			cout << counter * sizeof(write) << endl;
			file.seekg(counter * sizeof(write), ios::beg); // Go to file position (beggining + counter).
			file.write(reinterpret_cast<char *>(&write), sizeof(write)); // Overwrite old null data with new data
			break;
		}

		counter++;
	}

	if (!replaced) // If no null data was replaced, append to end of file.
	{
		file.clear();
		file.seekg(0L, ios::end);
		file.write(reinterpret_cast<char *>(&write), sizeof(write));
	}
}

/**********************************************************************************
Output:
***********************************************************************************



***********************************************************************************/
