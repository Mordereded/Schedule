#pragma once
#ifndef AttractionTableReader_H_
#define AttractionTableReader_H_
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Node.h"

class AttractionTableReader {
public:
    std::vector<Node> readTable(const std::string& filename);

private:
    Node parseAttraction(const std::string& line);
};
#endif // !AttractionTableReader_H_

