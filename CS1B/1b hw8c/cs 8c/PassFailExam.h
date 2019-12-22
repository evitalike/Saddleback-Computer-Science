#pragma once
#include "PassFailActivity.h";

class PassFailExam : public PassFailActivity
{
private:
	int numQuestions;
	double pointsEach;
	int numMissed;
public:
	PassFailExam();
	PassFailExam(int questions, int missed, double mps);
	~PassFailExam();
	void set(int questions, int missed);
	double getNumQuestions();
	double getPointsEach();
	double getNumMissed();
};