#include "Database.h"

void Database::AddPerson(Person newPerson)
{
	Persons.push_back(newPerson);
}

std::vector<Person> Database::GetPersons()
{
	return Persons;
}

Person Database::SearchByName(std::string Name)
{
	for (std::vector<Person>::iterator it = Persons.begin(); it < Persons.end(); it++)
	{
		if (it->CheckName(Name))
		{
			return *it;
		}
	}
}