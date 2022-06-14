#include "Database.h"

void Database::AddPerson(const Person newPerson)
{
	Persons.push_back(newPerson);
}

People Database::GetPersons()
{
	return Persons;
}

void Database::RemovePersonByPesel(const std::string pesel)
{
	for (People::iterator it = Persons.begin(); it < Persons.end(); it++)
	{
		if (pesel == it->GetPesel())
		{
			RemovePerson(it);
			break;
		}
	}
}

void Database::RemovePerson(People::iterator it)
{
	Persons.erase(it);
}

People Database::SearchBySurname(const std::string surname)
{
	People foundPeople;
	for (People::iterator it = Persons.begin(); it < Persons.end(); it++)
	{
		if (surname == it->GetSurname())
		{
			foundPeople.push_back(*it);
		}
	}
	return foundPeople;
}

Person Database::SearchByPesel(const std::string pesel)
{
	for (People::iterator it = Persons.begin(); it < Persons.end(); it++)
	{
		if (pesel == it->GetPesel())
		{
			return *it;
		}
	}
}

void Database::PrintPersonalInformation(Person person)
{
	std::cout << person.GetName() << std::endl;
	std::cout << person.GetSurname() << std::endl;
	std::cout << person.GetPesel() << std::endl;
	std::cout << person.GetAddress() << std::endl << std::endl;
}

void Database::PrintPeople(People people)
{
	for (People::iterator it = people.begin(); it < people.end(); it++)
	{
		PrintPersonalInformation(*it);
	}
}

void Database::PrintPeople()
{
	for (People::iterator it = Persons.begin(); it < Persons.end(); it++)
	{
		PrintPersonalInformation(*it);
	}
}