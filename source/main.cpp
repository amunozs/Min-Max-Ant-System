#include <iostream>
#include <fstream>
#include "./SpaceInformation.hpp"

int main () {
	SpaceInformation P;
	std::cout<<"OK"<<endl;
	P.readFromFile ("prueba.txt");
	std::cout<<P;
	return 0;
}
