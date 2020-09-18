/* Program Name :
* Authors : Ryan Clayson (100______) and Daniel Hinbest (100717231)
* Date :
* Description :
*/
#include <string>

class WorkTicket
{
private:
	int ticketNumber;
	int clientID;
	int ticketDay;
	int ticketMonth;
	int ticketYear;
	std::string issueDescription; //Could be public as well
public:
	WorkTicket();
	WorkTicket(int number, int day, int month, int year);
};
