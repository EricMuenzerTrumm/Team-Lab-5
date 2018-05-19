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
				DisplayRecord();
				break;
			}

		case 3:
			{
				AddRecord();
				break;
			}

		case 4:
			{
				DeleteRecord();
				break;
			}

		case 5:
			{
				ChangeRecord();
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
