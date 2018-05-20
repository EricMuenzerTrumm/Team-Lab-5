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
