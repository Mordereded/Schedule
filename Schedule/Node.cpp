
#include "Node.h"

bool predicat::operator()(const Node& p1, const Node& p2)
{
    return p1.priorite < p2.priorite;
}


std::ostream& operator<< (std::ostream& out, const Node& node)
{
    return out << "��������: " << node.name <<
        " ��������� = " << node.priorite <<
        " ����� ��������� = " << node.time << "\n";
}