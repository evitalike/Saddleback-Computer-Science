// Attached: HW_2a, 2b, 2c, 2d
// ===================================================
// Program: HW_2d
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int ROWS = 5;
const int COLS = 3;

void readGrades(char grades[][COLS]);
void displayGrades(char grades[][COLS]);
void displayGPAs(char grades[][COLS]);
void displayAvgGrades(char grades[][COLS]);

int main()
{
	char grades[ROWS][COLS] = { 0 };

	readGrades(grades);
	displayGrades(grades);
	displayGPAs(grades);
	displayAvgGrades(grades);

	system("pause");
	return 0;
}

void readGrades(char grades[][COLS])
{
	ifstream inFile;
	inFile.open("C:\\Users\\roverdog\\source\\repos\\hw 2d\\hw 2d\\grades.dat");
	if (inFile.fail())
	{
		cout << "Unable to open file datafile.txt\n";
		system("pause");
		exit(1);
	}
	while (!inFile.eof())
	{
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				inFile >> grades[row][col];
			}
		}
	}
	inFile.close();
}

void displayGrades(char grades[][COLS])
{
	int student = 1;

	cout << "All Grades:\n";
	cout << left << setw(10) << "Student" << setw(10) << "English" << setw(10) << "History" << setw(10) << "Math" << endl;
	for (int row = 0; row < ROWS; row++)
	{
		cout << left << '#' << setw(9) << student;
		student++;
		for (int col = 0; col < COLS; col++)
		{
			cout << setw(10) << grades[row][col];
		}
		cout << endl;
	}
	cout << endl;
}

void displayGPAs(char grades[][COLS])
{
	float sum = 0;
	int student = 1;

	cout << "Student GPAs:\n"
		<< "Student\n";
	
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			if (grades[row][col] == 'A')
			sum = sum + 4;
			if (grades[row][col] == 'B')
				sum = sum + 3;
			if (grades[row][col] == 'C')
				sum = sum + 2;
			if (grades[row][col] == 'D')
				sum = sum + 1;
		}
		cout << fixed << setprecision(2) << '#' << setw(9) << student << sum / 3 << endl;
		sum = 0;
		student++;
	}
	cout << endl;
}

void displayAvgGrades(char grades[][COLS])
{
	float sum = 0;

	cout << "Average GPA by subject:\n"
		<< setw(10) << "English" << setw(10) << "History" << setw(10) << "Math" << endl;

	for (int col = 0; col < COLS; col++)
	{
		for (int row = 0; row < ROWS; row++)
		{
			if (grades[row][col] == 'A')
				sum = sum + 4;
			if (grades[row][col] == 'B')
				sum = sum + 3;
			if (grades[row][col] == 'C')
				sum = sum + 2;
			if (grades[row][col] == 'D')
				sum = sum + 1;
		}
		cout << fixed << setprecision(2) << setw(10) << sum / 5;
		sum = 0;
	}
	cout << endl << endl;
}

// ===================================================
/* OUTPUT:
All Grades:
Student   English   History   Math
#1        A         A         B
#2        C         C         F
#3        C         D         B
#4        B         A         C
#5        B         A         B

Student GPAs:
Student
#1        3.67
#2        1.33
#3        2.00
#4        3.00
#5        3.33

Average GPA by subject:
English   History   Math
2.80      3.00      2.20

Press any key to continue . . .
*/
// ===================================================