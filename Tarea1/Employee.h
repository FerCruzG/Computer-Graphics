#pragma once	
#include <string>

class Employee {	//declaracion de la clase Circle
public:

	Employee(int _id, std::string firstName, std::string lastName, int salary);

	int GetId();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetName();
	int GetSalary();
	void SetSalary(int salary);
	int GetAnualSalary();
	int RaiseSalary(int percent);
	std::string Print();

private:		//variables
	
	int _id;
	std::string _firstName;
	std::string _lastName;
	int _salary;
};