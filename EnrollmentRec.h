/*
        Name: Connie Xu
        Course: CSCE II 1040
        Teacher: Keathly
        Assignment: Homework 2
*/
//class for enrollment recs
class EnrollmentRecs
{
	private:
		int EnrollmentID;	//enrollment ID
		int StuID;	//student ID
		int CourseID;	//course ID
		int Grades[10];	//grades array
		float AvgGrade;	//avg grade
		char LetterGrade;	//letter grade
	
		//counters
		int graCnt;
		int Cnt;

	public:
		//constructor
		EnrollmentRecs ();
		//add enrollment record
		void AddEnrollmentRec (int eID, int sID, int cID, int Gra[10], int gcnt, int Count);
		//add enrollmrn grade
		void AddEnrollmentGrade (int Gra[10], int gcnt);
		//get enrollment ID
		int GetEID ();
		//get student ID
		int GetSID ();
		//get course ID
		int GetCID ();
		//get grade count
		int GetGraCnt ();
		//get grade avg
		float GetGradeAvg ();
		//calculate grade
		void CalcGrade ();

		//print grades
		void PrintGrades (void);
		//print students
		void PrintStudent (void);
		//prnt enrollment records
		void DisplayEnrollmentRec (void);
};
