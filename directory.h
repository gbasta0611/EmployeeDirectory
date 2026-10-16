#pragma once
#ifndef BASTA_DIRECTORY_H
#define BASTA_DIRECTORY_H

#include <string>
#include <map>

struct Employee {
	std::string name;
	std::string department;
	std::string email;
};

// validation functions
int get_number(const std::string& prompt);
int get_menu_choice();
std::string get_required_text(const std::string& prompt);

// display and search functions
void display_all(const std::map<int, Employee>& employees);
void search_employees(const std::map<int, Employee>& employees);

// modify the map
void add_employee(std::map<int, Employee>& employees);
void update_employee(std::map<int, Employee>& employees);
void remove_employee(std::map<int, Employee>& employees);

#endif
