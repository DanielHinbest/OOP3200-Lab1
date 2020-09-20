/* Program Name: OOP 3200 - Lab 1 - WorkTicket
 * Authors: Ryan Clayson and Daniel Hinbest
 * Date: September 20, 2020
 * Description: A project to create and display a work ticket using the WorkTicket class
 */

#include <iostream>
#include<stdexcept>
#include<sstream>
#include<iomanip>
#include "MyConsoleInput.h"
//TODO: Fix all accessor and mutator names

// class declaration 
class WorkTicket
{
	//private data members
private:
	int ticketNumber;
	std::string clientID;
	int ticketDay;
	int ticketMonth;
	int ticketYear;
	std::string issueDescription; 

	//start of public
public:
	//Default constructor. If paramaters aren't declared, the ticket takes in these default parameters
	WorkTicket(int ticketNumber = 0, std::string clientID = "", int ticketDay = 1, int ticketMonth = 1,
				  int ticketYear = 2000, std::string issueDescription = "");
	
	//All accessors. "Getters"
	int GetTicketNumber();
	std::string GetClientID();
	int GetTicketDay();
	int GetTicketMonth();
	int GetTicketYear();
	std::string GetIssueDescription();
	void ShowWorkTicket() const;

	//All mutators/ "Setters"
	void SetTicketNumber(int ticketNumber);
	void SetClientID(std::string clientID);
	void SetTicketDay(int ticketDay);
	void SetTicketMonth(int ticketMonth);
	void SetTicketYear(int ticketYear);
	void SetIssueDescription(std::string issueDescription);
	bool SetWorkTicket(int number, std::string id, int day, int month, int year, std::string description);
	
	// end of public	
};// end of class

//Constructor Definition
WorkTicket::WorkTicket(int number, std::string id, int day, int month, int year, std::string description)
{
	SetTicketNumber(ticketNumber);
	SetClientID(clientID);
	SetTicketMonth(month);
	SetTicketDay(day);
	SetTicketYear(year);
	SetIssueDescription(description);
}

bool WorkTicket::SetWorkTicket(int number, std::string id, int day, int month, int year, std::string description)
{
	const int DAYS = 31;
	const int MONTHS = 12;
	const int YEAR_MINIMUM = 2000;
	const int YEAR_MAXIMUM = 2099;

	bool returnValue;

	
	if (ticketNumber <= 0 || month < 1 || month > MONTHS
	|| day < 1 || day > DAYS || year < YEAR_MINIMUM || year > YEAR_MAXIMUM)
		returnValue = false;
	else if (clientID.length() < 1 || description.length() < 1)
		returnValue = false;
	else
	{
		ticketNumber = number;
		clientID = id;
		ticketDay = day;
		ticketMonth = month;
		ticketYear = year;
		issueDescription = description;
		return true;
	}
	

	return returnValue;
}

void WorkTicket::ShowWorkTicket() const
{
	std::cout << "\nTicket Number: " << ticketNumber
		<< "\nClient ID: " << clientID
		<< "\nDate: " << ticketDay << "/" << ticketMonth << "/" << ticketYear
		<< "\nDescription:\n\t" << issueDescription << std::endl;
}

int main()
{
	WorkTicket arr[3];
	int numberInput, dayInput, monthInput, yearInput;
	std::string idInput, descriptionInput;

	std::cout << "Please enter the following information when prompted." << std::endl;

	for (int i = 0; i < 3; i++)
	{
		try
		{
			std::cout << "\nEnter ticket number: ";
			numberInput = ConsoleInput::ReadInteger();
			arr[i].SetTicketNumber(numberInput);

			std::cout << "\nEnter Client ID: ";
			std::cin >> idInput;
			arr[i].SetClientID(idInput);

			std::cout << "\nEnter Date: ";
			std::cout << "\n\tDay: ";
			std::cin >> dayInput;
			std::cout << "\n\tMonth: ";
			std::cin >> monthInput;
			std::cout << "\n\tYear: ";
			std::cin >> yearInput;

			arr[i].SetTicketDay(dayInput);
			arr[i].SetTicketMonth(monthInput);
			arr[i].SetTicketYear(yearInput);

			std::cout << "\nEnter Descriptive Issue: ";
			std::cin >> descriptionInput;
			arr[i].SetIssueDescription(descriptionInput);
		}
		catch (const std::exception& ex)
		{
			std::cerr << ex.what();
		}
	}
	std::cout << std::endl;

	std::cout << "Following information was received.";
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Ticket Number: " << arr[i].GetTicketNumber() << std::endl;
		std::cout << "Client ID: " << arr[i].GetClientID() << std::endl;
		std::cout << "Date: " << arr[i].GetTicketDay() << " / " << arr[i].GetTicketMonth()
			<< " / " << arr[i].GetTicketYear() << std::endl;
		std::cout << "Description: " << arr[i].GetIssueDescription() << std::endl << std::endl;
	}
}

void WorkTicket::SetTicketNumber(int number)
{	
	try
	{
		if (number > 0) 
		{
			ticketNumber = number;
		}
	}
	catch (std::invalid_argument)
	{
		throw std::invalid_argument("Ticket Number must be a positive whole number. Please try again.");
	}
	
}
void WorkTicket::SetClientID(std::string id)
{
	try
	{
		if (id.length() > 0)
		{
			clientID = id;
		}
	}
	catch (std::invalid_argument)
	{
		throw std::invalid_argument("Please enter client ID using alpha-numeric.");
	}
}
void WorkTicket::SetTicketDay(int day)
{	
	try
	{
		if (day >= 1 && day <= 31)
		{
			ticketDay = day;
		}
	}
	catch (std::invalid_argument)
	{
		throw std::invalid_argument("Invalid Day. Please enter a day between 1 and 31");
	}
}
void WorkTicket::SetTicketMonth(int month)
{	
	try
	{
		if (month >= 1 && month <= 12)
		{
			ticketMonth = month;
		}
	}
	catch (std::invalid_argument)
	{
		throw std::invalid_argument("Invalid Month. Please enter month between 1 and 12");
	}
}
void WorkTicket::SetTicketYear(int year)
{	
	try
	{
		if (year <= 2099 && year >= 2000)
		{
			ticketYear = year;
		}
	}
	catch (std::invalid_argument)
	{
		throw std::invalid_argument("Invalid Year. Please enter year between 2000 and 2099.");
	}
}
void WorkTicket::SetIssueDescription(std::string description)
{
	try
	{
		if (description.length() > 0)
		{
			issueDescription = description;
		}
	}
	catch (std::invalid_argument)
	{
		throw std::invalid_argument("Please enter descriptive issue.");
	}
}

int WorkTicket::GetTicketNumber()
{
	return ticketNumber;
}
std::string WorkTicket::GetClientID()
{
	return clientID;
}
int WorkTicket::GetTicketDay()
{
	return ticketDay;
}
int WorkTicket::GetTicketMonth()
{
	return ticketMonth;
}
int WorkTicket::GetTicketYear()
{
	return ticketYear;
}
std::string WorkTicket::GetIssueDescription()
{
	return issueDescription;
}

