/*
        Name: Connie Xu
        Course: CSCE II 1040
        Teacher: Keathly
        Assignment: Homework 2
*/
#include "EnrollmentRec.h"

#define MAX_NUM  100

class Enrollment
{
	private:
		int EnrollmentID;	//enrollment ID
		int StuID;	//student ID
		int CourseID;	//course ID
		int Grades[10];	//grades array
		float AvgGrade;	//avg grade
		char LetterGrade;	//letter grade

		//counters
		int Cnt;
		int graCnt;

		//for memory
		void AddRecord ();
		//int CheckDuplicate ();
	public:
		//constructor
    		Enrollment ();
		//destructor
		~Enrollment ();
		//pointer
		EnrollmentRecs *EnrollmentRec;

    		//add a new enrollment
    		void NewEnrollment (int, int);
		//display enrollment
		void DisplayEnrollment (void);
		//add grades for student
		void AddGradesForStudentinCourse (void);
		//print grades for student
		void PrintGradesforStudent (void);
		//print all student roster
		void PrintAllStudentinCourse (void);
		//get avg
		void ComputeAvgForCourse ();
		//dump into file
		void DumpEnrollmentTableToFile ();
		//get info from file
		void LoadEnrollmentTableFromFile (int Pos);
		//get info of file location
		int GetPos ()
		{	
			return (Cnt * sizeof (EnrollmentRecs));
		};
};
