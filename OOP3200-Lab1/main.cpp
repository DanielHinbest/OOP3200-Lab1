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
	std::string ShowWorkTicket() const;

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
	SetWorkTicket::WorkTicket(number, std::string id, day, month, year, std::string description);
}

bool WorkTicket::SetWorkTicket(int number, std::string id, int day, int month, int year, std::string description)
{
	SetTicketNumber(number);
	SetClientID(id);
	SetTicketDay(day);
	SetTicketMonth(month);
	SetTicketYear(year);
	SetIssueDescription(description);

	return true;
}


//Class definiton section
//SetWorkTicket - Sets all the attributes in the class
//bool WorkTicket::SetWorkTicket(int ticketNumber, std::string id, int day, int month, int year, std::string description)
//{
//	bool returnValue;
//	ticketNumber++;
//	clientID = ticketYear + ticketMonth + ticketYear + ticketNumber;
//	std::getline(std::cin, issueDescription);
//
//	if (issueDescription.length() < 1)
//		returnValue = false;
//	else
//		returnValue = true;
//	return returnValue;
//}


int main()
{
	WorkTicket arr[3];
	int numberInput, dayInput, monthInput, yearInput;
	std::string idInput, descriptionInput;

	cout << "Please enter the following information when prompted." << endl;

	for (int i = 0; i < 3; i++)
	{
		try
		{
			cout << "\nEnter ticket number: ";
			numberInput = ConsoleInput::ReadInteger();
			arr[i].SetTicketNumber(numberInput);

			cout << "\nEnter Client ID: ";
			cin >> idInput;
			arr[i].SetClientID(idInput);

			cout << "\nEnter Date: ";
			cin >> dayInput >> monthInput >> yearInput;
			arr[i].SetTicketDay(dayInput);
			arr[i].SetTicketMonth(monthInput);
			arr[i].SetTicketYear(yearInput);

			cout << "\nEnter Descriptive Issue: ";
			cin >> descriptionInput; 
			arr[i].SetIssueDescription(descriptionInput); 
		}
		catch (const exception& ex)
		{
			cerr << ex.what();
		}
	}
	cout << endl;

	cout << "Following information was received.";
	for (int i = 0; i < 3; i++)
	{
		cout << "Ticket Number: " << arr[i].GetTicketNumber() << endl;
		cout << "Client ID: " << arr[i].GetClientID() << endl;
		cout << "Date: " << arr[i].GetTicketDay() << " / " << arr[i].GetTicketMonth()
			 << " / " << arr[i].GetTicketYear() << endl;
		cout << "Description: " << arr[i].GetIssueDescription() << endl << endl;
	}

void WorkTicket::SetTicketNumber(int number)
{
	if (number > 0) 
	{
		ticketNumber = number;
	}
	else
	{
		throw invalid_argument("Ticket Number must be a positive whole number. Please try again.");

	}
}
void WorkTicket::SetClientID(std:string id)
{
	if (id.length() > 0)
	{
		clientID = id;
	}
	else
	{
		throw invalid_argument("Please enter client ID using alpha-numeric.");
	}
}
void WorkTicket::SetTicketDay(int day)
{
	if (day >= 1 && day <= 31)
	{
		ticketDay = day;
	}
	else
	{
		throw invalid_argument("Invalid Day. Please enter day between 1 and 31");
	}
}
void WorkTicket::SetTicketMonth(int month)
{
	if (month >= 1 && month <= 12)
	{
		ticketMonth = month;
	}
	else
	{
		throw invalid_argument("Invalid Month. Please enter month between 1 and 12");
	}
}
void WorkTicket::SetTicketYear(int year)
{
	if (year <= 2099 && year >= 2000)
	{
		ticketYear = year;
	}
	else
	{
		throw invalid_argument("Invalid Year. Please enter year between 2000 and 2099.");
	}
}
void WorkTicket::SetIssueDescription(std::string description)
{
	if (description.length() > 0)
	{
		issueDescription = description;
	}
	else
	{
		throw invalid_argument("Please enter descriptive issue.");
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

