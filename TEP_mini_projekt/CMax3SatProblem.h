#pragma once
#include <string>
#include <vector>

using namespace std;

const int clause_size = 3;

class CMax3SatProblem
{
private:
	vector<int*> problemInstance;
	bool initialized;
public:
	CMax3SatProblem() { initialized = false;  };
	~CMax3SatProblem();
	void Load(string path);
	int Compute(vector<bool>* solution);
	int checkClause(int* clause, vector<bool>* solution);
	void clear();
	bool isInitialized() { return initialized; };
	int getProblemInstanceSize() { return problemInstance.size(); };
	int* getClause(int index);
};

