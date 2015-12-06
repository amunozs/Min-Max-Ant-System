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




#endif
