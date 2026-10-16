#include <iostream>
#include <stdexcept>
#include "directory.h"

using namespace std;

int main()
{
	map<int, Employee> employees {
		{1001, {"Casey Feininger", "Graphic Design", "casey@lakeareatech.edu"}},
		{1008, {"BJ Bolton", "SD/NET", "bj@lakeareatech.edu"}},
		{1003, {"Brandon Stangl", "NET", "brandon@lakeareatech.edu"}},
		{1010, {"Amber LaPrairie", "SD/GD", "amber@lakeareatech.edu"}}
	};

	try
	{
		int choice = 1;
		while (choice != 6){
			choice = get_menu_choice();

			switch(choice){
				case 1:
					display_all(employees);
					break;
				case 2:
					search_employees(employees);
					break;
				case 3:
					add_employee(employees);
					break;
				case 4:
					update_employee(employees);
					break;
				case 5:
					remove_employee(employees);
					break;
				case 6:
					cout << "Goodbye!\n";
					break;
			}
		}
	}
	catch (const runtime_error& e){
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}















