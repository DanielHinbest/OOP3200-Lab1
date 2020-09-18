/* Program Name : OOP 3200 - Lab 1 - WorkTicket.cpp Class
* Authors : Ryan Clayson (10055837) and Daniel Hinbest (100717231)
* Date : 
* Description :
*/
#include <string>

// class declaration 
class WorkTicket
{
	//private data members
private:
	int ticketNumber;
	int clientID;
	int ticketDay;
	int ticketMonth;
	int ticketYear;
	std::string issueDescription; //Could be public as well

	//Declaration for Constructor
public:
	WorkTicket();
	WorkTicket(int, int, int, int);
	bool SetWorkTicket(int id, std::string description); //I think
	void ShowWorkTicket();
	
};

//Constructors - default
WorkTicket::WorkTicket()
{
	ticketNumber = 0;
	int ticketDay;
	int ticketMonth;
	int ticketYear;
}

//Constructors - parameterized
WorkTicket::WorkTicket(int number, int day, int month, int year)
{
	ticketNumber = number;
	ticketDay = day;
	ticketMonth = month;
	ticketYear = year;
}

//Class definiton section
/* A mutator method to set all the attributes of the object to the parameters as
long as the parameters are valid. ALL of the parameters must be valid in order for ANY of the
attributes to change. Validation rules are explained above for work ticket number and date. Client
number and Description must be at least one character long. If no problems are detected, return
TRUE. Otherwise return FALSE.
 */
bool WorkTicket::SetWorkTicket(int id, std::string description)
{
	
}

void WorkTicket::ShowWorkTicket() //Display all attributes
{
	
}
