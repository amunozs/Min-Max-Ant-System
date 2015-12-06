#include <iostream>
#include <fstream>
#include "./Node.hpp"

int main () {
	ProblemDefinition P;
	std::cout<<"OK"<<endl;
	P.readFromFile ("prueba.txt");
	std::cout<<P;
	return 0;
}
