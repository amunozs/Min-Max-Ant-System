#ifndef ANT_
#define ANT_

#include <cstdlib>
#include <SpaceInformation.hpp>

class Ant
{
	private:
	
	SpaceInformation *si_;
	int *path_;
	
	bool isNodeValid (int idx)
	{
		if (si_->isNodeRepeatable(idx)) 
			return 1;

		for (int i = 0; i < 50; ++i)
		{
			if ( path_[i] == idx )
				return 0;
			if ( path_[i] == -1) 
				return 1;	
		}		
	} 

	int selectNextNode ( int actual) 
	{
		double total = 0;
		int accum = 0;
		int p;

		for (int i=0; i < si_->getNumNodes(); ++i)
		{
			if (  isNodeValid(i) && si_->getDistance (actual, i) != -1)
				total = total + si_->getProbability (actual, i);
		}
		p = std::rand() % (int)(total*1000);
		p++; // To prevent value 0	
		for (int i=0; i<si_->getNumNodes(); ++i)
		{
			if ( isNodeValid(i)  && si_->getDistance (actual, i) != -1)
			{
				accum = accum + si_->getProbability (actual, i) * 1000;
				if ( p <= accum ) 
					return i;
			}
		}
		return -1;
	}

	bool allNodesVisited ()
	{
		for (int i = 0; i < si_->getNumNodes(); ++i)
		{
			if (si_->isNodeRequired(i))
			{
//TODO 50
				for (int c = 0; c < 50; ++c)
				{
					if (path_[c] == i)
						break;
					if (path_[c] == -1)
						return 0;				
				}
			}	
		}
		return 1;
	}
	
	void resetAnt()
	{
		for (int i =0; i<50; i++)
			path_[i] = -1;
	}
	

	public:
	
//TODO calcular tamaño de path
	Ant (SpaceInformation *si=NULL) : si_(si) 
	{ 
		path_ = new int[50];
		path_[0] = -1;	
		for(int i=1; i<50; ++i) path_[i] = -1;
		srand(time(NULL));
	}

	~Ant () { delete[] path_; }

	void solve ()
	{
		//srand(time(NULL));
		resetAnt();
		//std::cout<<"solving..."<<std::endl;
		//std::cout<<*si_<<std::endl;
		int a = si_->getNumNodes();

		while(1)
		{
			path_[0] = std::rand() % a;
			path_[1] = -1;
			if (si_->isNodeRepeatable(path_[0]))
				break;
		}
		
		for (int i=0; 1; i++)
		{
			path_[i+1] = selectNextNode (path_[i]);
			if (path_[i+1] == -1) return;
			if (allNodesVisited()) return;
			path_[i+2] = -1;
		}
	}

	Ant& operator=( const Ant& A )
	{
		for(int i=0; i<50; i++)
		{
			path_[i] = A.path_[i];
		}
		si_ = A.si_;
		return *this;
	}

	bool satisfiesCapacity ()
	{
		int *capacities_ = new int[si_->getNumNodes()];
		for (int i=0; i<si_->getNumNodes(); i++)
		{
			capacities_[i] = si_->getCapacity (i);
		}
//TODO ese i+2 es cutre de cojones
		for (int i=0; i<50; i=i+2)
		{
			if (path_[i] != -1)
				if (si_->getCapacity(path_[i]) != -1)
				{
					capacities_[path_[i]] = capacities_[path_[i]] - capacities_[path_[i+1]];
					if (capacities_[path_[i]] < 0)
						return 0;
				}
		}
		return 1;
	}

	void setSpaceInformation (SpaceInformation *si) {si_ = si;}

    friend std::ostream &operator<< (std::ostream &output, const Ant &A)
	{
		output << "PATH:" << std::endl;
		for (int i = 0; i < 50; ++i)
		{
			if (A.path_[i] == -1)
				return output;
			else if (i != 0)
				output << " -> ";
				
			output << A.si_->getNodeName(A.path_[i]);
		}
		return output;
	}

	const int* getPath () const { return path_; }
};

#endif
