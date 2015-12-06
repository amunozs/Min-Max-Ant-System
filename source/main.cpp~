#include <iostream>
#include <fstream>
#include "./SpaceInformation.hpp"
#include "./Ant.hpp"

int main () {
	SpaceInformation P;
	std::cout<<"OK"<<endl;
	P.readFromFile ("prueba.txt");
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
		
	Ant A (&P);
	A.solve();
	cout<<A<<std::endl;

	return 0;
}
