#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include "Struct.h"

struct Patient
{
	char surname[40];
	char firstname[40];
	char patronymic[40];
	char address[80];
	int medicalcard;
	int insurance;
};
using namespace std;

extern void CreateFile()
{
	ofstream buf("Buffer.txt");
	if (!buf)
	{
		cout << "ERROR! The buffer file doesn't exist." << endl;
		exit(0);
	}
	buf.close();
}
extern void DataEntry()
{
	char surname[40], firstname[40], patronymic[40], address[80];
	int medicalcard, insurance;
	int n;

	cout << '\t' << "Input the number of logs: ";
	cin >> n;
	ofstream record("Buffer.txt", ios::app);

	if (record)
	{
		record << n << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "Input the surname: ";
			cin >> surname;
			cout << "Input the first name: ";
			cin >> firstname;
			cout << "Input the patronymic/matronymic: ";
			cin >> patronymic;
			cout << "Input the address: ";
			cin >> address;
			cout << "Input the medical card number: ";
			cin >> medicalcard;
			cout << "Input the insurance policy number: ";
			cin >> insurance;

			record << surname << endl;
			record << firstname << endl;
			record << patronymic << endl;
			record << address << endl;
			record << medicalcard << endl;
			if (i < n - 1)
				record << insurance << endl;
			else
				record << insurance;

			cout << "_______________________________" << '\n' << endl;
		}
	}
	else
	{
		cout << "ERROR! The file couldn't be accessed correctly.";
		record.close();
		exit(0);
	}
	record.close();
}
extern void Print()
{
	ifstream reading("Buffer.txt");

	if (reading)
	{
		char surname[40], firstname[40], patronymic[40], address[80];
		int medicalcard, insurance;
		int n;

		reading >> n;
		cout << "The number of logs: " << n << '\n' << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "Log #" << i + 1 << endl;
			reading >> surname >> firstname >> patronymic;
			cout << '\n' << "Name: " << surname << " " << firstname << " " << patronymic << endl;
			reading >> address;
			cout << '\n' << "Adress: " << address << endl;
			reading >> medicalcard;
			cout << "Medical card number: " << medicalcard << endl;
			reading >> insurance;
			cout << '\n' << "Insurance policy number: " << insurance << endl;
			cout << '\n' << "_________________________" << '\n' << endl;
		}
	}
	else
	{
		cout << "ERROR! The file couldn't be accessed correctly.";
		reading.close();
		exit(0);
	}
	reading.close();
}
static void Copy()
{
	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading) {
		if (record) {
			char surname[40], firstname[40], patronymic[40], address[80];
			int medicalcard, insurance; int n;
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> surname >> firstname >> patronymic;
				record << surname << endl;
				record << firstname << endl;
				record << patronymic << endl;
				reading >> address;
				record << address << endl;
				reading >> medicalcard >> insurance;
				record << medicalcard << endl;
				if (i < n - 1)
					record << insurance << endl;
				else
					record << insurance;
			}
		}
		else
		{
			cout << "ERROR! The file couldn't be accessed correctly.";
			reading.close();
			record.close();
			exit(0);
		}
	}
	else
	{
		cout << "ERROR! The file couldn't be accessed correctly.";
		reading.close();
		record.close();
		exit(0);
	}
	reading.close();
	record.close();
}
extern void DataChange()
{
	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			char surname[40], firstname[40], patronymic[40], address[80];
			int medicalcard, insurance;
			int n, n1;
			reading >> n;

			cout << "Choose the log number: ";
			cin >> n1;
			cout << '\n';
			n1--;

			record << n << endl;
			if (n1 >= 0 && n1 < n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i != n1) {
						reading >> surname >> firstname >> patronymic;
						record << surname << endl;
						record << firstname << endl;
						record << patronymic << endl;
						reading >> address;
						record << address << endl;
						reading >> medicalcard >> insurance;
						record << medicalcard << endl;
						if (i < n - 1)
							record << insurance << endl;
						else
							record << insurance;
					}
					else {
						cout << "Input the surname: ";
						cin >> surname;
						cout << "Input the first name: ";
						cin >> firstname;
						cout << "Input the patronymic/matronymic: ";
						cin >> patronymic;
						cout << "Input the address: ";
						cin >> address;
						cout << "Input the medical card number: ";
						cin >> medicalcard;
						cout << "Input the insurance policy number: ";
						cin >> insurance;

						record << surname << endl;
						record << firstname << endl;
						record << patronymic << endl;
						record << address << endl;
						record << medicalcard << endl;
						if (i < n - 1)
							record << insurance << endl;
						else
							record << insurance;

						reading >> surname >> firstname >> patronymic;
						reading >> address;
						reading >> medicalcard >> insurance;
					}
				}

				cout << '\n' << "The log has been changed." << '\n' << endl;
			}

			else {
				cout << "The entered log doesn't exist.";
				record.close();
				reading.close();
				exit(0);
			}
		}

		else {
			cout << "ERROR! The file couldn't be accessed correctly.";
			reading.close();
			record.close();
			exit(0);
		}
	}

	else {
		cout << "ERROR! The file couldn't be accessed correctly.";
		reading.close();
		record.close();
		exit(0);
	}

	record.close();
	reading.close();
	remove("Buffer_.txt");
}
extern void DeleteData()
{
	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			char surname[40], firstname[40], patronymic[40], address[80];
			int medicalcard, insurance;
			int n, n1;
			reading >> n;
			int f = n - 1;

			cout << "Choose the log number: ";
			cin >> n1;
			cout << '\n';
			n1--;

			record << f << endl;
			if (n1 >= 0 && n1 < n) {
				for (int i = 0; i < n; i++)
				{
					if (i != n1) {
						reading >> surname >> firstname >> patronymic;
						record << surname << endl;
						record << firstname << endl;
						record << patronymic << endl;
						reading >> address;
						record << address << endl;
						reading >> medicalcard >> insurance;
						record << medicalcard << endl;
						if (i < n - 1)
							record << insurance << endl;
						else
							record << insurance;
					}
					else {
						reading >> surname >> firstname >> patronymic;
						reading >> address;
						reading >> medicalcard >> insurance;
					}
				}
				cout << "The log has been deleted." << endl;
			}
			else {
				cout << "The entered log doesn't exist.";
				record.close();
				reading.close();
				exit(0);
			}
		}
		else {
			cout << "ERROR! The file couldn't be accessed correctly.";
			reading.close();
			record.close();
			exit(0);
		}
	}
	else {
		cout << "ERROR! The file couldn't be accessed correctly.";
		reading.close();
		record.close();
		exit(0);
	}
	record.close();
	reading.close();
	remove("Buffer_.txt");
}
extern void AddData()
{
	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			char surname[40], firstname[40], patronymic[40], address[80];
			int medicalcard, insurance;
			int n;
			reading >> n;
			int b = n + 1;

			record << b << endl;

			for (int i = 0; i < b; i++) {
				if (i < n) {
					reading >> surname >> firstname >> patronymic;
					record << surname << endl;
					record << firstname << endl;
					record << patronymic << endl;
					reading >> address;
					record << address << endl;
					reading >> medicalcard >> insurance;
					record << medicalcard << endl;
					if (i < n - 1)
						record << insurance << endl;
					else
						record << insurance;
				}
				else {
					cout << "Input the surname: ";
					cin >> surname;
					cout << "Input the first name: ";
					cin >> firstname;
					cout << "Input the patronymic/matronymic: ";
					cin >> patronymic;
					cout << "Input the address: ";
					cin >> address;
					cout << "Input the medical card number: ";
					cin >> medicalcard;
					cout << "Input the insurance policy number: ";
					cin >> insurance;

					record << surname << endl;
					record << firstname << endl;
					record << patronymic << endl;
					record << address << endl;
					record << medicalcard << endl;
					record << insurance << endl;
				}
			}
			cout << "The log has been added." << '\n' << endl;
		}
		else {
			cout << "ERROR! The file couldn't be accessed correctly.";
			reading.close();
			record.close();
			exit(0);
		}
	}
	else {
		cout << "ERROR! The file couldn't be accessed correctly.";
		reading.close();
		record.close();
		exit(0);
	}

	record.close();
	reading.close();
	remove("Buffer_.txt");

}
extern void FindLog()
{
	ifstream reading("Buffer.txt");
	Patient example[50];
	if (reading) {

		int n, s, count = 0;
		char searchtext[80];
		int searchnumber;

		reading >> n;

		for (int i = 0; i < n; i++) {
			reading >> example[i].surname;
			reading >> example[i].firstname;
			reading >> example[i].patronymic;
			reading >> example[i].address;
			reading >> example[i].medicalcard;
			reading >> example[i].insurance;
		}

		cout << '\t' << "Choose the parameter: " << endl;
		cout << '\t' << "1 - Surname" << '\n' << '\t' << "2 - First name" << '\n' << '\t' << "3 - Patronymic/matronymic " << '\n' << '\t' << "4 - Address" << '\n' << '\t' << "5 - Medical card number" << '\n' << '\t' << "6 - Insurance policy number" << '\n' << '\t' << "0 - Exit" << endl;
		cin >> s;
		switch (s) {

		case 1:
			cin.ignore();
			cout << "Input the sought-for surname: ";
			cin.getline(searchtext, 40);
			cout << '\n' << "_________________________" << '\n' << endl;

			for (int i = 0; i < n; i++)
			{
				if (strcmp(example[i].surname, searchtext) == 0)
				{
					cout << "Log #" << i + 1 << endl;
					cout << '\n' << "Name: " << example[i].surname << " " << example[i].firstname << " " << example[i].patronymic << endl;
					cout << '\n' << "Adress: " << example[i].address << endl;
					cout << "Medical card number: " << example[i].medicalcard << endl;
					cout << '\n' << "Insurance policy number: " << example[i].insurance << endl;
					cout << '\n' << "_________________________" << '\n' << endl;
					count++;
				}
			}
			if (count == 0)
				cout << "No matching logs have been found." << '\n' << endl;
			break;

		case 2:
			cin.ignore();
			cout << "Input the sought-for first name: ";
			cin.getline(searchtext, 40);
			cout << '\n' << "_________________________" << '\n' << endl;

			for (int i = 0; i < n; i++)
			{
				if (strcmp(example[i].firstname, searchtext) == 0)
				{
					cout << "Log #" << i + 1 << endl;
					cout << '\n' << "Name: " << example[i].surname << " " << example[i].firstname << " " << example[i].patronymic << endl;
					cout << '\n' << "Adress: " << example[i].address << endl;
					cout << "Medical card number: " << example[i].medicalcard << endl;
					cout << '\n' << "Insurance policy number: " << example[i].insurance << endl;
					cout << '\n' << "_________________________" << '\n' << endl;
					count++;
				}
			}
			if (count == 0)
				cout << "No matching logs have been found." << '\n' << endl;
			break;

		case 3:
			cin.ignore();
			cout << "Input the sought-for patronymic/matronymic: ";
			cin.getline(searchtext, 40);
			cout << '\n' << "_________________________" << '\n' << endl;

			for (int i = 0; i < n; i++)
			{
				if (strcmp(example[i].patronymic, searchtext) == 0)
				{
					cout << "Log #" << i + 1 << endl;
					cout << '\n' << "Name: " << example[i].surname << " " << example[i].firstname << " " << example[i].patronymic << endl;
					cout << '\n' << "Adress: " << example[i].address << endl;
					cout << "Medical card number: " << example[i].medicalcard << endl;
					cout << '\n' << "Insurance policy number: " << example[i].insurance << endl;
					cout << '\n' << "_________________________" << '\n' << endl;
					count++;
				}
			}
			if (count == 0)
				cout << "No matching logs have been found." << '\n' << endl;
			break;

		case 4:
			cin.ignore();
			cout << "Input the sought-for address: ";
			cin.getline(searchtext, 80);
			cout << '\n' << "_________________________" << '\n' << endl;

			for (int i = 0; i < n; i++)
			{
				if (strcmp(example[i].address, searchtext) == 0)
				{
					cout << "Log #" << i + 1 << endl;
					cout << '\n' << "Name: " << example[i].surname << " " << example[i].firstname << " " << example[i].patronymic << endl;
					cout << '\n' << "Adress: " << example[i].address << endl;
					cout << "Medical card number: " << example[i].medicalcard << endl;
					cout << '\n' << "Insurance policy number: " << example[i].insurance << endl;
					cout << '\n' << "_________________________" << '\n' << endl;
					count++;
				}
			}
			if (count == 0)
				cout << "No matching logs have been found." << '\n' << endl;
			break;
		case 5:
			cout << "Input the sought-for medical card number: ";
			cin >> searchnumber;
			cout << '\n' << "_________________________" << '\n' << endl;

			for (int i = 0; i < n; i++)
			{
				if (example[i].medicalcard == searchnumber)
				{
					cout << "Log #" << i + 1 << endl;
					cout << '\n' << "Name: " << example[i].surname << " " << example[i].firstname << " " << example[i].patronymic << endl;
					cout << '\n' << "Adress: " << example[i].address << endl;
					cout << "Medical card number: " << example[i].medicalcard << endl;
					cout << '\n' << "Insurance policy number: " << example[i].insurance << endl;
					cout << '\n' << "_________________________" << '\n' << endl;
					count++;
				}
			}
			if (count == 0)
				cout << "No matching logs have been found." << '\n' << endl;
			break;

		case 6:
			cout << "Input the sought-for insurance policy number: ";
			cin >> searchnumber;
			cout << '\n' << "_________________________" << '\n' << endl;

			for (int i = 0; i < n; i++)
			{
				if (example[i].insurance == searchnumber)
				{
					cout << "Log #" << i + 1 << endl;
					cout << '\n' << "Name: " << example[i].surname << " " << example[i].firstname << " " << example[i].patronymic << endl;
					cout << '\n' << "Adress: " << example[i].address << endl;
					cout << "Medical card number: " << example[i].medicalcard << endl;
					cout << '\n' << "Insurance policy number: " << example[i].insurance << endl;
					cout << '\n' << "_________________________" << '\n' << endl;
					count++;
				}
			}
			if (count == 0)
				cout << "No matching logs have been found." << '\n' << endl;;
			break;

		case 0:
			break;

		}
	}
	else {
		cout << "ERROR! The file couldn't be accessed correctly.";
		reading.close();
		exit(0);
	}
	reading.close();

}
static void QuickSort(Patient* s , int start, int finish) {

	int left, right, pivot;
	Patient temp;
	left = start;
	right = finish;
	pivot = (start + finish) / 2;
	int i;

	do {
		i = 0;
		while (s[left].surname[i] == s[pivot].surname[i] && i < 40)
			i++;
		while (s[left].surname[i] < s[pivot].surname[i])
			left++;
		i = 0;
		while (s[right].surname[i] == s[pivot].surname[i] && i < 40)
			i++;
		while (s[right].surname[i] > s[pivot].surname[i])
			right--;

		if (left <= right)
		{
			temp = s[left];
			s[left] = s[right];
			s[right] = temp;
			left++;
			right--;
		}
	} while (left <= right);

	if (start < right) QuickSort(s, start, right);
	if (left < finish) QuickSort(s, left, finish);
}
extern void Sort()
{
	ifstream reading("Buffer.txt");
	Patient example[50];
	if (reading) {

		int n, s, count = 0;
		char searchtext[80];
		int searchnumber;

		reading >> n;

		for (int i = 0; i < n; i++)
		{
			reading >> example[i].surname;
			reading >> example[i].firstname;
			reading >> example[i].patronymic;
			reading >> example[i].address;
			reading >> example[i].medicalcard;
			reading >> example[i].insurance;
		}

		QuickSort(example, 0, n - 1);

		cout << "The data sorted in alphabetical order: " << '\n' << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "Log #" << i + 1 << endl;
			cout << '\n' << "Name: " << example[i].surname << " " << example[i].firstname << " " << example[i].patronymic << endl;
			cout << '\n' << "Adress: " << example[i].address << endl;
			cout << "Medical card number: " << example[i].medicalcard << endl;
			cout << '\n' << "Insurance policy number: " << example[i].insurance << endl;
			cout << '\n' << "_________________________" << '\n' << endl;
		}


	}
	else {
		cout << "ERROR! The file couldn't be accessed correctly.";
		reading.close();
		exit(0);
	}
	reading.close();
}
