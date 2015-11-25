#ifndef PTABLE_GRAPHICS_HPP_INCLUDED
#define PTABLE_GRAPHICS_HPP_INCLUDED

#include "../lib/libs.hpp"

using namespace std;

class pgraphics
{
public:
    void normal_pt()
    {
        cout << "+                +" <<endl;
        cout << "++          ++++++" <<endl;
        cout << "++          ++++++" <<endl;
        cout << "++++++++++++++++++" <<endl;
        cout << "++++++++++++++++++" <<endl;
        cout << "++++++++++++++++++" <<endl;
        cout << "+++++++++" <<endl;
        cout << "  |++++++++++++++" << endl;
        cout << "  |++++++++++++++" << endl;
    }
    void extended_pt()
    {
        cout << "+                              +" <<endl;
        cout << "++                        ++++++" <<endl;
        cout << "++                        ++++++" <<endl;
        cout << "+++              +++++++++++++++" <<endl;
        cout << "+++              +++++++++++++++" <<endl;
        cout << "++++++++++++++++++++++++++++++++" <<endl;
        cout << "+++++++++++++++++++++++" <<endl;
    }
};

#endif // PTABLE_GRAPHICS_HPP_INCLUDED
