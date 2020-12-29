Hw2make.exe : Hw2Main.o Course.o CourseRec.o Enrollment.o EnrollmentRec.o Student.o StudentRec.o
	g++ Hw2Main.o Course.o CourseRec.o Enrollment.o EnrollmentRec.o Student.o StudentRec.o -o Hw2make.exe

Hw2Main.o : Hw2Main.cpp Course.cpp CourseRec.cpp Enrollment.cpp EnrollmentRec.cpp Student.cpp StudentRec.cpp
	g++ -c Hw2Main.cpp

Course.o : Course.cpp Course.h
	g++ -c Course.cpp

CourseRec.o : CourseRec.cpp CourseRec.h
	g++ -c CourseRec.cpp

Enrollment.o : Enrollment.cpp Enrollment.h
	g++ -c Enrollment.cpp

EnrollmentRec.o : EnrollmentRec.cpp EnrollmentRec.h 
	g++ -c EnrollmentRec.cpp

Student.o : Student.cpp Student.h
	g++ -c Student.cpp

StudentRec.o : StudentRec.cpp StudentRec.h
	g++ -c StudentRec.cpp

clean:
	rm *.o Hw2make.exe

run:
	./Hw2make.exe
