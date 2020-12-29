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

#include "Course.h"

//constructor
studentCourse::studentCourse ()
{
	//initializers and memory allocation	
	Cnt = 0;
	EnrollCap = 0;
	CourseRec = new CourseRecords[MAX_NUM];
}

//destrcutor
studentCourse::~studentCourse ()
{
	//delete memory	
	delete [] CourseRec;
}

//check for CID duplicate
/*
int studentCourse::CheckCIDDuplicateFile (int Cid)
{
	fstream file;
	int Found = 0;

	file.open ("StudentRecord.txt", ios::in);

	if(!file)
    	{
		cout<<"File does not exist"<<endl;
	   	Found = 2;
	   	return Found;
	} 

	//seek to beginning of file
	file.seekg (0, ios::beg);
	while (file.read((char *)this, sizeof (studentCourse)))
	{
       		cout<<"Read from file CID " << CID << endl;
       		if (Cid == CID)
	   	{
			//cout<< "CID duplicate found " << Cid << endl;
		   	Found = 1;
		   	break;
	   	}
	}

	file.close ();
	return Found;
}
*/

//adds the given data in the course table
void studentCourse::AddRecord (int Cid, char cN[40], char cLoc[40], char MT[40])
{
	//finding course ID
	int Found = CourseIDFound (Cid);
	//if found, print error
	if (Found == 1)
	{
		cout << endl << "CID Found in Table, Do not add it to record" << endl << endl;
		return;
	}
	
	//counter for enrollment cap
	if (EnrollCap < 48)
		EnrollCap++;

	//add course
	CourseRec[Cnt].AddCourseRec(Cid, cN, cLoc, MT, Cnt, EnrollCap);

	//if counter is less than 100, increment
	if (Cnt < MAX_NUM)
		Cnt++;
}

//check duplicate in Course memory
int studentCourse::CourseIDFound (int Cid)
{
	//find ID
	int Found = 0;
	//go through list to find course ID
	for (int i = 0; i < Cnt; i++)
	{
		//print found id if found
		if (CourseRec[i].GetCID() == Cid)
		{
			cout<< "Course ID found in Table " << Cid << endl;
			// found
			Found = 1;
			break;
		}
	}

	return Found;
}

//this function displays the list of courses from memory
void studentCourse::DisplayRecord()
{
	cout << "studentCourse::DisplayRecord Cnt = " << Cnt << endl;
	
	//for loop to display course rec
	for (int i = 0; i < Cnt; i++)
	{
		CourseRec[i].DisplayCourseRec();
	}
}

//dump course to file
void studentCourse::DumpCourseTableToFile()
{
	fstream file;

	//open the file in write, append mode
	file.open("GradeBook.txt", ios::app);	//ios::out | ios::app);
	//file.open("GradeBook.txt");
	//if can't open print error
	if(file.fail())	//!file
	{
		cout << "Error in DumpCourseTableToFile opening file !!!" << endl;
		return;
	}

	for (int i = 0; i < Cnt; i++)
	{
		//write the record to the file as append
		file.write((char *) &CourseRec[i], sizeof (CourseRecords));
	}
	//close file
	file.close();
}

//load course to table from file
void studentCourse::LoadCourseTableFromFile(int Pos)
{
	fstream file;

	//open file
	file.open("GradeBook.txt");	//, ios::in);
	//if can't open print error
	if(file.fail())	//!file
	{
		cout << "Error in LoadCourseTableFromFile opening file !!!" << endl;
		return;
	}

	//find Pos
	file.seekg (Pos, ios::beg);
	for (int i = 0; i < Cnt; i++)
	{
		//write the record to the file as append
		file.read((char *) &CourseRec[i], sizeof (CourseRecords));
	}

	file.close();
}

//adds the given data in the course file
/*
void studentCourse::AddRecordFile (int Cid, char cN[40], char cLoc[40], char MT[40])
{
	fstream file;
	int Found = false;

	Found = CheckCIDDuplicateFile (Cid);
	if (Found == 1)
	{
		cout << "\nCid Duplicate Found, Do not add it to record" << endl << endl;
	}
	else
	{
		//open the file in write, append mode
		file.open("StudentRecord.txt", ios::out | ios::app);
		if(!file)
		{
			cout<<"Error in AddRecord opening file !!!"<<endl;
			return;
		}

	    CID = Cid;
        strcpy (cName, cN);
		strcpy (cLocation, cLoc);
		Cnt++; 
		EnrollCap++;
		strcpy (MeetTime, MT);

   	    //cout << "AddRecord CID added to file = " << CID << endl;
   	    //cout << "AddRecord Counter added to file = " << Cnt << endl;
		//cout << "cName = " << cName << endl;

		//write the record to the file as append
		file.write((char *) this, sizeof (studentCourse));
		file.close();
	}
}
*/
//displays the list of courses
/*
void studentCourse::DisplayRecordFile()
{
	fstream file;
	file.open ("StudentRecord.txt", ios::in);

    if(!file)
    {
       cout << "Error in DisplayRecord opening file !!!"<<endl;
       return;
    }

	cout << "\nDisplay Course ID Record:\n";
	//seek to beginning of file
	file.seekg (0, ios::beg);
	while (file.read((char *)this, sizeof (studentCourse)))
	{
	  cout << " Course ID = " << CID << endl;
      cout << " Course Name = " << cName << endl ;
	  cout << " Course Loc = " << cLocation << endl;
      cout << " Counter = " << Cnt << endl;
	  cout << " Enroll Cap = " << EnrollCap << endl;
	  cout << " MeetTime = " << MeetTime << endl << endl;
	}

	file.close ();
}
*/
//add a new course
void studentCourse::NewCourse ()
{
	int CourseID;	//course ID
	char CourseName[40];	//course name
	char cLoc[40];	//course location
	char MT[40];	//meeting time

	//enter info and retrieve info
	cout << "Enter Course ID: ";
	cin >> CourseID;

    	cout << "Enter Course Name (NO spaces): ";
    	cin >> CourseName;

	cout << "Enter Course Location: ";
	cin.ignore(); //check    
	cin >> cLoc;

	cout << "Enter Meet Time (Ex input: 11:00AM-12:00PM -- NO spaces): ";
    	cin >> MT;

	//add info to record
    	AddRecord (CourseID, CourseName, cLoc, MT);
}
