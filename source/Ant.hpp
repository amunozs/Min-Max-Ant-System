#ifndef ANT_
#define ANT_

#include "SpaceInformation.hpp"

class Ant
{
	private:
	
	SpaceInformation *si_;
	int *path_;
	double fitness_;
	
	public:
	
//TODO calcular tamaño de path
	Ant (SpaceInformation *si) : si_(si) { path = new int[50]; }

	~Ant () { delete[] path; }

	void solve ()
	{
		int p;
		int accum = 0;
		bool finish = 0;

		path[0] = rand() % si_->getNumNodes();

		for (int i=1; finish; i++){

			accum = 0;
			p = rand() % 1000;
			p++; // To prevent value 0	

			for (int c=0; c<si_->getNumNodes(); ++c)
			{
				accum = accum + si_->getProbability (path[i], c) * 1000;
				if ( p <= accum ) 
					path[i] = c;
			}
		}
	}
};

#endif