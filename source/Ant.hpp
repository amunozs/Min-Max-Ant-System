#ifndef ANT_
#define ANT_

#include <cstdlib>
#include "SpaceInformation.hpp"

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
			if (  isNodeValid(i) )
				total = total + si_->getProbability (actual, i);
		}
		//srand(time(NULL));
		p = std::rand() % (int)(total*1000);
		p++; // To prevent value 0	

		for (int i=0; i<si_->getNumNodes(); ++i)
		{
			if ( isNodeValid(i) )
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
//TODO recalcular probabilidades cuando se van descartando nodos
	void solve ()
	{
		//srand(time(NULL));
		bool finish = 0;
		int a = si_->getNumNodes();
		path_[0] = std::rand() % a;
		path_[1] = -1;

		for (int i=0; 1; i++){
			path_[i+1] = selectNextNode (path_[i]);
			if (path_[i+1] == -1) return;
			if (allNodesVisited()) return;
			path_[i+2] = -1;
		}
	}

	void setSpaceInformation (SpaceInformation *si) {si_ = si;}

	friend ostream &operator<< (ostream &output, const Ant &A)
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
