#include "Database.h"
#include "Student.h"
#include "Employee.h"
#include "Person.h"
#include <fstream>
#include <string>
#include <cctype>
#include <list>
#include <algorithm>

bool ComparePesel(Person* person1, Person* person2)
{
	return person1->GetPesel() < person2->GetPesel();
}

bool CompareSurname(Person* person1, Person* person2)
{
	return person1->GetSurname() < person2->GetSurname();
}

bool CompareEarnings(Person* person1, Person* person2)
{
	if (dynamic_cast<Employee*>(person1) && dynamic_cast<Employee*>(person2))
	{
		return dynamic_cast<Employee*>(person1)->GetEarnings() < dynamic_cast<Employee*>(person2)->GetEarnings();
	}
	return false;
}

void Database::AddPerson(Person* newPerson)
{
	if (ValidatePesel(newPerson->GetPesel()))
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
	Person* foundPerson = SearchByPesel(pesel);
	if (NULL != foundPerson)
	{
		Persons.erase(std::find(Persons.begin(), Persons.end(), foundPerson));
		std::cout << "Person was succesfully removed" << std::endl;
	}
	else 
	{
		std::cout << "There is no person with such PESEL" << std::endl;
	}
}

People Database::SearchBySurname(const std::string surname)
{
	People foundPeople;
	for (auto &person : Persons)
	{
		if (surname == person->GetSurname())
		{
			foundPeople.push_back(person);
		}
	}
	return foundPeople;
}

Person* Database::SearchByPesel(const std::string pesel)
{
	for (auto &person : Persons)
	{
		if (pesel == person->GetPesel())
		{
			return person;
		}
	}
	return NULL;
}

void Database::ModifyAddressByPesel(const std::string pesel, const std::string newAddress)
{
	
	Person* foundPerson = SearchByPesel(pesel);
	if (NULL != foundPerson)
	{
		foundPerson->SetAddress(newAddress);
	}
}

void Database::PrintPersonalInformation(Person *person)
{
	std::cout << "Name: " << person->GetName() << std::endl;
	std::cout << "Surname: " << person->GetSurname() << std::endl;
	std::cout << "Pesel: " << person->GetPesel() << std::endl;
	std::cout << "Address: " << person->GetAddress() << std::endl;
	std::cout << "Gender: " << GenderToString(person->GetGender()) << std::endl;
	if (dynamic_cast<Student*>(person))
	{
		std::cout << "Index: " << dynamic_cast<Student*>(person)->GetIndex() << std::endl;
	}
	if (dynamic_cast<Employee*>(person))
	{
		std::cout << "Earnings: " << dynamic_cast<Employee*>(person)->GetEarnings() << std::endl;
	}
	std::cout << std::endl;
}

void Database::PrintPeople(People people)
{
	std::cout << std::endl;
	for (auto person : people)
	{
		PrintPersonalInformation(person);
	}
}

void Database::PrintPeople()
{
	std::cout << std::endl;
	for (auto person : Persons)
	{
		PrintPersonalInformation(person);
	}
}

void Database::SavePeopletoFile()
{
	std::ofstream DatabaseFile(defaultFile);
	for (auto& person : Persons)
	{
		if (dynamic_cast<Student*>(person))
		{
			DatabaseFile << "Student" << std::endl;
		}
		if (dynamic_cast<Employee*>(person))
		{
			DatabaseFile << "Employee" << std::endl;
		}
		
		DatabaseFile << person->GetName() << std::endl;
		DatabaseFile << person->GetSurname() << std::endl;
		DatabaseFile << person->GetPesel() << std::endl;
		DatabaseFile << person->GetAddress() << std::endl;
		DatabaseFile << GenderToString(person->GetGender()) << std::endl;
		if (dynamic_cast<Student*>(person))
		{
			DatabaseFile << dynamic_cast<Student*>(person)->GetIndex() << std::endl;
		}
		if (dynamic_cast<Employee*>(person))
		{
			DatabaseFile << dynamic_cast<Employee*>(person)->GetEarnings() << std::endl;
		}
		DatabaseFile << "-------------------" << std::endl;
	}
	DatabaseFile.close();
}

void Database::LoadPeoplefromFile()
{
	Student* loadedStudent;
	Employee* loadedEmployee;
	bool bLoadingStudent = false;
	bool bLoadingEmployee = false;
	std::vector <std::string> loadedPersonInfo;
	
	std::string line;
	std::ifstream DatabaseFile(defaultFile);
	if (DatabaseFile.is_open())
	{
		while (std::getline(DatabaseFile, line))
		{
			if ("Student" == line)
			{
				bLoadingStudent = true;
			}
			if ("Employee" == line)
			{
				bLoadingEmployee = true;
			}
			if (bLoadingStudent || bLoadingEmployee)
			{
				if ("-------------------" == line)
				{
					if (bLoadingStudent)
					{
						loadedStudent = new Student(
							loadedPersonInfo[1],
							loadedPersonInfo[2],
							loadedPersonInfo[3],
							loadedPersonInfo[4],
							StringToGender(loadedPersonInfo[5]),
							stoi(loadedPersonInfo[6]));
						loadedPersonInfo.clear();
						AddPerson(loadedStudent);
					}
					else if (bLoadingEmployee)
					{
						loadedEmployee = new Employee(
							loadedPersonInfo[1],
							loadedPersonInfo[2],
							loadedPersonInfo[3],
							loadedPersonInfo[4],
							StringToGender(loadedPersonInfo[5]),
							stoi(loadedPersonInfo[6]));
						loadedPersonInfo.clear();
						AddPerson(loadedEmployee);
					}
					bLoadingStudent = false;
					bLoadingEmployee = false;
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

void Database::SortByPesel()
{
	sort(Persons.begin(), Persons.end(), ComparePesel);
}

void Database::SortBySurname()
{
	sort(Persons.begin(), Persons.end(), CompareSurname);
}

void Database::SortByEarnings()
{
	sort(Persons.begin(), Persons.end(), CompareEarnings);
}