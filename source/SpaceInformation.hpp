#ifndef SPACE_INFORMATION_
#define SPACE_INFORMATION_

#include "Node.hpp"

class SpaceInformation
{
	private:
	
	Node *node_;
	double **feromone_;
	double **distance_;
	double **probability_;	

	int num_nodes_;

	public:
	
	SpaceInformation (int num_nodes = 0) 
	{
		resize(num_nodes);
	}

	void resize (int num_nodes)
	{
		num_nodes_ = num_nodes;
		node_ = new Node[num_nodes];

		feromone_ = new double*[num_nodes];
		distance_ = new double*[num_nodes];
		probability_ = new double*[num_nodes];

		for (int i = 0; i < num_nodes; ++i)
		{
    		feromone_[i] = new double[num_nodes];
			distance_[i] = new double[num_nodes];
			probability_[i] = new double[num_nodes];
		}
	}

	void freeMemory () 
	{
		delete[] node_;

		for (int i = 0; i < num_nodes_; ++i)
		{
    		delete [] feromone_[i];
			delete [] distance_[i];
			delete [] probability_[i];
		}

  		delete [] feromone_;
		delete [] distance_;
		delete [] probability_;
	}

	~SpaceInformation ()
	{
		freeMemory();
	}

	bool readFromFile (const char * filename)
	{
		std::ifstream file;
		file.open (filename);

		if (file.is_open())
        {
			int num_nodes;
			file >> num_nodes; 
			resize (num_nodes);
			for (int i = 0; i < num_nodes_; ++i)
			{
				file >> node_[i];

				distance_[i][i] = -1;

				for (int c = 0; c < num_nodes_; ++c)
				{
					if (c == i) continue;
					file >> distance_[i][c];
				}
			}
			file.close();
			return 1;
		}
		return 0;
	}

//TODO control de errores out of bounds
	void setFeromone (int node_1, int node_2, double value)
	{
		feromone_[node_1][node_2] = value;
	}

	void setProbability (int node_1, int node_2, double value)
	{
		probability_[node_1][node_2] = value;
	}

	double getFeromone (int node_1, int node_2)
	{
		return feromone_[node_1][node_2];
	}

	double getProbability (int node_1, int node_2)
	{
		return probability_[node_1][node_2];
	}
	
	int getNumNodes () 
	{
		return num_nodes_;
	}

	friend ostream &operator<< (ostream &output, const SpaceInformation &S)
	{
		output << "NODES:" << std::endl << std::endl;
		for (int i = 0; i < S.num_nodes_; ++i)
		{
			output << S.node_[i] << std::endl;
		}

		output << std::endl << "DISTANCES:" << std::endl << std::endl;
 		for (int i = 0; i < S.num_nodes_; ++i)
		{
			for (int c = 0; c < S.num_nodes_; ++c)
				output << i << "," << c << ": " << S.distance_[i][c] << std::endl;
		}
		return output;
	}
};

#endif
