#pragma once
#include <conio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <random>
#include <time.h>
#include <vector>
using namespace std;

struct Individual {
public:
	float fitness;
	char * string;
	Individual(char * string) {
		this->string = string;
	}
	~Individual(){}
};

class Genetic_Algorigthm {
	bool goalReached = false;
	const char * goal = "geneticalgorithmscanbefun"; // skip at 7, 17, 20, 22 
	int goalSize = sizeof(goal) / goal[0];
	const char * alphabet = "abcdefghijklmnopqrstuvwxyz";
	vector<Individual> population;
	int popSize;

public:
	Genetic_Algorigthm() {
		srand(clock());
		for (int i = 0; i < popSize; i++) {
			char * tempString;
			for (int j = 0; j < goalSize; j++) {
				tempString[i] = alphabet[rand() & sizeof(alphabet)/alphabet[0]];
			}
			population.push_back(tempString);
		}
	}
	~Genetic_Algorigthm(){}

	// TODO:
	// each cycle needs to look at all the individuals and access
	// whether they're fit enough. Then, breed the fittest and 
	// start over. Continue like this until you've found one
	// that matches the goal state


	float access(Individual & accessing) {
		float amountWrong = 0;
		for (int i = 0; i < goalSize; ++i) {
			if (accessing.string[i] != goal[i]) {
				amountWrong += abs(accessing.string[i] - goal[i]);
			}
		}
		accessing.fitness = amountWrong / goalSize;
		return accessing.fitness;
	}

	Individual crossover(Individual ind1, Individual ind2) {

	}

	Individual mutate(Individual mutating) {

	}

	void printString(Individual printing) {
		for (int i = 0; i < goalSize; ++i) {
			cout << printing.string[i];
			if (i == 6 || i == 16 || i == 19 || i == 21)
				cout << " ";
		}
	}
};