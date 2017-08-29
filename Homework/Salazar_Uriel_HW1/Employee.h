//System Libraries
#include <string>

//"Employee" class definition
class Employee
{
public:
	Employee();
	Employee(std::string, std::string, float);
	void setFirstName(std::string);
	std::string getFirstName();
	void setLastName(std::string);
	std::string getLastName();
	void setMonthlySalary(float);
	float getMonthlySalary();
	void displayAnnualSalary();
	void displayRaisedSalary();
private:
	std::string firstName;
	std::string lastName;
	float monthlySalary;
	float yearlySalary = 0;
	float raisedSalary = 0;
	float raise = 0.10;
	float validateMonthlySalary(float);
	float calculateYearlySalary(float);
	float calculateRaisedSalary(float, float);
};