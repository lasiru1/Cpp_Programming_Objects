#include <iostream>
#include <string>
#include "GradeBook.h"

GradeBook::GradeBook()
{
	courseName = "";
	instructorName = "";
	courseSize = -1;
}

GradeBook::GradeBook(std::string name, std::string instructor, int size)
{
	setCourseName(name);
	setInstructorName(instructor);
	setCourseSize(size);
}

void GradeBook::setCourseName(std::string name)
{
	if (name.size() < 25)
	{
		courseName = name;
	}

	if (name.size() >= 25)
	{
		courseName = name.substr(0, 25);
		std::cerr << "Name: \"" << name
			<< "\" exceeds the maximum length (25).\n"
			<< "Limiting courseName to first 25 characters.\n"
			<< std::endl;
	}
}

std::string GradeBook::getCourseName()
{
	return courseName;
}

void GradeBook::setInstructorName(std::string instructor)
{
	if (instructor.size() < 25)
	{
		instructorName = instructor;
	}

	if (instructor.size() >= 25)
	{
		instructorName = instructor.substr(0, 25);
		std::cerr << "Name: \"" << instructor
			<< "\" exceeds the maximum length (25).\n"
			<< "Limiting courseName to first 25 characters.\n"
			<< std::endl;
	}
}

std::string GradeBook::getInstructorName()
{
	return instructorName;
}

void GradeBook::setCourseSize(int size)
{
	if (validateCourseSize(size) == -1)
		courseSize = -1;
	else
		courseSize = size;
}

int GradeBook::getCourseSize()
{
	return courseSize;
}

void GradeBook::displayMessage()
{
	std::cout << "Welcome to the gradebook for " << courseName << "!" << std::endl;
	std::cout << "This course is presented by: " << instructorName << std::endl;
	std::cout << "Course size for " << courseName << " is " << courseSize << ".\n";
}

int GradeBook::validateCourseSize(int size)
{
	if (size < 1)
	{
		std::cerr << "Class cannot have less than 1 student.\n";
		//courseSize = -1;
		std::cerr << "courseSize variable set to -1.\n";
		return -1;
	}
	else if (size > 32)
	{
		std::cerr << "Class cannot have more than 32 students.\n";
		//courseSize = -1;
		std::cerr << "courseSize variable set to -1.\n";
		return -1;
	}
}