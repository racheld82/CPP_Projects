#pragma once
#include"Solider.h"

class Officer :public Solider
{
public:
	Officer(int id, string fname, string lname, int num, int soci);
	Officer(const Officer& of);
	Officer(const Officer&& of);
	int getSocioMetric() { return sociometric; };
	void print() override;
	string soldierType() override;
	bool medal() override;


private:
	int sociometric;

};


