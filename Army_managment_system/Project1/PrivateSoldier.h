#pragma once
#include"Solider.h"
class PrivateSoldier:public Solider
{
public:
	PrivateSoldier(int id, string fname, string lname, int num, int* grade);
	PrivateSoldier(const PrivateSoldier& s);
	PrivateSoldier(const PrivateSoldier&& s);
	PrivateSoldier();
	~PrivateSoldier();
	void print() override;
	string soldierType() override;
	bool medal() override;
protected:
	int* grades;
};


