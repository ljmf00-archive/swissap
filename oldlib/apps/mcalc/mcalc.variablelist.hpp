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


#ifndef USER_VARIABLES_H
#define USER_VARIABLES_H

#include "../lib/libs.hpp"

#include "mcalc.constants.hpp"

using namespace std;



void toupper(char upper[], const char str[]);


class Variablelist {
    public:
        bool exist(const char* name);
        bool add(const char* name, double value);
        bool del(const char* name);

        bool get_value(const char* name, double* value);
        bool get_value(const int id, double* value);
        int  get_id(const char* name);
        bool set_value(const char* name, const double value);

    private:
        struct VAR
        {
            char name[NAME_LEN_MAX+1];
            double value;
        };

        std::vector<VAR> var;
};


#endif
