#include <iostream>
#include <vector>
#include <string>
#include "CGAIndividual.h"
#include "CMax3SatProblem.h"
#include "CGAOptimizer.h"

using namespace std;



int main() {
	//CGAIndividual Test
	/*
	CGAIndividual in(5);
	CGAIndividual in2(5);
	CGAIndividual in3(5);

	in2.printGenome();
	in3.printGenome();
	CGAIndividual::Crossover(&in2, &in3, 80);
	in2.printGenome();
	in3.printGenome();
	*/

	//CMax3SatProblem Test
	CMax3SatProblem p;
	CGAIndividual in(50);

	string path = "m3s_50_0.txt";
	cout << "CMax3SatProblem is initialized: " << (p.isInitialized() ? "true" : "false") << endl;
	p.Load(path);
	cout << "CMax3SatProblem is initialized: " << (p.isInitialized() ? "true" : "false") << endl;
	cout << "Problem size: " << p.getProblemInstanceSize() << endl;
	cout << "Clauses satisfied: " << p.Compute(in.getGenome()) << endl;
	

	//CGAOptimizer Test
	/*CMax3SatProblem problem;
	string path = "m3s_50_0.txt";
	problem.Load(path);

	CGAOptimizer optimizer(&problem, 50);
	optimizer.Initialize(50, 1, 5);
	cout << optimizer.getBestFitness()<<endl;

	for (int i = 0; i < 3; i++) {
		optimizer.RunIteration();
		cout << optimizer.getBestFitness() << endl;
	}*/



	return 0;
}