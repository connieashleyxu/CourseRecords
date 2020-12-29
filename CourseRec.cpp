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

#include "CourseRec.h"

//constrcutor
CourseRecords::CourseRecords ()
{
	//initializer	
	Cnt = 0;
	EnrollCap = 0;
}

//add course record
void CourseRecords::AddCourseRec (int cid, char cN[40], char cLoc[40], char MT[40], int cnt, int EC)
{
	cout << "AddCourseRec CourseRecords called" << endl;

	//update course recs
	CID = cid;
	strcpy (cName, cN);
	strcpy (cLocation, cLoc);
	strcpy (MeetTime, MT);
	Cnt = cnt;
	EnrollCap = EC;
}

//get course ID
int CourseRecords::GetCID ()
{
	return CID;
}

//display course recs
void CourseRecords::DisplayCourseRec (void)
{
	cout << "DisplayCourseRec CourseRecords called" << endl;

	//display course records and info
	cout << endl << " Course ID = " << CID << endl;
        cout << " Course Name = " << cName << endl ;
	cout << " Course Loc = " << cLocation << endl;
        cout << " Counter = " << Cnt << endl;
	cout << " Enroll Cap = " << EnrollCap << endl;
	cout << " MeetTime = " << MeetTime << endl << endl;
}
