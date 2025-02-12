#pragma once
#include"PrivateSoldier.h"

class Commander :public PrivateSoldier
{
public:
	Commander(int id, string fname, string lname, int num, int* grade,bool combat);
	~Commander();
	Commander();
	Commander(const Commander&& s);
	Commander(const Commander& s);
	bool getCombat() { return isCombat; };
	void print() override;
	string soldierType() override;
	bool medal() override;
private:
	bool isCombat;
};


