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
	
	/*for (int i=0 ; i<9; i++)
	{
		//std::cout<<"i="<<i<<std::endl;
		for (int c = 0; c<9; c++){
			//std::cout<<"c="<<c<<std::endl;
			if (i==c)
				P.setFeromone(i,c,0);
			else
				P.setFeromone(i,c,1);				
		}
	}*/
	
	//std::cout<<P;
		
	//std::cout<<"node 0: "<<P.isNodeRepeatable (4)<<std::endl;
//	Ant A (&P);
//	A.solve();
	std:cout<<"main"<<std::endl;
	//cout<<A<<std::endl;
	Solver S(&P);
	S.solve();
	S.printSol();
	return 0;
}
