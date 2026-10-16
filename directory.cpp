#include "directory.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// validation functions
int get_number(const string& prompt)
{
	int number;
	while (true)
	{
		cout << prompt;
		if (cin >> number && number > 0){
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return number; // valid number, clear stream and return number
		}

		cout << "Please enter a valid positive number\n";

		if (cin.eof()){
			throw runtime_error("Input stream closed!");
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

int get_menu_choice(){
	cout << "\nEMPLOYEE DIRECTORY\n"
		<< "------------------\n"
		<< "1. Display all employees\n"
		<< "2. Search by employee id\n"
		<< "3. Add employee\n"
		<< "4. Update emplyee\n"
		<< "5. Remove employee\n"
		<< "6. Exit\n\n";

	int choice;
	while (true) {
		choice = get_number("Choice: ");

		if (choice >=1 && choice <=6){
			return choice;
		}

		cout << "Please choose an option from 1 to 6!\n";
	}
}

string get_required_text(const string& prompt){
	string text;

	while (true){
		cout << prompt;

		if (!getline(cin, text)){
			throw runtime_error("Input stream closed!\n");
		}

		if (text.find_first_not_of(" \t") != string::npos){
			return text;
		}

		cout << "This field cannot be empty!\n";
	}
}

// display and search functions
void display_all(const map<int, Employee>& employees) {
	cout << "\nEMPLOYEE DIRECTORY\n"
		<< "------------------\n";

	if (employees.empty()){
		cout << "No employees found!\n";
		return;
	}

	int length = 25;

	cout << left << setw(5) << "ID" << setw(length) << "Name" << setw(length) << "Department" << setw(length) << "Email" << endl;

	for (const auto& employee : employees){
		cout << left << setw(5) << employee.first << setw(length) << employee.second.name << setw(length)
		<< employee.second.department << setw(length) << employee.second.email << endl;
	}
}

void search_employees(const map<int, Employee>& employees) {
	int id = get_number("Enter an employee id: ");
	auto it = employees.find(id); // create an iterator to point to and find id in map

	if (it == employees.end()){
		cout << "Employee not found!\n";
		return;
	}

	cout << "\nEmployee Found:\n"
		<< "ID: " << it->first << endl
		<< "Name: " << it->second.name << endl
		<< "Department: " << it-> second.department << endl
		<< "Email: " << it->second.email << endl;
}

// modify the map
void add_employee(map<int, Employee>& employees) {
	int id = get_number("Enter a new employee id: ");

	if (employees.contains(id)){
		cout << "That employee id already exists.\n";
		return;
	}

	Employee employee;

	employee.name = get_required_text("Enter employee name: ");
	employee.department = get_required_text("Enter employee department: ");
	employee.email = get_required_text("Enter employee email: ");

	employees.insert({id, employee});
	cout << "Employee was added successfully!\n";
}

void update_employee(map<int, Employee>& employees){
	int id = get_number("Enter employee id to update: ");

	if (!employees.contains(id)){
                cout << "That employee id doesn't exist.\n";
                return;
        }

        cout << "\nCurrent employee: " << employees.at(id).name << endl;
        cout << "Current department: " << employees.at(id).department << endl;
        cout << "Current email: " << employees.at(id).email << endl;

        employees.at(id).department = get_required_text("Enter a new department: ");
        employees.at(id).email = get_required_text("Enter a new email: ");

        cout << "Employee was updated successfully!\n";
}

void remove_employee(map<int, Employee>& employees){
	int id = get_number("Enter employee id to remove: ");
	int removed = employees.erase(id);

	if (removed > 0){
		cout << "Employee removed successfully!\n";
	} else {
		cout << "Employee was not found or erased.\n";
	}
}
















