#include "Database.h"
#include "Person.h"
#include <fstream>
#include <string>
#include <list>

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
			Persons.erase(it);
			break;
		}
	}
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
	for (auto it : Persons)
	{
		if (pesel == it.GetPesel())
		{
			return it;
		}
	}
}

void Database::PrintPersonalInformation(Person person)
{
	std::cout << person.GetName() << std::endl;
	std::cout << person.GetSurname() << std::endl;
	std::cout << person.GetPesel() << std::endl;
	std::cout << person.GetAddress() << std::endl;
	std::cout << GenderToString(person.GetGender()) << std::endl;
	std::cout << std::endl;
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
	for (auto it : Persons)
	{
		PrintPersonalInformation(it);
	}
}

void Database::SavePeopletoFile()
{
	std::ofstream DatabaseFile("People.txt");
	for (auto person : Persons)
	{
		DatabaseFile << "Person" << std::endl;
		DatabaseFile << person.GetName() << std::endl;
		DatabaseFile << person.GetSurname() << std::endl;
		DatabaseFile << person.GetPesel() << std::endl;
		DatabaseFile << person.GetAddress() << std::endl;
		DatabaseFile << GenderToString(person.GetGender()) << std::endl;
		DatabaseFile << "-------------------" << std::endl;
	}
	DatabaseFile.close();
}

void Database::LoadPeoplefromFile()
{
	Person loadedPerson;
	bool bLoadingPerson = false;
	std::vector <std::string> loadedPersonInfo;
	std::string line;
	std::ifstream DatabaseFile("People.txt");
	if (DatabaseFile.is_open())
	{
		while (std::getline(DatabaseFile, line))
		{
			if (line == "Person")
			{
				bLoadingPerson = true;
			}
			else if (bLoadingPerson)
			{
				if (line == "-------------------")
				{
					bLoadingPerson = false;
					Person loadedPerson(loadedPersonInfo[0], loadedPersonInfo[1], loadedPersonInfo[2], loadedPersonInfo[3], StringToGender(loadedPersonInfo[4]));
					loadedPersonInfo.clear();
					AddPerson(loadedPerson);
				}
				else
				{
					loadedPersonInfo.push_back(line);
				}
			}
		}
		DatabaseFile.close();
	}
	else
	{
		std::cout << "Cannot open file" << std::endl;
	}
}