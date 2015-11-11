#pragma once
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
	const char * goal = "geneticalgorithmscanbefun";
	const char * alphabet = "abcdefghijklmnopqrstuvwxyz";
	vector<char*> population;
	int popSize;

public:
	Genetic_Algorigthm() {
		srand(clock());
		for (int i = 0; i < popSize; i++) {
			char * tempString;
			for (int j = 0; j < 25; j++) {
				tempString[i] = alphabet[rand() & sizeof(alphabet)/alphabet[0]];
			}
			population.push_back(tempString);
		}
	}
	~Genetic_Algorigthm(){}
};