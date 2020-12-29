/*
        Name: Connie Xu
        Course: CSCE II 1040
        Teacher: Keathly
        Assignment: Homework 2
*/
#include "CourseRec.h"

#define MAX_NUM  100

//student course class
class studentCourse
{
	private:
		int  CID;	//course id
        	char cName[40];	//course name
		char cLocation[40];	//location
		int  Cnt;	//counter
		int EnrollCap;	//enrollment cap
		char MeetTime[40];	//meeeting time

		//for file
		//void AddRecordFile (int, char[], char [], char[]);
		//int CheckCIDDuplicateFile (int Cid);

		//for memory
		void AddRecord (int, char[], char [], char[]);

	public: 
		//constructor   
		studentCourse ();
		//destructor
		~studentCourse ();
		CourseRecords *CourseRec;	//pointer

    		//add a new course
    		void NewCourse (void);
		//display record
		void DisplayRecord (void);
		//course ID found
		int CourseIDFound (int);
		//void DisplayRecordFile (void);
		//dump to file
		void DumpCourseTableToFile ();
		//load from file
		void LoadCourseTableFromFile (int Pos);
		//return info on course record location for file
		int GetPos ()
		{
			return (Cnt * sizeof (CourseRecords));
		};
};

