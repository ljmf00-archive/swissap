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


#ifndef PARSER_H
#define PARSER_H

// declarations
#include "mcalc.constants.hpp"
#include "mcalc.error.hpp"
#include "mcalc.functions.hpp"
#include "mcalc.variablelist.hpp"

using namespace std;

class Parser
{
    // public functions
    public:
        Parser();
        char* parse(const char expr[]);

    // enumerations
    private:

        enum TOKENTYPE {NOTHING = -1, DELIMETER, NUMBER, VARIABLE, FUNCTION, UNKNOWN};

        enum OPERATOR_ID {AND, OR, BITSHIFTLEFT, BITSHIFTRIGHT,                 // level 2
                       EQUAL, UNEQUAL, SMALLER, LARGER, SMALLEREQ, LARGEREQ,    // level 3
                       PLUS, MINUS,                     // level 4
                       MULTIPLY, DIVIDE, MODULUS, XOR,  // level 5
                       POW,                             // level 6
                       FACTORIAL};                      // level 7

    // data
    private:
        char expr[EXPR_LEN_MAX+1];    // holds the expression
        char* e;                      // points to a character in expr

        char token[NAME_LEN_MAX+1];   // holds the token
        TOKENTYPE token_type;         // type of the token

        double ans;                   // holds the result of the expression
        char ans_str[255];            // holds a string containing the result
                                      // of the expression

        Variablelist user_var;        // list with variables defined by user

    // private functions
    private:
        void getToken();

        double parse_level1();
        double parse_level2();
        double parse_level3();
        double parse_level4();
        double parse_level5();
        double parse_level6();
        double parse_level7();
        double parse_level8();
        double parse_level9();
        double parse_level10();
        double parse_number();

        int get_operator_id(const char op_name[]);
        double eval_operator(const int op_id, const double &lhs, const double &rhs);
        double eval_function(const char fn_name[], const double &value);
        double eval_variable(const char var_name[]);

        int row();
        int col();
};

#endif