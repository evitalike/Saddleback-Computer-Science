#pragma once
#include "GradedActivity.h";

class PassFailActivity : public GradedActivity
{
protected:
	double minPassingScore;
public:
	PassFailActivity();
	PassFailActivity(double mps);
	~PassFailActivity();
	void setMinPassingScore(double mps);
	double getMinPassingScore();
	virtual char getLetterGrade();
};