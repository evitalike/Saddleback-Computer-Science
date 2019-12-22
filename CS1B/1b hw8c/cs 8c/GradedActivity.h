#pragma once

class GradedActivity
{
protected:
	double score;
public:
	GradedActivity();
	GradedActivity(double testScore);
	~GradedActivity();
	void setScore(double testScore);
	double getScore();
	virtual char getLetterGrade();
};