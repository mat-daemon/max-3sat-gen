#pragma once
#include <vector>
#include "CGAIndividual.h"
#include "CMax3SatProblem.h"

using namespace std;

class CGAOptimizer
{
private:
	vector<CGAIndividual*> population;
	int crossoverProbability;
	int mutationProbability;
	CMax3SatProblem* problem;
	int problemSize;
	bool initialized;
	int selectParent();

public:
	CGAOptimizer(CMax3SatProblem* problem, int problemSize);
	~CGAOptimizer();
	void Initialize(int populationSize, int crossoverProbability, int mutationProbability);
	void RunIteration();
	//getters
	int getProblemSize() { return problemSize; };
	int getCrossoverProbability() { return crossoverProbability; };
	int getMutationProbability() { return mutationProbability; };
	int getPopulationSize() { return population.size(); };
	int getBestFitness();
	void oneClauseOpt(CGAIndividual* child);
};

