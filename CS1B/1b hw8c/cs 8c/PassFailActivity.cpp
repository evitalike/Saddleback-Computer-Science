#include "PassFailActivity.h"

PassFailActivity::PassFailActivity()
{
	minPassingScore = 0;
}

PassFailActivity::PassFailActivity(double mps)
{
	minPassingScore = mps;
}

PassFailActivity::~PassFailActivity()
{
}

void PassFailActivity::setMinPassingScore(double mps)
{
	minPassingScore = mps;
}

double PassFailActivity::getMinPassingScore()
{
	return minPassingScore;
}

char PassFailActivity::getLetterGrade()
{
	if (score >= minPassingScore)
		return 'P';
	else
		return 'F';
}