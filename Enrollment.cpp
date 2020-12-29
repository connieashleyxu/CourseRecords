/*
        Name: Connie Xu
        Course: CSCE II 1040
        Teacher: Keathly
        Assignment: Homework 2
*/
#include <iostream>
#include <fstream> 
#include <string.h>
#include <ctype.h>
using namespace std;

#include "Enrollment.h"


//constructor
Enrollment::Enrollment ()
{
	//initializer
	Cnt = 0;
	graCnt = 0;
	EnrollmentRec = new EnrollmentRecs[MAX_NUM];
}

//destructor
Enrollment::~Enrollment ()
{
	//delete
	delete [] EnrollmentRec;
}

//load enrollment table from tab;e
void Enrollment::LoadEnrollmentTableFromFile(int Pos)
{
	fstream file;

	//open the file in write, append mode
	file.open("GradeBook.txt", ios::in);
	
	//error if can't open file
	if(file.fail())
	{
		cout << "Error in LoadCourseTableFromFile opening file !!!" << endl;
		return;
	}
	//get info of where left off
	file.seekg (Pos, ios::beg);
	for (int i = 0; i < Cnt; i++)
	{
		//write the record to the file as append
		file.read((char *) &EnrollmentRec[i], sizeof (EnrollmentRecs));
	}

	file.close();
}

//display enrollment
void Enrollment::DisplayEnrollment (void)
{
	cout << "Enrollment::DisplayEnrollment Cnt = " << Cnt << endl;

	//display enrollemnts
	for (int i = 0; i < Cnt; i++)
	{
		EnrollmentRec[i].DisplayEnrollmentRec();
	}
}

//add new enrollment
void Enrollment::NewEnrollment (int sID, int cID)
{
	//get enrollment info
	cout << "Enter enrollment ID: ";
	cin >> EnrollmentID;

	StuID = sID;
	CourseID = cID;
/*
      cout << "Student ID:  ";
      cin >> StuID;

	  cout << "Enter Course ID: ";
      cin >> CourseID;
*/

	cout << "Enter How many grades (Total Num of Grade not exceed to 10): ";
	cin >> graCnt;

	//max 10 grades
	if (graCnt > 10)
		graCnt = 10;

	//get grades
	cout << "Grade ";
	for (int i = 0; i < graCnt; i++)
	{
		cin >> Grades[i];
	}
		cout << endl;

	AddRecord ();
}


//dump info into file
void Enrollment::DumpEnrollmentTableToFile ()
{
	fstream file;

	//open the file in write, append mode
	//file.open("GradeBook.txt", ios::out | ios::app);
	file.open("GradeBook.txt");
	//if cant open, error message	
	if(file.fail())
	{
		cout << "Error in AddRecord opening file !!!" << endl;
		return;
	}
	
	for (int i = 0; i < Cnt; i++)
	{
		//write the record to the file
		file.write((char *) &EnrollmentRec[i], sizeof (EnrollmentRecs));
	}

	file.close();
}

//add record to enrollment
void Enrollment::AddRecord ()
{
	//add enrollment
	EnrollmentRec[Cnt].AddEnrollmentRec (EnrollmentID, StuID, CourseID, Grades, graCnt, Cnt);
	//calculate grade
	EnrollmentRec[Cnt].CalcGrade();
	if (Cnt < MAX_NUM)
		Cnt++;
}

/*
int Enrollment::CheckDuplicate ()
{
	int Found = 0;
	for (int i=0; i<Cnt; i++)
	{
		if (EnrollmentRec[i].GetEID() == EnrollmentID)
		{
			//cout<< "EnrollmentID duplicate found in Memory " << EnrollmentID << endl;
			// Duplicate found
			Found = 1;
			break;
		}
	}

	return Found;
}
*/
//print grades for student
void Enrollment::PrintGradesforStudent ()
{
	//initialize to 0
	int sID, cID, index=0;
	int Found = 0;

	//enter id
	cout << "Enter Student ID: ";
	cin >> sID;

	//check for sID
	for (int i = 0; i < Cnt; i++)
	{
		if (EnrollmentRec[i].GetSID() == sID)
		{
			Found = 1;
			break;
		}
	}

	//output corresponding message to id
	if (!Found)
	{
		cout << "Student ID not Found, Cannot print grades to this Student ID " << sID << endl;
	}
	else
	{
		cout << "Enter Course ID: ";
		cin >> cID;

		Found = 0;
		//check for cID
		for (int i = 0; i < Cnt; i++)
		{
			if (EnrollmentRec[i].GetCID() == cID)
			{
				Found = 1;
				index = i;
				break;
			}
		}

		//coutput corresponding info for course id
		if (!Found)
		{
			cout << "Course ID not Found, Cannot print grades to this student course ID " << cID << endl;
		}
		else
		{
			//all pass, now Print grades
			EnrollmentRec[index].PrintGrades();
		}
	}
}

//find course avg
void Enrollment::ComputeAvgForCourse ()
{
	//initializers to 0
	int cID;
	int cIDCnt = 0;
	float TotalAvg = 0.0;

	//enter course and get info
	cout << "Enter Course ID: ";
	cin >> cID;

	//for total num of enrollment
	for (int i = 0; i < Cnt; i++)
	{
		if (EnrollmentRec[i].GetCID() == cID)
		{
			cIDCnt++;			
			TotalAvg += EnrollmentRec[i].GetGradeAvg();
		}
	}

	//output course avg
	if (cIDCnt)
		cout << "Grade Average for a course CID " << cID << " is " << TotalAvg/cIDCnt << endl;
}

//print all students in course
void Enrollment::PrintAllStudentinCourse ()
{
	int cID;

	//enter course ID
	cout << "Enter Course ID: ";
	cin >> cID;

	//for total num of enrollment
	for (int i = 0; i < Cnt; i++)
	{
		if (EnrollmentRec[i].GetCID() == cID)
		{
			//all pass, now Print Student IDs
			EnrollmentRec[i].PrintStudent();
		}
	}
}

//add grades for students in course
void Enrollment::AddGradesForStudentinCourse ()
{
	//initializers
	int sID, cID, index = 0;
	int Found = 0;

	//enter student ID
	cout << "Enter Student ID: ";
	cin >> sID;

	//check for sID
	for (int i = 0; i < Cnt; i++)
	{
		if (EnrollmentRec[i].GetSID() == sID)
		{
			Found = 1;
			break;
		}
	}

	if (!Found)
	{
		cout << "Student ID not Found, Cannot add grades to this Student ID " << sID << endl;
	}
	else
	{
		cout << "Enter Course ID: ";
		cin >> cID;

		Found = 0;
		//check for cID
		for (int i = 0; i < Cnt; i++)
		{
			if (EnrollmentRec[i].GetCID() == cID)
			{
				Found = 1;
				index = i;
				cout << "Index " << index << endl;
				break;
			}
		}

		if (!Found)
		{
			cout << "Course ID not Found, Cannot add grades to this student course ID " << cID << endl;
		}
		else
		{
			// All pass, now add grades
		    	int CurrGraCnt = EnrollmentRec[index].GetGraCnt ();
			cout << "Current grade CNT " << CurrGraCnt << endl;

            	if (CurrGraCnt < 10)
			{
				//get grade count
				int gCnt;
				cout << "Enter How many grades: Total < 10: ";
				cin >> gCnt;

				//cant input more than 10 grades
				if ((gCnt + CurrGraCnt) > 10)
				{
					cout << "Num of grades exceed 10" << endl;
					graCnt = 10;
				}

				//enter new grade and count
	            		cout << "New Grade ";
				for (int i = CurrGraCnt; i < (CurrGraCnt + gCnt); i++)
				{
					cin >> Grades[i];
				}
				gCnt = CurrGraCnt + gCnt;
				cout << "New grade count " << gCnt << endl;
				EnrollmentRec[index].AddEnrollmentGrade (Grades, gCnt);
				//update grade AVG and Letter grade
				EnrollmentRec[index].CalcGrade();
			}
			else
			{
				//cant write more than 10 grades
				cout << "Your grade exceed limit of 10, cannot add grade!!" << endl;
			}
		}
	}
}

