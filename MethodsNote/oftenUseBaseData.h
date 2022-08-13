#pragma once
int intnum[12] = { 11,3,2,4,7,6,9,0,8,1,5,7 };//k=0,array[0] is length
int intnumRepeate[11] = { 10,2,3,4,3,5,7,8,6,2,0};//k=1,array[0] is length
double doublenum[12] = { 11,3.3,2.2,4.4,7.7,6.6,9.9,0,8.8,1.1,5.5,7.7 };
double doublenumRepeate[12] = { 11,3.3,2.2,4.4,7.7,2.2,9.9,0,2.2,1.1,2.2,7.7 };

int getBaseDataN(int k,int **e) {
	//k=0;array have not repeate
	//k=1;array have repeate
	if (k == 0) {
		*e = intnum;
		return 11;
	}
	else {
		*e = intnumRepeate;
		return 10;
	}
}
int getBaseDataN(int k, double** e) {
	if (k == 0) {
		*e = doublenum;
		return 11;
	}
	else {
		*e = doublenumRepeate;
		return 11;
	}
}