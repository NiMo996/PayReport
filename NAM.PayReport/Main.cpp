#include <iostream>
#include <conio.h>
#include <string> // used for string data type and getline function
#include <limits> // used in data validation for entering number of employees and clearing the input buffer

//Pay Report: Assignment 4
//Nick Moede 10/4/2024

using namespace std;

//Employee struct
struct Employee {
	int ID = 0;
	string FirstName;
	string LastName;
	float HoursWorked = 0.0f;
	float HourlyRate = 0.0f;
};
static float CalculateWeeklyPay(float hoursWorked, float hourlyRate)
{
	return hoursWorked * hourlyRate;
}
static void PrintTotalPayReport(Employee* employees, int numEmployees)
{

	cout << "Pay Report:" << endl;
	cout << "----------------" << endl;
	float totalPay = 0;
	for (int i = 0; i < numEmployees; i++)
	{
		float individualPay = CalculateWeeklyPay(employees[i].HoursWorked, employees[i].HourlyRate);
		totalPay += individualPay;
		cout << (i + 1) << ". " << employees[i].FirstName << " " << employees[i].LastName
			<< ": $" << individualPay << endl;
	}
	cout << endl;
	cout << "Total Pay: $" << totalPay << endl;
}

int main()
{
	int numEmployees = 0;
	bool invalidInput = false;
	while (!invalidInput)
	{

		cout << "Enter the number of employees: ";
		if (cin >> numEmployees && numEmployees > 0) //check if input is a valid number and not a character
		{
			invalidInput = true;
		}
		else
		{
			invalidInput = false;
			cout << "Please enter a valid number of employees: ";
			cin.clear(); //clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard the input
		}
		cout << endl;

	}
	Employee* employees = new Employee[numEmployees]; //allocate memory for employees array after data validation
	//Enter employee data
	for (int i = 0; i < numEmployees; i++)
	{

		cout << "|-----Employee " << i + 1 << " Information-----|" << endl;
		cout << endl;
		cout << "Enter the ID for Employee " << i + 1 << ": ";
		cin >> employees[i].ID;
		cin.ignore();
		cout << "Enter the First Name for Employee " << i + 1 << ": ";
		cin >> ws;
		getline(cin, employees[i].FirstName);
		cout << "Enter the Last Name for Employee " << i + 1 << ": ";
		cin >> ws;
		getline(cin, employees[i].LastName);
		cout << "Enter the Hours Worked for Employee " << i + 1 << ": ";
		cin >> employees[i].HoursWorked;
		cout << "Enter the Hourly Rate for Employee " << i + 1 << ": ";
		cin >> employees[i].HourlyRate;
		cout << endl;
	}
	PrintTotalPayReport(employees, numEmployees);

	//delete memory allocated for employees array
	delete[] employees;

	(void)_getch();
	return 0;
}