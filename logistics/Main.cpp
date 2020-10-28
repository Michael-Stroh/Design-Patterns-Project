#include <iostream>
#include <string>

#include "TyreStrategy.h"
#include "Tyre.h"


using namespace std;

int main()
{
	TyreStrategy* ts = new TyreStrategy();
	
	vector<Tyre*> t = ts->getTyres();
	
	for(int i =0; i < t.size(); i++){
		t[i]->usage();
	}
	
	int* arr = ts->getPitLaps();
	
	for(int i =0; i < ts->getNumPits(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}


