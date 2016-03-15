// header file for MailingLabel class

// prevent multiple inclusions of header
#ifndef	MAILINGLABEL_H
#define	MAILINGLABEL_H

// system libraries
#include <iostream>
#include <string>

// class "MailingLabel" definition
class MailingLabel
{
	friend std::ostream &operator << (std::ostream &, const MailingLabel &);	// outputting 

public:
	std::string senderName;
	std::string firstName;
	std::string firstName;
	std::string firstName;
	std::string firstName;
	std::string firstName;


private:


};

#endif
