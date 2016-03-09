#include <iostream>
#include <string>
#include "GradeBook.h"

using namespace std;

int main()
{
	string inputName;
	string inputInstructor;
	int inputSize;

	cout << "Enter Course Name: ";
	cin >> inputName;
	cout << "Enter Instructor Name: ";
	cin >> inputInstructor;
	cout << "Enter Course Size: ";
	cin >> inputSize;

	GradeBook myBook1(inputName, inputInstructor, inputSize);

	cout << "Course name is " << myBook1.getCourseName() << "." << endl;
	cout << "Instructor name is " << myBook1.getInstructorName() << "." << endl;
	cout << "Course size is " << myBook1.getCourseSize() << "." << endl;
	myBook1.displayMessage();

	cout << endl;

	cout << "Enter 2nd Course Name: ";
	cin >> inputName;
	cout << "Enter 2nd Instructor Name: ";
	cin >> inputInstructor;
	cout << "Enter 2nd Course Size: ";
	cin >> inputSize;

	GradeBook myBook2(inputName, inputInstructor, inputSize);

	cout << "Course name is " << myBook2.getCourseName() << "." << endl;
	cout << "Instructor name is " << myBook2.getInstructorName() << "." << endl;
	cout << "Course size is " << myBook2.getCourseSize() << "." << endl;
	myBook2.displayMessage();

	return 0;
}