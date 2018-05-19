void DisplayFile()
{
	int counter = 0;
	Employee emp;
	fstream file;

	file.open("Database.dat", ios::in || ios::binary);

	cout << endl << "--------------------------------------------------------" << endl;
	cout << "Database:" << endl;
	cout << "--------------------------------------------------------" << endl << endl;

	while (!EOF)
	{
		file.read(reinterpret_cast<char *>(&emp), sizeof(emp));

		cout << "--------------------------------------------------------" << endl;
		cout << "Entry " << (counter + 1) << ": " << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "Name: " << emp.name << endl;
		cout << "Address: " << emp.address << endl;
		cout << "City, State, and ZIP: " << emp.city_state_zip << endl;
		cout << "Phone Number: " << emp.phone_number << endl;
		cout << "Accunt Balance: " << emp.balance << endl;
		cout << "Last Payment Date: " << emp.last_payment_date << endl;
		cout << "--------------------------------------------------------" << endl << endl;

		counter++;
	}
}
