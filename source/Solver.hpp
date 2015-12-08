#include "Ant.hpp"

#include <cmath>
class Solver
{
	private:
	
	SpaceInformation *si_;
	Ant *ant_;
	int *fitness_;
	int num_ants_;
	int num_iterations_;
	int init_fitness;
	int best_fitness_;
	int best_fitness_global;
	Ant best_ant_;
	Ant best_ant_global_;
	double max;
	double min;
	int alpha;
	int beta;
	double evap;	

	void calculateProbabilities ()
	{
		double p;
		for (int i=0; i<si_->getNumNodes(); i++)
		{
			for (int c=0; c<si_->getNumNodes(); c++)
			{
				if (si_->getDistance(i,c) == -1) 
					p=0;
				else if (si_->getDistance(i,c) == 0)
					p=1;
				else
					p = pow(si_->getFeromone(i,c), alpha) * pow(si_->getDistance(i,c), beta);

				si_->setProbability(i,c,p);
			}
		} 
	}

	void calculateFitness ()
	{
		int fitness ;
		best_fitness_ = 100;
		for (int i=0; i<num_ants_; i++)
		{
			fitness = init_fitness;
//TODO cambiar 50
			for (int c=0; c<50; c++)
			{
				if (ant_[i].getPath()[c+1] == -1) 
					break;
				fitness = fitness + si_->getDistance (ant_[i].getPath()[c], ant_[i].getPath()[c+1]); 
			}
			
			if (ant_[i].satisfiesCapacity ())
				fitness = fitness - 10;

			fitness_[i] = fitness;
			if (fitness < best_fitness_)
			{
				best_fitness_ = fitness;
				best_ant_ = ant_[i];

				if (fitness < best_fitness_global)
				{
					best_ant_global_ = ant_[i];
					best_fitness_global = fitness;
				}
			}
		}
	}

	public:
	
	Solver (SpaceInformation *si, int num_ants = 10) : si_(si) , num_ants_(num_ants)
	{
		
		fitness_ = new int[num_ants];
		ant_ = new Ant[num_ants];
		for (int i=0; i<num_ants; i++)
			ant_[i].setSpaceInformation(si);
		alpha = 1;
		beta = 2;
		evap = 0.1;
		max = 10;
		min = 1;
		init_fitness = 10;
		num_iterations_ = 1000;
		best_fitness_global = 100;
	}

	~Solver () 
	{
		delete[] ant_;
		delete[] fitness_;
	}

	void solve ()
	{
		calculateProbabilities();
		for (int i=0; i<num_iterations_; i++)
		{
			//std:cout<<"i="<<i<<std::endl;
			for (int a=0; a<num_ants_; a++)
			{
				//std::cout<<"a="<<a<<std::endl;
				ant_[a].solve();
				
				//cout<<ant_[a]<<std::endl;
			}
			calculateFitness();
			calculateProbabilities();
			//std::cout<<"BEST "<<best_ant_<<std::endl;
		}
	}

	void printSol()
	{
		//cout<<*si_<<std::endl;
		cout<<"SOLUTION "<<best_ant_global_<<std::endl<<"FITNESS: "<<best_fitness_global<<std::endl;	
	}
};
