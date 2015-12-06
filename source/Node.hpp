#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <fstream>

using namespace std;
class Node 
{
	private:

	bool repeatable_;
	bool required_;
	std::string name_;	

	public:

	Node () : repeatable_(0), required_(0), name_("NoName") {}
	Node (bool required, bool repeatable, std::string name ="NoName") : repeatable_(repeatable), required_(required), name_(name) {}

	bool isrepeatable	() 	{ return repeatable_; }
	bool isRequired		() 	{ return required_; }
	std::string getName	() 	{ return name_; }

	void setrepeatable	(bool repeatable)	{ repeatable_ = repeatable; }
	void setRequired	(bool required)		{ required_ = required; }
	void setName 		(std::string name)	{ name_ = name; }

	friend ostream &operator<< (ostream &output, const Node &N)
	{
		output << N.name_ << ", " << N.required_ << ", " << N.repeatable_;
		return output;
	}

	friend istream &operator>> ( istream  &input, Node &N )
    { 
        input >> N.name_ >> N.required_ >> N.repeatable_;
        return input;            
    }
};


//TODO Creo que se puede hacer sin templates
class ProblemDefinition
{
	private:
	
	Node *node_;
	double **feromone_;
	double **distance_;
	
	int num_nodes_;

	public:
	
	ProblemDefinition (int num_nodes = 0) 
	{
		resize(num_nodes);
	}

	void resize (int num_nodes)
	{
		num_nodes_ = num_nodes;
		node_ = new Node[num_nodes];

		feromone_ = new double*[num_nodes];
		distance_ = new double*[num_nodes];

		for (int i = 0; i < num_nodes; ++i)
		{
    		feromone_[i] = new double[num_nodes];
			distance_[i] = new double[num_nodes];
		}
	}

	void freeMemory () 
	{
		delete[] node_;

		for (int i = 0; i < num_nodes_; ++i)
		{
    		delete [] feromone_[i];
			delete [] distance_[i];
		}

  		delete [] feromone_;
		delete [] distance_;
	}

	~ProblemDefinition ()
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
					//distance_[i][c] = 0;
				}
			}
			file.close();
			return 1;
		}
		return 0;
	}

	friend ostream &operator<< (ostream &output, const ProblemDefinition &P)
	{
		output << "NODES:" << std::endl << std::endl;
		for (int i = 0; i < P.num_nodes_; ++i)
		{
			output << P.node_[i] << std::endl;
		}

		output << std::endl << "DISTANCES:" << std::endl << std::endl;
 		for (int i = 0; i < P.num_nodes_; ++i)
		{
			for (int c = 0; c < P.num_nodes_; ++c)
				output << i << "," << c << ": " << P.distance_[i][c] << std::endl;
		}
		return output;
	}

};



#endif
