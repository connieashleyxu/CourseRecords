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

#include "Student.h"

//constructor
Student::Student ()
{
	//initialize counters and memory
	Cnt = 0;
	StudentRec = new StudentRecs[MAX_NUM];
}

//destructor
Student::~Student ()
{
	//remove memory
	delete [] StudentRec;
}

//add records
void Student::AddRecord ()
{
	//find student ID
	int Found = CheckStuIDFound (StuID);
	if (Found == 1)
	{
		//error if already exists
		cout << endl << "Student ID Duplicate Found in Table, Do not add it to record" << endl << endl;
		return;
	}

	//can't enroll in more than 5 courses
	if (NumOfClassEnrolled > 5)
	{
		cout << endl << "Student Num of Class Enrolled more than 5, Exceed limit 5, Do not add it to record" << endl << endl;
		return;
	}

	//add student record and update count
	StudentRec[Cnt].AddStudentRec (StuID, StuName, NumOfClassEnrolled, StuClassification, Cnt);
	if (Cnt < MAX_NUM)
		Cnt++;
}

//check student id found
int Student::CheckStuIDFound (int sID)
{
	//find student ID
	int Found = 0;
	for (int i = 0; i < Cnt; i++)
	{
		if (StudentRec[i].GetSID() == sID)
		{
			//cout << "Student ID duplicate found in Memory " << StuID << endl;
			//duplicate found
			Found = 1;
			break;
		}
	}

	return Found;
}

//dump info to file
void Student::DumpStudentTableToFile()
{
	fstream file;

	//open the file in write, append mode
	file.open("GradeBook.txt", ios::out | ios::app);
	if(file.fail())
	{
		//error if can't open file
		cout << "Error in DumpStudentTableToFile opening file !!!" << endl;
		return;
	}

	for (int i = 0; i < Cnt; i++)
	{
		//write the record to the file as append
		file.write((char *) &StudentRec[i], sizeof (StudentRecs));
	}

	file.close();
}

//add new student
void Student::NewStudent (void)
{
	//get info for student and input
	cout << "Enter Student ID: ";
	cin >> StuID;

      	cout << "Enter Student Name (Enter as Last,First -- NO spaces) :  ";
      	cin >> StuName;

	cout << "# of Classes Enrolled: ";
      	cin >> NumOfClassEnrolled;

	cout << "Enter Student Classification: ";
      	cin >> StuClassification;

	cout << endl;

	AddRecord ();
}

//display student; print info
void Student::DisplayStudent (void)
{
	for (int i = 0; i < Cnt; i++)
	{
		StudentRec[i].DisplayStudentRec();
	}
}

//load info from table
void Student::LoadStudentTableFromFile (int Pos)
{
	fstream file;

	file.open("GradeBook.txt", ios::in);
	if(file.fail())
	{
		//output error if can't open
		cout << "Error in LoadStudentTableFromFile opening file !!!" << endl;
		return;
	}

	//get location of data in file
	file.seekg (Pos, ios::beg);
	for (int i = 0; i < Cnt; i++)
	{
		//read the record from the file
		file.read((char *) &StudentRec[i], sizeof (StudentRecs));
	}

	file.close();
}

//get location of info for file
int Student::GetPos ()
{
		return (Cnt * sizeof (StudentRecs));
}
