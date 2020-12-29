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

#include "EnrollmentRec.h"

//constrcutor
EnrollmentRecs::EnrollmentRecs ()
{
	//initialize grades
	graCnt = 0;
	Cnt = 0;
}

//add enrollment recs
void EnrollmentRecs::AddEnrollmentRec (int eID, int sID, int cID, int Gra[10], int gcnt, int Count)
{
	cout << "AddEnrollmentRec EnrollmentRecs called" << endl;
		
	//update enrollment info
     	EnrollmentID = eID;
	StuID = sID;
	CourseID = cID;
	graCnt = gcnt;
	for (int i = 0; i < gcnt; i++)
	{
		Grades[i] = Gra[i];
	}

	Cnt = Count;
}

//add enrollment grade
void EnrollmentRecs::AddEnrollmentGrade (int Gra[10], int gcnt)
{
	//get new info for enrollment
	graCnt = gcnt;
	for (int i = 0; i < gcnt; i++)
	{
		cout << "New Grade " << Gra[i] << endl;

		Grades[i] = Gra[i];
	}
}

//get enrollment ID
int EnrollmentRecs::GetEID ()
{
	return EnrollmentID;
}

//get student ID
int EnrollmentRecs::GetSID ()
{
	return StuID;
}

//get co//urse ID
int EnrollmentRecs::GetCID ()
{
	return CourseID;
}

//get grade counter
int EnrollmentRecs::GetGraCnt ()
{
	return graCnt;
}

//get grafe average
float EnrollmentRecs::GetGradeAvg ()
{
	return AvgGrade;
}

//calculate grade
void EnrollmentRecs::CalcGrade ()
{
	//initialize sum
	int Sum = 0;
	//get sum
	for (int i = 0; i < graCnt; i++)
	{
		Sum += Grades[i];
	}
	//calculate average
	AvgGrade = (float) (Sum/graCnt);

	//find letter grade
	if (AvgGrade >= 90)
		LetterGrade = 'A';
	else
    	if ((AvgGrade < 90) && (AvgGrade >= 80))
		LetterGrade = 'B';
	else
    	if ((AvgGrade < 80) && (AvgGrade >= 70))
		LetterGrade = 'C';
	else
	if ((AvgGrade < 70) && (AvgGrade >= 60))
		LetterGrade = 'D';
	else
		LetterGrade = 'F';
}

//print grades
void EnrollmentRecs::PrintGrades (void)
{
	//get course and student ID
        cout << " Student ID = " << StuID << endl ;
	cout << " Course ID = " << CourseID << endl;

	//print grades
	cout << " Grades = ";
	for (int i = 0; i < graCnt; i++)
        cout << "  " << Grades[i];
	cout << endl;
}

//print students
void EnrollmentRecs::PrintStudent (void)
{
      	cout << " Student ID = " << StuID << endl;
}

//print enrollments records
void EnrollmentRecs::DisplayEnrollmentRec (void)
{
	cout << "DisplayEnrollmentRec EnrollmentRecs called" << endl;

	//display info
	cout << endl << " Enrollment ID = " << EnrollmentID << endl;
      	cout << " Student ID = " << StuID << endl ;
	cout << " Course ID = " << CourseID << endl;

	cout << " Grades = ";
	for (int i = 0; i < graCnt; i++)
        	cout << "  " << Grades[i];
	cout << endl;

	cout << " Avg Grade = " << AvgGrade << endl;
	cout << " Letter Grade = " << LetterGrade << endl << endl;
}
