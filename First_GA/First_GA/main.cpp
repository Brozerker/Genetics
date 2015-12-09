#include "genetic_alg.h"
#include <conio.h>
using namespace std;

int main() {
	int popSize, mutateTimes;
	cout << "how big should the start population be?" << endl;
	cin >> popSize;
	cout << "how many times should an Individual mutate each cycle?" << endl;
	cin >> mutateTimes;
	Genetic_Algorigthm GA(popSize, mutateTimes);
	GA.initPop();
	while (GA.stillCycling()) {
		GA.manageGA();
	}
	getchar();
}
