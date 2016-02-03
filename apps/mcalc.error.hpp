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

#ifndef ERROR_H
#define ERROR_H

using namespace std;



class Error {
    public:
        Error(const int row, const int col, const int id, ...);

        int get_row() {return err_row;} // Returns the row of the error
        int get_col() {return err_col;} // Returns the column of the error
        int get_id() {return err_id;}   // Returns the id of the error
        char* get_msg() {return msg;}   // Returns a pointer to the error msg

    private:
        int err_row;    // row where the error occured
        int err_col;    // column (position) where the error occured
        int err_id;     // id of the error
        char msg[255];

        const char* msgdesc(const int id);
};


#endif
