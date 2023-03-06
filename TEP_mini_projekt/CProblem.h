#pragma once
#include <vector> 

using namespace std;

class CProblem
{
public:
	virtual int Compute(vector<bool>* solution);
};

