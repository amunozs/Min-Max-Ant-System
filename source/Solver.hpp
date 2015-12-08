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
	int* best_ant_;
	Ant b;
	double max;
	double min;
	double alpha;
	double beta;
	double evap;	

	void calculateProbabilities ()
	{
		double p;
		for (int i=0; i<si_->getNumNodes(); i++)
		{
			for (int c=0; c<si_->getNumNodes(); c++)
			{
				if (c<=i) continue;
				if (si_->getDistance(i,c) == -1) 
					p=0;
				else
					p = pow(si_->getFeromone(i,c), alpha) * pow(si_->getDistance(i,c), beta);
				si_->setProbability(i,c,p);
				si_->setProbability(c,i,p);
			}
		} 
	}

	void calculateFitness ()
	{
		int fitness ;
		for (int i=0; i<num_ants_; i++)
		{
			fitness = init_fitness;
//TODO cambiar 50
			for (int c=0; c<50; c++)
			{
				if (ant_[i].getPath()[c+1] == -1) 
					break;

				fitness = fitness - si_->getDistance (ant_[i].getPath()[c], ant_[i].getPath()[c+1]); 
			}
			fitness_[i] = fitness;
			if (fitness < best_fitness_)
			{
				best_fitness_ = fitness;
				//for (int c=0; c<50; c++)
				//	best_ant_[c] = ant_[i].getPath()[c];
				b = ant_[i];
			}
		}
	}

	public:
	
	Solver (SpaceInformation *si, int num_ants = 10) : si_(si) 
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
		init_fitness = 25;
		num_iterations_ = 50;
		best_fitness_ = init_fitness + 1;
//TODO 50
		best_ant_ = new int[50];
		for (int i=0; i<50; i++)
			best_ant_[i] = -1;
	}

	~Solver () 
	{
		delete[] ant_;
		delete[] fitness_;
		delete[] best_ant_;
	}

	void solve ()
	{
	calculateProbabilities();
		for (int i=0; i<num_iterations_; i++)
		{
			std::cout<<"i="<<i<<std::endl;
			for (int a=0; a<num_ants_; a++)
			{
				
				ant_[a].solve();
				std::cout<<"a="<<a<<std::endl;
				cout<<ant_[a]<<std::endl;
			}
			std::cout<<"hey1"<<std::endl;
			calculateFitness();
			std::cout<<"hey2"<<std::endl;
			calculateProbabilities();
			std::cout<<"hey3"<<std::endl;
		}
	}

	void printSol()
	{
		cout<<"SOLUTION "<<b<<std::endl;
	}

};
