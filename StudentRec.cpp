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

#include "StudentRec.h"

//constrcutor
StudentRecs::StudentRecs ()
{
	//initilaize
	Cnt = 0;
}

//add student records
void StudentRecs::AddStudentRec (int sID, char sName[40], int NumClassEnroll, char sClassification[40], int Count)
{
	cout << "AddStudentRec StudentRecs called" << endl;

	//update student info
        StuID = sID;
	strcpy (StuName, sName);
	NumOfClassEnrolled = NumClassEnroll;
	strcpy (StuClassification, sClassification);
	Cnt = Count;
}

//get student id
int StudentRecs::GetSID ()
{
	return StuID;
}

//print student records
void StudentRecs::DisplayStudentRec (void)
{
	cout << "DisplayStudentRec EnrollmentRecs called" << endl;

	cout << endl << " Student ID = " << StuID << endl;
	cout << " Student Name = " << StuName << endl ;
	cout << " Num of Class Enrolled = " << NumOfClassEnrolled << endl;
	cout << " Student Classification = " << StuClassification << endl << endl;
}
