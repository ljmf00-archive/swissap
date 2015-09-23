#ifndef TPERIODIC_HPP_INCLUDED
#define TPERIODIC_HPP_INCLUDED

#include "../lib/libs.hpp"

using namespace std;

class ptable
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
    void list_pt()
    {
        cout << "###  NAME        LETTER" << endl;
        cout << "  1  HYDROGEN    H" << endl;
        cout << "  2  HELIUM      He" << endl;
        cout << "  3  LITHIUM     Li" << endl;
        cout << "  4  BERYLLIUM   Be" << endl;
        cout << "  5  BORON       B" << endl;
        cout << "  6  CARBON      C" << endl;

    }
    void help()
    {
        cout << "Usage: sourcescript ... periodic-table (--argv) [argv] ...\n\n";
        cout << "  --show-n         SHOW NORMAL PERIODIC TABLE\n";
        cout << "  --show-e         SHOW EXTENDED PERIODIC TABLE\n";
        cout << "  --list           SHOW ATOM LIST\n";
        cout << "  -s g<num>           SHOW ATOM GRAPHIC LOCATION\n";
        cout << "  -s <num>            SHOW ATOM DESCRIPTION\n";
        cout << "  -s <letters>        SHOW ATOM DESCRIPTION\n";
    }
    void variables(char* argm)
    {

    }
};

#endif // TPERIODIC_HPP_INCLUDED
