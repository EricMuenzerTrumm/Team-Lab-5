void AddRecord()
{
	bool replaced = false, valid = true;
	int counter = 0;
	Account read, write;
	fstream file;

	file.open("Database.dat", ios::in | ios::out | ios::ate | ios::binary); //Open the file in read and write mode.

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

	do //While choice is invalid
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

	while (file) //While there is still something to read.
	{
		file.read(reinterpret_cast<char *>(&read), sizeof(read)); //Read the current structure in the file and place data into read structure.

		if (file.tellg() < 0) //If file pointer goes to -1
		{
			break; //Exit loop to prevent duplicate output.
		}
		
		if (static_cast<string>(read.name) == "null") //If search encounters deleted data.
		{
			replaced = true;
			cout << counter * sizeof(write) << endl;
			file.seekg(counter * sizeof(write), ios::beg); //Go to file position (beggining + counter).
			file.write(reinterpret_cast<char *>(&write), sizeof(write)); //Overwrite old null data with new data
			break;
		}

		counter++;
	}

	if (!replaced) //If no null data was replaced, append to end of file.
	{
		file.clear();
		file.seekg(0L, ios::end);
		file.write(reinterpret_cast<char *>(&write), sizeof(write));
	}
}
