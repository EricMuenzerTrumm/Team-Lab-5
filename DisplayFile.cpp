void DisplayFile()
{
	int counter = 0;
	Account acc;
	fstream file;

	file.open("Database.dat", ios::in || ios::binary);

	cout << endl << "--------------------------------------------------------" << endl;
	cout << "Database:" << endl;
	cout << "--------------------------------------------------------" << endl << endl;

	while (!EOF)
	{
		file.read(reinterpret_cast<char *>(&acc), sizeof(acc));

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
	}
}
