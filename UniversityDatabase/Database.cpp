#include "Database.h"
#include "Person.h"
#include <fstream>
#include <string>
#include <cctype>
#include <list>
#include <algorithm>

void Database::AddPerson(Person newPerson)
{
	if (ValidatePesel(newPerson.GetPesel()))
	{
		Persons.push_back(newPerson);
		std::cout << "New Person was added" << std::endl;
	}
	else
	{
		std::cout << "Pesel number is not valid" << std::endl;
	}
}

bool Database::ValidatePesel(const std::string pesel)
{
	// Digits validation
	if (!std::any_of (pesel.begin(), pesel.end(), ::isdigit) || pesel.length() != 11)
	{
		return false;
	}

	// BirthDay validation
	int birthMonthDigits = stoi(pesel.substr(2,2));
	int birthDayDigits = stoi(pesel.substr(4, 2));
	if (!((birthMonthDigits < 93 && birthMonthDigits < 80) || (birthMonthDigits < 73 && birthMonthDigits < 60) || (birthMonthDigits < 53 && birthMonthDigits < 40)
		|| (birthMonthDigits < 33 && birthMonthDigits < 20) || (birthMonthDigits < 13 && birthMonthDigits < 0)) || birthDayDigits > 31)
	{
		return false;
	}

	// Control Digit Validation
	int lastDigit = 0;
	const int weights[] = { 1,3,7,9,1,3,7,9,1,3 };
	for (int i = 0; i< 10; i++)
	{
		int digit = pesel[i] - '0';
		lastDigit += digit * weights[i];
	}
	lastDigit = 10 - lastDigit % 10;
	if (lastDigit == 10)
	{
		lastDigit = 0;
	}
	if (lastDigit != stoi(pesel.substr(pesel.length()-1, 1)))
	{
		return false;
	}

	return true;
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
	for (auto person : Persons)
	{
		if (surname == person.GetSurname())
		{
			foundPeople.push_back(person);
		}
	}
	return foundPeople;
}

Person* Database::SearchByPesel(const std::string pesel)
{
	for (auto person : Persons)
	{
		if (pesel == person.GetPesel())
		{
			Person savedPerson = person;
			return &savedPerson;
		}
	}
	return NULL;
}

void Database::ModifyAddressByPesel(const std::string pesel, const std::string newAddress)
{
	Person* foundPerson = SearchByPesel(pesel);
	if (foundPerson != NULL)
	{
		Person personToChange = *foundPerson;
		personToChange.ChangeAddress(newAddress);
		std::replace(Persons.begin(), Persons.end(), *foundPerson, personToChange);
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
	for (auto person : people)
	{
		PrintPersonalInformation(person);
	}
}

void Database::PrintPeople()
{
	for (auto person : Persons)
	{
		PrintPersonalInformation(person);
	}
}

void Database::SavePeopletoFile()
{
	std::ofstream DatabaseFile(defaultFile);
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
	std::ifstream DatabaseFile(defaultFile);
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