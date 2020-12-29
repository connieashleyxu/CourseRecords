/*
	Name: Connie Xu
	Course: CSCE II 1040
	Teacher: Keathly
	Assignment: Homework 2
*/
#include <iostream>
#include <fstream> 
#include <string>
#include <ctype.h>
#include <cstdlib>
using namespace std;

#include "Enrollment.h"
#include "Student.h"
#include "Course.h"

//class for student menu
class StudentMenu
{
	private:
		//void Introduction(void);
	public: 
		void MainMenu(void);
};

//main menu function
void StudentMenu::MainMenu(void)
{
	//objects for classes
	studentCourse Stu;
	Enrollment En;
	Student S;
	int option;	//option int

	//output wlelcome
	cout << endl << "  Welcome to Gradebook!" << endl << endl;
	while (1)
	{
		//output menu
		cout << " 1. Add a New Course\n";
		cout << " 2. Print a list of all Courses\n";

		cout << " 3. Add a New Student\n";
		cout << " 4. Print a list of all Students\n";

		cout << " 5. Add New Enrollment\n";
		cout << " 6. Display all Enrollment Records\n";

		cout << " 7. Add Grades for a student in a course\n";
		cout << " 8. Print a list of all grades for a student in a course\n";
		cout << " 9. Print a list of all students in a course\n";
		cout << " 10. Compute the Average for a course\n";
		cout << " 11. Store Grade Book to Disk\n";
		cout << " 12. Load Grade Book from Disk\n";

		cout << " 13. QUIT\n";
		cout << "Enter Your Choice: \n";

		//get in user input
		cin >> option;

		//choose certain options according to user input, check for out of range inputs and break
		if (option <= 0 || option >= 13)
		{
			break;
		}
		else
		if (option == 13)
		{
			cout << endl << "You quit" << endl;
			exit(1);
		}
		else
		if (option == 1)
		{
			//studentCourse S;
			Stu.NewCourse();
		}
		else
		if (option == 2)
		{
			//studentCourse s;
			//s.DisplayRecordFile();
			Stu.DisplayRecord();
		}
		else
        	if (option == 3)
		{
			S.NewStudent();
		}
		else
        	if (option == 4)
		{
			S.DisplayStudent();
		}
		else
       	 	if (option == 5)
		{
			//check for 1: Existing Course ID?
			//           2: Existing student ID:
			//           3: Num of Same course ID < 48
			int sID, cID;
			cout << "Student ID:  ";
			cin >> sID;
			int Found = S.CheckStuIDFound (sID);
			if (!Found)
			{
				cout << "Student ID " << sID << " DOES NOT exist, Not adding to Enrollment Rec"<< endl;
				continue;
			}

			cout << "Enter Course ID: ";
			cin >> cID;
			Found = Stu.CourseIDFound(cID);
			if (!Found)
			{
				cout << "Course ID " << cID << " DOES NOT exist, Not adding to Enrollment Rec"<< endl;
				continue;
			}

			En.NewEnrollment(sID, cID);
		}
		else
        	if (option == 6)
		{
			En.DisplayEnrollment();
		}
		else
        	if (option == 7)
		{
			//add grades for a student in a course
			//enter sID and cID
			En.AddGradesForStudentinCourse();
		}
		else
        	if (option == 8)
		{
			En.PrintGradesforStudent ();
		}
		else
        	if (option == 9)
		{
			En.PrintAllStudentinCourse ();
		}
		else
        	if (option == 10)
		{
			En.ComputeAvgForCourse();
		}
		else
        	if (option == 11)
		{
			En.DumpEnrollmentTableToFile();
			S.DumpStudentTableToFile();
			Stu.DumpCourseTableToFile();
		}
		else
        	if (option == 12)
		{
			fstream file;

			file.open("GradeBook.txt", ios::in);
			if(file.fail())
			{
				cout << "Error in LoadCourseTableFromFile opening file !!!" << endl;
				return;
			}
			string Buffer;

			while (getline(file, Buffer))
			{
				cout << Buffer << endl;
			}

			file.close();
		
/*
			int Pos;

			Pos = 0;
			En.LoadEnrollmentTableFromFile(Pos);
			Pos = En.GetPos();
			cout << "Enrollments Pos = " << Pos << endl;
			S.LoadStudentTableFromFile(Pos);
			Pos = S.GetPos();
			cout << "Students Pos = " << Pos << endl;
			Stu.LoadCourseTableFromFile(Pos);
*/
		}
	}
}

int main()
{
	//call main menu
	StudentMenu menu;
	menu.MainMenu();
	return 0;
}
