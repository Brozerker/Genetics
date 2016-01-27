#pragma once
#include <conio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <random>
#include <time.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Individual {
	float fitness = 1000.0f;
	string str;
	Individual() {}
	Individual(string str) : str(str) {}
	~Individual(){}
};

class Genetic_Algorigthm {
	int currentGen = 0;
	int timesToMutate;
	bool display = false;
	bool goalReached = false;
	string goal = "geneticalgorithmscanbefun"; // skip at 7, 17, 20, 22  
	int goalSize = goal.size(); //sizeof(goal) / sizeof(goal[0]);
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	vector<Individual> population;
	Individual previousBest;
	int popSize;

public:
	Genetic_Algorigthm(int, int);
	~Genetic_Algorigthm();

	void initPop();
	float access(Individual & accessing);
	void accessPop();
	void mutate(Individual & mutating);
	void printString(Individual printing);
	void sortPop();
	void popSwap(int x, int y);
	void setNewPopulation(vector<Individual> parents);
	void manageGA();
	void output();
	bool stillCycling();
	Individual crossover(Individual father, Individual mother);
	Individual bestChoice();
	vector<Individual> top10();
};