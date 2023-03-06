#include "CGAOptimizer.h"

const int domestic_prob = 50;

CGAOptimizer::CGAOptimizer(CMax3SatProblem* problem, int problemSize) {

	this->problem = problem;
	this->problemSize = problemSize;
	this->crossoverProbability = domestic_prob;
	this->mutationProbability = domestic_prob;
	this->initialized = false;
}

void CGAOptimizer::Initialize(int populationSize, int crossoverProbability, int mutationProbability)
{
	this->crossoverProbability = crossoverProbability;
	this->mutationProbability = mutationProbability;

	for (int i = 0; i < populationSize; i++) {
		CGAIndividual* individual = new CGAIndividual(problemSize);
		population.push_back(individual);
	}

	initialized = true;
}

CGAOptimizer::~CGAOptimizer()
{
	for (int i = 0; i < population.size(); i++) {
		delete population[i];
	}
}


int CGAOptimizer::selectParent()
{	
	//tournament method
	int parent1Index = CGAIndividual::generateRandom(0, population.size() - 1);
	int parent2Index = CGAIndividual::generateRandom(0, population.size() - 1 );

	int parent1Fitness = population[parent1Index]->Fitness(problem);
	int parent2Fitness = population[parent1Index]->Fitness(problem);

	return (parent1Fitness > parent2Fitness ? parent1Index : parent2Index);

}


void CGAOptimizer::RunIteration()
{
	vector<CGAIndividual*> newPopulation;
	
	while (newPopulation.size() < population.size()) {
		int parent1 = selectParent();
		int parent2 = selectParent();

		CGAIndividual* child1 = new CGAIndividual(*population[parent1]);
		CGAIndividual* child2 = new CGAIndividual(*population[parent2]);

		child1->Crossover(child1, child2, crossoverProbability);

		child1->Mutation(mutationProbability);
		child2->Mutation(mutationProbability);

		oneClauseOpt(child1);
		oneClauseOpt(child2);

		newPopulation.push_back(child1);
		newPopulation.push_back(child2);
	}
	
	int i = 0;
	for (; i < population.size(); i++) {
		delete population[i];
		population[i] = newPopulation[i];
		newPopulation[i] = NULL;
	}

	for (; i < newPopulation.size(); i++) {
		population.push_back(newPopulation[i]);
		newPopulation[i] = NULL;
	}

}

int CGAOptimizer::getBestFitness()
{
	int fitness = 0;
	for (auto individual : population) {
		int localFitness = individual->Fitness(problem);

		if(localFitness > fitness) fitness = localFitness;
	}
	return fitness;
}

void CGAOptimizer::oneClauseOpt(CGAIndividual* child)
{
	int clauseIndex = CGAIndividual::generateRandom(0, problem->getProblemInstanceSize() - 1);
	if (problem->checkClause(problem->getClause(clauseIndex), child->getGenome()) == 0) {
		for (int i = 0; i < 3; i++) {
			child->setGene(abs(problem->getClause(clauseIndex)[i]), !child->getGene(abs(problem->getClause(clauseIndex)[i])));
		}
	}
	
}




