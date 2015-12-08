#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <fstream>

//TODO quitar using namespace
using namespace std;
class Node 
{
	private:

	bool repeatable_;
	bool required_;
	int capacity_;
	std::string name_;	

	public:

	Node () : repeatable_(0), required_(0), name_("NoName") {}
	Node (bool required, bool repeatable, std::string name ="NoName") : repeatable_(repeatable), required_(required), name_(name) {}

	bool isRepeatable	() const	{ return repeatable_; }
	bool isRequired		() const	{ return required_; }
	std::string getName	() const	{ return name_; }
	int getCapacity		() const	{ return capacity_; }

	void setrepeatable	(bool repeatable)	{ repeatable_ = repeatable; }
	void setRequired	(bool required)		{ required_ = required; }
	void setName 		(std::string name)	{ name_ = name; }
	void setCapacity 	(int capacity)		{ capacity_ = capacity; }

	friend ostream &operator<< (ostream &output, const Node &N)
	{
		output << N.name_ << ", " << N.required_ << ", " << N.repeatable_ <<", " << N.capacity_;
		return output;
	}

	friend istream &operator>> ( istream  &input, Node &N )
    { 
        input >> N.name_ >> N.required_ >> N.repeatable_ >> N.capacity_;
        return input;            
    }
};




#endif
