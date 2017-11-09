/*
 * main.cpp
 *
 *  Created on: Oct 30, 2017
 *      Author: pcoo_local
 */

#include "Poly.h"

int main(){

	Poly p1(0);
	Poly p2(0);
	cout << "Entrez deux polynômes: " << endl;
	cout << "Polynôme 1: ";
	std::cin>>p1;
	cout << "Polynôme 2: ";
	std::cin>>p2;

	std::cout<<p1;
	std::cout<<p2;

	Poly pmult(0);
	cout << "pmult" <<endl;
	pmult = p1 * p2;
	cout << "pmult" <<endl;
	Poly padd(0);
	padd = p1 + p2;
	cout << "padd" << endl;

	cout << "P1(x) + P2(x) = ";
	std::cout<< padd;
	cout << "P1(x) * P2(x) = ";
	std::cout<< pmult;

	return 0;
}


