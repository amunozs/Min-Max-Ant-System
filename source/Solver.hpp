#include "Ant.hpp"

#include <cmath>
class Solver
{
	private:
	
	SpaceInformation *si_;
	Ant *ant_;
	int *fitness_;
	int num_ants_;
	double alpha;
	double beta;

	void calculateProbabilities ()
	{
		double p;
		for (int i=0; i<si_->getNumNodes(); i++)
		{
			for (int c=0; c<si_->getNumNodes(); c++)
			{
				if (c<=i) continue;
				p = pow(si_->getFeromone(i,c), alpha) * pow(si_->getDistance(i,c), beta);
			}
		} 
	}

	void calculateFitness (int idx)
	{
		int* path = ant_[idx].getPath();
		int fitness = 0;
//TODO cambiar 50
		for (int i=0; i<50; i++)
		{
			fitness_[i] = 
		}
	}

	public:
	
	Solver (SpaceInformation *si, int num_ants = 10) : si_(si) 
	{
		fitness_ = new int[num_ants];
		ant_ = new Ant[num_ants];
		for (int i=0; i<num_ants; i++)
			ant_[i].setSpaceInformation(si);
	}

	~Solver () 
	{
		delete[] ant_;
		delete[] fitness_;
	}

};
