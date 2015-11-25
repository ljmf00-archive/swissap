

#ifndef TPERIODIC_HPP_INCLUDED
#define TPERIODIC_HPP_INCLUDED

#include "../lib/libs.hpp"

using namespace std;


class ptable
{
public:
    void help()
    {
        cout << "Usage: sourcescript ... periodic-table (--argv) [argv] ...\n\n";
        cout << "  --show-n         SHOW NORMAL PERIODIC TABLE\n";
        cout << "  --show-e         SHOW EXTENDED PERIODIC TABLE\n";
        cout << "  --list           SHOW ATOM LIST\n";
        cout << "  -s g<num>           SHOW ATOM GRAPHIC LOCATION\n";
        cout << "  -s g<letter>           SHOW ATOM GRAPHIC LOCATION\n";
        cout << "  -s <num>            SHOW ATOM DESCRIPTION\n";
        cout << "  -s <letters>        SHOW ATOM DESCRIPTION\n";
        cout << "  -s e<num>        SHOW EXTENDED ATOM DESCRIPTION\n";
        cout << "  -s e<letter>        SHOW EXTENDED ATOM DESCRIPTION\n";
    }
    void variables(char* argm)
    {

    }
};

#endif // TPERIODIC_HPP_INCLUDED
