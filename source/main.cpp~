#include <iostream>
#include <fstream>
#include "./SpaceInformation.hpp"
#include "./Ant.hpp"
#include "./Solver.hpp"

int main () {
	SpaceInformation P;
	P.readFromFile ("prueba.txt");
		//std::cout<<"NOPE";
	//std::cout<<P;
	
	for (int i=0 ; i<6; i++)
	{
		for (int c = 0; c<6; c++){
			if (i==c)
				P.setProbability(i,c,0);
			else
				P.setProbability(i,c,1);				
		}
	}
	
	//std::cout<<P;
		
	//std::cout<<"node 0: "<<P.isNodeRepeatable (4)<<std::endl;
	Ant A (&P);
	A.solve();
	std:cout<<"main"<<std::endl;
	cout<<A<<std::endl;

	return 0;
}
