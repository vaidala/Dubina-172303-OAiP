
#include <iostream>
#include "Struct.h"

using namespace std;

	int main()
	{
		int s;
		while (true) {
			cout << '\t' << "Choose the action: " << endl;
			cout << '\t' << "1 - Create the file" << '\n' << '\t' << "2 - Enter the data" << '\n' << '\t' << "3 - Print the data" << '\n' << '\t' << "4 - Add a log" << '\n' << '\t' << "5 - Change a log" << '\n' << '\t' << "6 - Delete a log" << '\n' << '\t' << "7 - Find a log" << '\n' << '\t' << "8 - Sort the data" << '\n' << '\t' << "0 - Exit" << endl;
			cin >> s;
			switch (s) {
			case 1:
				CreateFile();
				system("pause");
				system("cls");
				break;
			case 2:
				DataEntry();
				system("pause");
				system("cls");
				break;
			case 3:
				Print();
				system("pause");
				system("cls");
				break;
			case 4:
				AddData();
				system("pause");
				system("cls");
				break;
			case 5:
				DataChange();
				system("pause");
				system("cls");
				break;
			case 6:
				DeleteData();
				system("pause");
				system("cls");
				break;
			case 7:
				FindLog();
				system("pause");
				system("cls");
				break;
			case 8:
				Sort();
				system("pause");
				system("cls");
				break;
			case 0:
				exit(1);
			}
		}
}