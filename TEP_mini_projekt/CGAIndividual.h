#pragma once
#include <vector>
#include "CMax3SatProblem.h"
#include <iostream>
using namespace std;

class CGAIndividual
{
private:
	vector<bool> genome;
	static void swapGene(CGAIndividual* child1, CGAIndividual* child2, int index);
	
public:
	CGAIndividual(int problemSize);
	CGAIndividual(CGAIndividual& individual);
	~CGAIndividual() { genome.clear(); };
	static void  Crossover(CGAIndividual* child1, CGAIndividual* child2, int crossoverProbability);
	void Mutation(int mutationProbability);
	int Fitness(CMax3SatProblem* problem);
	static int generateRandom(int sOfInterval, int eOfInterval);
	bool getGene(int index) { return genome[index]; };
	void setGene(int index, bool gene) { genome[index] = gene; };
	int getGenomeSize() { return genome.size();  };
	//for debugging purposes
	void printGenome();
	vector<bool>* getGenome() { return &genome; };
};

