#include <iostream>
#include <fstream>
#include <ostream>
#include <cmath>
#include "commesso.h"
#include <armadillo>

using namespace arma;
using namespace std;

rowvec swap(rowvec);
bool check(mat);
double cost(rowvec);
int Pbc(int j);
rowvec shift(rowvec path);

int populationSize = 10;
int pathLength = 5;

int main() {


        // Read seed for random numbers
        int p1, p2;
        ifstream Primes("Primes");
        Primes >> p1 >> p2;
        Primes.close();

        ifstream input("seed.in");
        input >> seed[0] >> seed[1] >> seed[2] >> seed[3];
        rnd.SetRandom( seed, p1, p2 );
        input.close();
	//


	rowvec path = {1,2,3,4,5};
	mat paths(populationSize, pathLength);
	colvec costs(populationSize);

	for (int i=0;i<populationSize;i++) {
		rowvec newPath = swap(path);
		paths.row(i) = newPath;
		costs(i) = cost(newPath);
	}

	uvec indices = sort_index(costs);	

	paths = paths.rows(indices);
	
	// più alzo l'esponente, più vengono privilegiati 
	// i più fit
	int p = 1;
	int j = int(populationSize*pow(rnd.Rannyu(),p));
	
	paths.print();
	return 0;

}

bool check(mat paths) {

	bool result = true;
	for (int i=0; i<populationSize; i++) { 
		rowvec riga = paths.row(i);
		rowvec 	unici = unique(riga);
		result = ( unici.n_elem == riga.n_elem);
	}
	return result;

}


// swap two cities in the path
// keeping the first in place
rowvec swap(rowvec path) {
	int index1 = floor(rnd.Rannyu(1,pathLength));
	int index2 = floor(rnd.Rannyu(1,pathLength));
	int temp = path[index1];
	path[index1] = path[index2];
	path[index2] = temp;
	return path;
}


double cost(rowvec path) {
	double cost = 0.;
	for (int i = 1; i<pathLength; i++)
		cost += abs(path[i]-path[i-1]);
	cost += abs(path[0]-path[pathLength-1]);
	return cost;
}


rowvec shift(rowvec path) {
	

	int m = floor(rnd.Rannyu(1,pathLength-1));
	for (int i=1; i<pathLength; i++) {}


}

int Pbc(int j) {
	if(j>4) return j%5+1;
	return j;
}

