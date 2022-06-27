#include <iostream>
#include "Student.h"
#include "Database.h"

int main()
{
	Database dataBase;
	Database dataBase1;
	Person person1{ Person("Janek", "Nowak", "12234", "Rondo 45", Gender::Male) };
	dataBase.AddPerson(person1);
	dataBase.SavePeopletoFile();
	dataBase1.LoadPeoplefromFile();
	dataBase1.PrintPeople();
}

