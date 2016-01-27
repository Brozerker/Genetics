#pragma once
#include "genetic_alg.h"

Genetic_Algorigthm::Genetic_Algorigthm(int populationSize, int mutate) : timesToMutate(mutate), popSize(populationSize) {}
Genetic_Algorigthm::~Genetic_Algorigthm() {}

void Genetic_Algorigthm::initPop() {
	srand(clock());
	for (int i = 0; i < popSize; i++) {
		char * tempString = new char[goalSize];
		for (int j = 0; j < goalSize; j++) {
			int randPos = rand() % 26;
			tempString[j] = alphabet[randPos]; //sizeof(alphabet) / sizeof(alphabet[0])];
		}
		string temp = tempString;
		temp.resize(goalSize);
		population.push_back(Individual(temp));
		previousBest = population[0];
	}
}

// assigns fitness to passed Individual and returns the value
float Genetic_Algorigthm::access(Individual & accessing) {
	float amountWrong = 0;
	for (int i = 0; i < goalSize; ++i) {
		if (accessing.str[i] != goal[i]) {
			amountWrong += abs(accessing.str[i] - goal[i]);
		}
	}
	accessing.fitness = amountWrong; // goalSize;
	if (amountWrong == 0)
		goalReached = true;
	return accessing.fitness;
}

// access entire population
void Genetic_Algorigthm::accessPop() {
	for (int i = 0; i < popSize; ++i) {
		access(population[i]);
	}
}

// returns a child of the two passed Individuals
Individual Genetic_Algorigthm::crossover(Individual father, Individual mother) {
	char * temp = new char[goalSize];
	// if i is even, use father, else, use mother
	for (int i = 0; i < goalSize; ++i) {
		if (i % 2 == 0)
			temp[i] = father.str[i];
		else
			temp[i] = mother.str[i];
	}
	string output = temp;
	output.resize(goalSize);
	return Individual(output);
}

// changes NUM_TO_MUTATE characters in the passed string to random, new ones
void Genetic_Algorigthm::mutate(Individual & mutating) {
	for (int i = 0; i < timesToMutate; ++i) {
		int randPos = rand() % goalSize;
		char randChar = alphabet[rand() % 26]; // (sizeof(alphabet) / sizeof(alphabet[0]))];
		if (mutating.str[randPos] != goal[randPos])
			mutating.str[randPos] = randChar;
	}
}

// prints the string of the passed Individual
void Genetic_Algorigthm::printString(Individual printing) {
	for (int i = 0; i < goalSize; ++i) {
		cout << printing.str[i];
		if (i == 6 || i == 16 || i == 19 || i == 21)
			cout << " ";
	}
	cout << endl;
}

// sorts the population (woooooo bubblesort)
void Genetic_Algorigthm::sortPop() {
	bool swapped = true;
	int n = popSize;
	while (swapped) {
		swapped = false;
		for (int i = 1; i < n; ++i) {
			if (population[i - 1].fitness > population[i].fitness) {
				popSwap(i - 1, i);
				swapped = true;
			}
		}
		n--;
	}
}

// swaps the Inidividuals at the passed positions
void Genetic_Algorigthm::popSwap(int x, int y) {
	Individual temp = population[x];
	population[x] = population[y];
	population[y] = temp;
}

// iterates through population and returns the fittest
Individual Genetic_Algorigthm::bestChoice() {
	Individual currentBest = population[0];
	for (int i = 0; i < popSize; ++i) {
		if (population[i].fitness < currentBest.fitness)
			currentBest = population[i];
	}
	if (currentBest.str != previousBest.str) {
		display = true;
		previousBest = currentBest;
	}
	return currentBest;
}

// returns the top 10 fittest Individuals
vector<Individual> Genetic_Algorigthm::top10() {
	vector<Individual> toReturn;
	for (int i = 0; i < 10; ++i) {
		toReturn.push_back(population[i]);
	}
	return toReturn;
}

// resets the population bassed off the passed Indiviuals
void Genetic_Algorigthm::setNewPopulation(vector<Individual> parents) {
	population.clear();
	for (int i = 0; i < parents.size(); ++i) {
		for (int k = 0; k < parents.size(); ++k) {
			population.push_back(crossover(parents[i], parents[k]));
		}
		mutate(population[i]);
	}
	popSize = population.size();
}

void Genetic_Algorigthm::manageGA() {
	currentGen++;
	accessPop();
	sortPop();
	output();
	setNewPopulation(top10());
}
void Genetic_Algorigthm::output() {
Individual currentBest = bestChoice();
	if (display) {
		cout << "Generation " << currentGen << "'s best choice: ";
		printString(currentBest);
	}
	display = false;
}
bool Genetic_Algorigthm::stillCycling() {
	if (goalReached) {
		cout << "Done!";
		getchar();
	}
	return !goalReached;
}
