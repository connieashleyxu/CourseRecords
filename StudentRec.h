/*
        Name: Connie Xu
        Course: CSCE II 1040
        Teacher: Keathly
        Assignment: Homework 2
*/
//class for students
class StudentRecs
{
	private:
		int StuID;	//student ID
		char StuName[40];	//student name
		int NumOfClassEnrolled;	//num class enrolled
		char StuClassification[40];	//student type

		//counter
		int Cnt;

	public:
		//constructor
		StudentRecs ();

		//add student record
		void AddStudentRec (int sID, char sName[40], int NumClassEnroll, char sClassification[40], int Count);

		//get student ID
		int GetSID ();
		//print student record
		void DisplayStudentRec (void);
};
