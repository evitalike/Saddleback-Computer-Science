#include "GradedActivity.h"

GradedActivity::GradedActivity()
{
	score = 0;
}

GradedActivity::GradedActivity(double testScore)
{
	score = testScore;
}

GradedActivity::~GradedActivity()
{
}

void GradedActivity::setScore(double testScore)
{
	score = testScore;
}

double GradedActivity::getScore()
{
	return score;
}

char GradedActivity::getLetterGrade()
{
	if (score >= 90)
		return 'A';
	else if (score >= 80)
		return 'B';
	else if (score >= 70)
		return 'C';
	else if (score >= 60)
		return 'D';
	else
		return 'F';
}
