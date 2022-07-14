#include <iostream>
#include "Student.h"
#include "Database.h"

int main()
{
	Database dataBase;
	Database dataBase1;
	dataBase1.LoadPeoplefromFile();
	dataBase1.ModifyAddressByPesel("55030101193", "New Address");
	dataBase1.PrintPeople();
}

