/*lsferreira programming */

/*
                                              _       _
                                             (_)     | |
  ___  ___  _   _ _ __ ___ ___  ___  ___ _ __ _ _ __ | |_
 / __|/ _ \| | | | '__/ __/ _ \/ __|/ __| '__| | '_ \| __|
 \__ \ (_) | |_| | | | (_|  __/\__ \ (__| |  | | |_) | |_
 |___/\___/ \__,_|_|  \___\___||___/\___|_|  |_| .__/ \\__|
                                               | |
                                               |_|
			 Copyright  (c) lsferreira programming - 2015
			 Forked from speqmath, 2007-2011 Jos de Jong

			 A C++ expression parser
			 @license

			 http://www.apache.org/licenses/LICENSE-2.0
*/

#include "../lib/libs.hpp"
#include "mcalc.error.hpp"
#include "mcalc.functions.hpp"

using namespace std;



/*
 * calculate factorial of value
 * for example 5! = 5*4*3*2*1 = 120
 */
double factorial(double value)
{
    double res;
    int v = static_cast<double>(value);

    if (value != static_cast<double>(v))
    {
        throw Error(-1, -1, 400, "factorial");
    }

    res = v;
    v--;
    while (v > 1)
    {
        res *= v;
        v--;
    }

    if (res == 0) res = 1;        // 0! is per definition 1
    return res;
}

/*
 * calculate the sign of the given value
 */
double sign(double value)
{
    if (value > 0) return 1;
    if (value < 0) return -1;
    return 0;
}
