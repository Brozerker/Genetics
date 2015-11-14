#include "genetic_alg.h"

int main() {
	Genetic_Algorigthm GA;
	GA.initPop();
	while (GA.stillCycling()) {
		GA.manageGA();
	}
}
