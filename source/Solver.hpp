#ifndef SOLVER_
#define SOLVER_

#include <Ant.hpp>
#include <cmath>
#include <ctime>

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
    double time_;

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
					p = pow(si_->getFeromone(i,c), alpha) * pow((1/(double)si_->getDistance(i,c)), beta);

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

	void calculateFeromone ()
	{

		for (int i=0 ; i<si_->getNumNodes(); i++)
		{
			for (int c = 0; c<si_->getNumNodes(); c++)
			{
				if (i==c)
					si_->setFeromone(i,c,0);
				else
				{
                    //fer = si_->getFeromone(i,c)*evap + (1-evap)*(200/best_fitness_);
                    si_->setFeromone(i,c,si_->getFeromone(i,c)*evap + (1-evap)*(200/best_fitness_));
				}
				
				if (si_->getFeromone(i,c) > max)
					si_->setFeromone(i,c,max);
				else if (si_->getFeromone(i,c) < min)
					si_->setFeromone(i,c,min);

			}
		}
	}

	void resetFeromone ()
	{
		for (int i=0 ; i<si_->getNumNodes(); i++)
		{
			for (int c = 0; c<si_->getNumNodes(); c++)
			{
				if (i==c)
					si_->setFeromone(i,c,0);
				else
					si_->setFeromone(i,c,max);				
			}
		}
	}

	public:
	
	Solver (SpaceInformation *si, int num_ants = 5) : si_(si) , num_ants_(num_ants)
	{
        std::cout<<"Solver"<<std::endl;
		fitness_ = new int[num_ants];
		ant_ = new Ant[num_ants];
		for (int i=0; i<num_ants; i++)
			ant_[i].setSpaceInformation(si);
		alpha = 1;
		beta = 2;
		evap = 0.9;
		max = 10;
		min = 1;
		init_fitness = 10;
		num_iterations_ = 10;
		best_fitness_global = 100;
        time_ = 0;
	}

    Solver (SpaceInformation *si, int num_ants, int num_iterations, int alpha, int beta, double max_fer, double min_fer, double evaporation) : si_(si) , num_ants_(num_ants), num_iterations_(num_iterations), alpha(alpha), beta(beta),
        max(max_fer), min(min_fer), evap(evaporation)
    {
        fitness_ = new int[num_ants];
        ant_ = new Ant[num_ants];
        for (int i=0; i<num_ants; i++)
            ant_[i].setSpaceInformation(si);
        init_fitness = 10;
        best_fitness_global = 100;
        time_ = 0;
    }


	~Solver () 
	{
		delete[] ant_;
		delete[] fitness_;
	}

	void solve ()
	{
        clock_t start = clock();
		resetFeromone();
		calculateProbabilities();
		
		for (int i=0; i<num_iterations_; i++)
		{
			for (int a=0; a<num_ants_; a++)
				ant_[a].solve();
	
			calculateFitness();
			calculateFeromone();
			calculateProbabilities();
		}
        clock_t end = clock();
        double time_ = double(end - start) / (CLOCKS_PER_SEC/1000);
	}

    void printSol()
	{
        std::cout<<"SOLUTION "<<best_ant_global_<<std::endl<<"FITNESS: "<<best_fitness_global<<std::endl;
	}

	void setNumIterations (int n) { num_iterations_ = n; }
	void setNumAnts (int n) { num_ants_ = n; }
	void setMaxFeromone (int n) { max = n; }
	void setMinFeromone (int n) { min = n; }
	void setAlpha (int n) { alpha = n; }
	void setBeta (int n) { beta = n; }
	void setEvaporationRatio (int n) { evap = n; }
	void setInitialFitness (int n) {init_fitness = n; }
    double getTime () { return time_; }
    int getFitness () {return best_fitness_global;}
    std::string getPath ()
    {
        std::string path_string;
        const int* path = best_ant_global_.getPath();
        //path_string += "SOLUTION:" + '\n';
        for (int i=0; i<50; i=i+2)
        {
            if (path[i] == -1 || path[i+1] == -1) break;
            path_string.append(si_->getNodeName(path[i]));
            path_string.append(" -> ");
            path_string.append(si_->getNodeName(path[i+1]));
            path_string += '\n';
        }
        return path_string;
    }
};

#endif
