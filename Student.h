/*
        Name: Connie Xu
        Course: CSCE II 1040
        Teacher: Keathly
        Assignment: Homework 2
*/
#include "StudentRec.h"

#define MAX_NUM  100

//class for student
class Student
{
	private:
		int StuID;	//student ID
		char StuName[40];	//student name
		int NumOfClassEnrolled;	//number of classes enrolled
		char StuClassification[40];	//student classification

		//counter
		int Cnt;
		//for memory
		void AddRecord ();

	public:
		//constrcutor
		Student ();
		//destructor
		~Student ();

		//pointer
		StudentRecs *StudentRec;

    		//add A New Student
    		void NewStudent (void);
		//display student
		void DisplayStudent (void);
		//check if student ID found
		int CheckStuIDFound (int);
		//put into file
		void DumpStudentTableToFile ();
		//take frm file
		void LoadStudentTableFromFile (int Pos);
		//get location from file
		int GetPos ();
};
