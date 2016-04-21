/*
 *  ___  _  ___  _____ _______  _____ ___.__.______   | Swiss Army Project
 * / _/_| |_\_ \ \__  \\_  __ \/     <   |  |\____ \  | Project in C/C++ Language
 * || |_   _| ||  / __ \|  | \/  Y Y  \___  ||  |_> > |
 * ||_  |_|  _|| (____  /__|  |__|_|  / ____||   __/  | @author Luís Ferreira
 * \__\     /__/      \/            \/\/     |__|     | @license GNU Public License v3
 *
 * Copyright (c) 2016 - Luís Ferreira. All right reserved
 * More information in: https://github.com/ljmf00/ (Github Page)
 */

#ifndef SWISSAPMATHPI_H_INCLUDED
#define SWISSAPMATHPI_H_INCLUDED

namespace swissapLib {
	struct pi 
	{
	private:
		int nblock;
    	int *tot;
    	int *t1;
    	int *t2;
    	int *t3;
    	void arctan(int* result, int* w1, int* w2, int denom, int onestep);
    	void copy(int* result, int* from);
    	bool zero(int* result);
    	void add(int* result, int *increm);
    	void sub(int* result, int* decrem);
    	void mult(int* result, int factor);
    	void print(int* result);
    	void set(int* result, int rhs);
    	void div(int* result, int denom);
    public:
    	void calculate(int ndigit);
	};
}

#endif // SWISSAPMATHPI_H_INCLUDED