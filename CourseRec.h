/*
        Name: Connie Xu
        Course: CSCE II 1040
        Teacher: Keathly
        Assignment: Homework 2
*/
//class for course records
class CourseRecords
{
	private:
		int  CID;	//course ID
        	char cName[40];	//name
		char cLocation[40];	//location
		int  Cnt;	//counter
		int  EnrollCap;	//cap
		char MeetTime[40];	//meeting time
	public:
		//constructor
		CourseRecords ();
		//add course record
		void AddCourseRec (int cid, char cN[40], char cLoc[40], char MT[40], int cnt, int EC);
		//get CID
		int GetCID ();
		//display course rec
		void DisplayCourseRec (void);
};
