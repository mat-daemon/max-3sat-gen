#include "CMax3SatProblem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

CMax3SatProblem::~CMax3SatProblem()
{
	for (int i = 0; i < problemInstance.size(); i++) delete[] problemInstance[i];
}

void CMax3SatProblem::Load(string path)
{
	ifstream file;
	file.open(path.c_str());

	if (file) {
		string line;
		string word;
		int temp_int;

		while (getline(file, line)) {
			int* clause = new int[3];
			int index = 0;
			stringstream ss;
			ss << line;

			while (!ss.eof()) {
				ss >> word;
				if (stringstream(word) >> temp_int) {
					clause[index] = temp_int;
					index++;

				}
			}

			problemInstance.push_back(clause);
		}
	}

	initialized = true;
	file.close();
}

int CMax3SatProblem::Compute(vector<bool>* solution)
{
	int accumulator = 0;

	for (auto clause : problemInstance) {
		accumulator += checkClause(clause, solution);
	}

	return accumulator;
}

//CHECK -0
int CMax3SatProblem::checkClause(int* clause, vector<bool>* solution)
{
	for (int i = 0; i < clause_size; i++) {
		if ((*solution)[abs(clause[i])]) {
			if (clause[i] < 0) return 0;
			return 1;
		}
		else {
			if (clause[i] < 0) return 1;
			else return 0;
		}
	}

	return 0;
}

void CMax3SatProblem::clear() {
	initialized = false;
	for (int i = 0; i < problemInstance.size(); i++) delete problemInstance[i];
	problemInstance.clear();
}

int* CMax3SatProblem::getClause(int index)
{
	if (index < problemInstance.size()) return problemInstance[index];
	else return nullptr;
}
