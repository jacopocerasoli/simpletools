/* crop: Part of the simpletools package
 * (c) Conor Fitzpatrick, 2008
 *
 * If you find this program useful in whole or in part
 * please cite this paper:
 *
 * Feel free to send bugreports, feature requests, patches etc to:
 * conor.fitzpatrick@cern.ch
 *
 */
#include "cropdatastore.h"
#include "cropvarensemble.h"
#include <stdlib.h>
#include <iostream>
#include "stdio.h"
#include "TROOT.h"
#include <TApplication.h>

//http://www.akiti.ca/mulmatvec2.html
using std::cout;
using std::endl;
cropdatastore * datastore;
cropvarensemble * varensemble;
int main(int argc, char *argv[]) {
	TCanvas *c = new TCanvas("null","null",0,0);
	if(argc != 4){
	sepperInfo();
	exit(EXIT_FAILURE);
	}

	TString weightListName = argv[1];
	TString varListName = argv[2];
	TString outname = argv[3];

	cout << "INFO: Parsing weightfile..." << endl;
	datastore = new cropdatastore("test",weightListName);
	datastore->printDataSets();
	datastore->initStats();
	varensemble = new cropvarensemble("test", varListName);
	varensemble->sortbySepPower(datastore);
	varensemble->writeToFile(outname);

}
