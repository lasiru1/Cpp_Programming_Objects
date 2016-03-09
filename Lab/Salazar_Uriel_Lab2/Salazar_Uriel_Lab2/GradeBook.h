#include <string>

class GradeBook
{
public:
	GradeBook();
	GradeBook(std::string, std::string, int);
	void setCourseName(std::string);
	std::string getCourseName();
	void setInstructorName(std::string);
	std::string getInstructorName();
	void setCourseSize(int);
	int getCourseSize();
	void displayMessage();
private:
	std::string courseName;
	std::string instructorName;
	int courseSize;
	int validateCourseSize(int);
};