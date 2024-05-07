#include <iostream>
#include <queue>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>
#include "Node.h"
#include "File.h"

#define Max_Hours (32)


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");
    

    std::string filename = "table.txt";
    double hours = 0;
    AttractionTableReader reader;
    std::priority_queue<Node, std::vector<Node>, predicat> nodes;

    std::vector<Node> items = reader.readTable(filename);

    for (const auto& node : items) {
        nodes.emplace(node);
    }
    for (ptrdiff_t i = 0; i < nodes.size() && hours < Max_Hours; i++)
    {
        if (hours + nodes.top().time > Max_Hours) continue;
        hours += nodes.top().time;
        std::cout << nodes.top() << "[Îñòàâøååñÿ âðåìÿ = " << Max_Hours - hours <<
            " : Âðåìÿ ïîñèùåíèÿ ñëåäóþùåãî ìåñòà = ";
        nodes.pop();
        std::cout << nodes.top().time << "]" << "\n";
    }

    return 0;
}
