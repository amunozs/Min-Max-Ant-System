#ifndef ANT_
#define ANT_

#include "SpaceInformation.hpp"

class Ant
{
	private:
	
	SpaceInformation *si_;
	int *path_;
	double fitness_;
	
	bool isNodeValid (int idx)
	{
		if (si_->isNodeRepeatable(idx)) return 1;

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
			if (  isNodeValid(i) )
				total = total + si_->getProbability (actual, i);
		}

		p = rand() % (int)(total*1000);
		p++; // To prevent value 0	

		for (int i=0; i<si_->getNumNodes(); ++i)
		{
			if ( isNodeValid(i) )
			{
				accum = accum + si_->getProbability (actual, i) * 1000;
				if ( p <= accum ) 
					return c;
			}
		}
		return -1;
	}

	bool allNodesVisited ()
	{
		for (int i = 0; i < si_->getNumNodes(); ++i)
		{
			if (si_->isNodeRequired())
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
	
	public:
	
//TODO calcular tamaño de path
	Ant (SpaceInformation *si) : si_(si) 
	{ 
		path_ = new int[50];
		path_[0] = -1;
	}

	~Ant () { delete[] path_; }
//TODO recalcular probabilidades cuando se van descartando nodos
	void solve ()
	{

		bool finish = 0;

		path[0] = rand() % si_->getNumNodes();
		path[1] = -1;

		for (int i=0; finish; i++){
			path[i+1] = selectNextNode (path[i]);
			if (path[i+1] == -1) return;
			path[i+2] = -1;
		}
	}
};

#endif
