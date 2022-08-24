#include <iostream>
#include "Student.h"
#include "Employee.h"
#include "Database.h"

int main()
{
	Database dataBase;
	Database dataBase1;
	Student *studentptr = new Student("Name", "Surname", "96012109879", "Address", Gender::Female, 124515);
	Employee* Employeeptr = new Employee("Name", "Surname", "90090515836", "Address", Gender::Female, 59898);
	dataBase.AddPerson(studentptr);
	dataBase.AddPerson(Employeeptr);
	dataBase.ModifyAddressByPesel("96012109879", "New Address");
	dataBase.PrintPeople();
	dataBase.SavePeopletoFile();
	dataBase1.LoadPeoplefromFile();
	dataBase1.RemovePersonByPesel("90090515836");
	dataBase1.PrintPeople();
}

