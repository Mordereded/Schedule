#pragma once
#ifndef NODE_H_
#define NODE_H_
#include "iostream"

struct Node
{
public:
	std::string name;
	int priorite;
	double time;

	Node() :priorite(priorite >= 0 ? priorite : 1 ),time(time > 0 ? time : 1)
	{}
	friend std::ostream& operator<< (std::ostream& out, const Node& node);
	
};
struct predicat
{
	bool operator()(const Node& p1, const Node& p2);
};

#endif // !NODE_H

