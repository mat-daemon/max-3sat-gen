#include "CGAIndividual.h"
#include <random>


//constructor
//generate random genome
CGAIndividual::CGAIndividual(int problemSize) {

	for (int i = 0; i < problemSize; i++) {
		genome.push_back(generateRandom(0, 1) == 0 ? false : true);
	}
}

//copy constructor
CGAIndividual::CGAIndividual(CGAIndividual& individual)
{
	for (bool gene : individual.genome) {
		genome.push_back(gene);
	}
}

//uniform distributed random value generator from sOfInterval to eOfInterval
//static method
//not efficient
int CGAIndividual::generateRandom(int sOfInterval, int eOfInterval)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(sOfInterval, eOfInterval);
	return distrib(gen);
}


//static method
void CGAIndividual::swapGene(CGAIndividual* child1, CGAIndividual* child2, int index)
{
	bool geneContainer = child1->getGene(index);
	child1->setGene(index, child2->getGene(index));
	child2->setGene(index, geneContainer);
}

//static method
void CGAIndividual::Crossover(CGAIndividual* child1, CGAIndividual* child2, int crossoverProbability)
{
	//child1 is copy of parent1 by default
	//child2 is copy of parent2 by default 
	//implemented in CGAOptimizer

	int probability = generateRandom(0, 99);
	
	if (probability < crossoverProbability) {
		//uniform crossover
		for (int i = 0; i<child1->getGenomeSize(); i++) {
			if (generateRandom(0,1) == 0) swapGene(child1, child2, i);
		}
	}

}

void CGAIndividual::Mutation(int mutationProbability)
{
	int probability; 

	for (int i = 0; i < getGenomeSize(); i++) {
		probability = generateRandom(0, 99);
		if (probability < mutationProbability) {
			setGene(i, !getGene(i));
		}
	}
}

int CGAIndividual::Fitness(CMax3SatProblem* problem)
{
	return problem->Compute(&genome);
}

//for debugging purposes
void CGAIndividual::printGenome()
{
	cout << "debug CGAIndividual class" << endl;
	cout << "Genome: ";
	for (int i = 0; i < getGenomeSize(); i++) {
		cout << getGene(i) << " ";
	}
	cout << "end of genome" << endl;
}



