#include "PassFailExam.h"

PassFailExam::PassFailExam()
{
	numQuestions = 0.0;
	pointsEach = 0.0;
	numMissed = 0.0;
}

PassFailExam::PassFailExam(int questions, int missed, double mps) : PassFailActivity(mps)
{
	set(questions, missed);
}

PassFailExam::~PassFailExam()
{
}

void PassFailExam::set(int questions, int missed)
{
	double numericScore;  	// To hold the numeric score

   // Set the number of questions and number missed.
	numQuestions = questions;
	numMissed = missed;

	// Calculate the points for each question.
	pointsEach = 100.0 / numQuestions;

	// Calculate the numeric score for this exam.
	numericScore = 100.0 - (missed * pointsEach);

	// Call the inherited SetScore function to set the numeric score.
	setScore(numericScore);
}

double PassFailExam::getNumQuestions()
{
	return numQuestions;
}

double PassFailExam::getPointsEach()
{
	return pointsEach;
}

double PassFailExam::getNumMissed()
{
	return numMissed;
}
