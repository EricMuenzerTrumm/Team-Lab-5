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
	char name[32]; //Name
	char address[48]; //Address
	char city_state_zip[48]; //City, State, and ZIP
	char phone_number[16]; //Phone Number
	float balance; //Balance
	char last_payment_date[16]; //Last Payment Date
};

// Prototypes
void Menu();
void DisplayFile();
void AddRecord();
void ChangeRecord();
void DeleteRecord();
void DisplayRecord();

// Main function
int main()
{
	Menu();

	system("pause");
	return 0;
}

/**********************************************************************************
Output:
***********************************************************************************



***********************************************************************************/
