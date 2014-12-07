/***************************************************************************************************
 ** Author:         Benjamin Hobbs
 ** Date Created:   2/4/2014
 ** Lab/Project#:   Ex. 8 Problem 2
 ** Filename:       gradingProgram
 ** Overview: 	    This program will create a class record for n students, allow the user to enter
 **                 grades, then output the grade by student.
 **
 **                 grading scheme:     2 quizzes (worth 10 pts each)   25% of grade
 **                                     1 midterm (worth 100 pts)       25% of grade
 **                                     1 final   (worth 100 pts)       50% of grade
 **
 ** Input:  		number of students, grades for each student
 ** Output: 		calculated grades for each student
 ** References:		...
***************************************************************************************************/

#include <iostream>	    //std::cout, std::cin

struct Grades
{
    int quiz_1, quiz_2, exam_1, exam_2;
    double classPercentage;
    char grade;
};

void getGrades(Grades &student);
void calculateGrade(Grades &student);
void printStudentRecord(Grades &student);

int main()
{
    Grades student = {0,0,0,0}; //create instance of grades called student

    getGrades(student);
    calculateGrade(student);
    printStudentRecord(student);

    return 0;
}


/**************************************************************************************************
 ** Function:       getGrades
 ** Description:    Gets user input for each grade
 ** Input:          User Input (grades)
 ** Output:         grades by reference
 *************************************************************************************************/
void getGrades(Grades &student)
{
    std::cout << "Please enter the following grades\n\nQuiz 1 (10 pts possible): ";
    std::cin >> student.quiz_1;

    std::cout << "Quiz 2 (10 pts possible): ";
    std::cin >> student.quiz_2;

    std::cout << "Midterm Exam (100 pts possible): ";
    std::cin >> student.exam_1;

    std::cout << "Final Exam (100 pts possible): ";
    std::cin >> student.exam_2;
}


/**************************************************************************************************
 ** Function:       calculateGrades
 ** Description:    takes student record and calculates final % and letter grade
 ** Input:          grades by reference
 ** Output:         grades by reference
 *************************************************************************************************/
void calculateGrade(Grades &student)
{
    double quizPercentage = 12.5, midtermPercentage = 25.0, finalPercentage = 50.0;

    student.classPercentage += ((student.quiz_1 / 10.0) * quizPercentage);   //quiz 1 to %, add to total %
    student.classPercentage += ((student.quiz_2 / 10.0)* quizPercentage);   //quiz 2 to %, add to total %
    student.classPercentage += ((student.exam_1 / 100.0) * midtermPercentage);   //ex_1 to %, add to total %
    student.classPercentage += ((student.exam_2 / 100.0)* finalPercentage);   //ex_2 to %, add to total %

    if (student.classPercentage >= 90){student.grade = 'A';}
    else if (student.classPercentage >= 80 && student.classPercentage < 90){student.grade = 'B';}
    else if (student.classPercentage >= 70 && student.classPercentage < 80){student.grade = 'C';}
    else if (student.classPercentage >= 60 && student.classPercentage < 70){student.grade = 'D';}
    else if (student.classPercentage < 60){student.grade = 'F';}
}


/**************************************************************************************************
 ** Function:       printStudentRecord
 ** Description:    Prints Student Record
 ** Input:          student of type Grades (by Ref)
 ** Output:         student of type Grades (by Ref), Text
 *************************************************************************************************/
void printStudentRecord(Grades &student)
{
    std::cout << "Student Record\n\nQuiz 1: " << student.quiz_1 << "/10\nQuiz 2: "
              << student.quiz_2 << "/10\n\nMidterm Exam: " << student.exam_1
              << "/100\nFinal Exam: " << student.exam_2 << "/100\n\nClass Percentage: "
              << student.classPercentage << "\nGrade: " << student.grade << std::endl;
}
