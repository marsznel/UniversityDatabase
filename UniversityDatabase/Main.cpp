#include <iostream>
#include "Student.h"
#include "Employee.h"
#include "Database.h"

int main()
{
	Database dataBase;
	Database dataBase1;
	Employee* Employeeptr = new Employee("Jan", "Surname", "90090515836", "Address", Gender::Male, 4000);
	Student* studentptr = new Student("Andrzej", "Surname", "96012109879", "Address", Gender::Male, 124515);
	Employee* Employeeptr1 = new Employee("Kasia", "Surname", "80072909146", "Address", Gender::Female, 3500);
	//dataBase.AddPerson(Employeeptr);
	//dataBase.AddPerson(Employeeptr1);
	//dataBase.AddPerson(studentptr);
	//dataBase.ModifyAddressByPesel("96012109879", "New Address");
	//dataBase.PrintPeople();
	//dataBase.SavePeopletoFile();
	//dataBase1.LoadPeoplefromFile();
	//dataBase1.RemovePersonByPesel("96012109879");
	//dataBase1.PrintPeople();
	//dataBase.SortByEarnings();
	//dataBase.PrintPeople();
	dataBase.GenerateData(3);
	dataBase.PrintPeople();
}

