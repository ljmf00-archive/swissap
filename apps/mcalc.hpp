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
*/

#ifndef MCALC_HPP_INCLUDED
#define MCALC_HPP_INCLUDED

//Include libraries
#include "../lib/libs.hpp"

#include "mcalc.parser.hpp"

//Used namespaces
using namespace std;

	void mcalc()
	{
		char expr[255];

    // create a parser object
    Parser prs;

    puts("ENTER EXPRESSION");
    puts("NULL EXPRESSION TO EXIT");
    puts("");

    do
    {
        // request an expression
        printf("> ");
        gets(expr);

        if (strcmp(expr, "") != 0)
        {
            try
            {
                // evaluate the expression
                char* result;
                result = prs.parse(expr);
                printf("\t%s\n", result);
            }
            catch (...)
            {
                printf("\tERROR: Unknown error\n");
            }
        }
    } while (strcmp(expr, "") != 0);
	}

#endif // MCALC_HPP_INCLUDED
