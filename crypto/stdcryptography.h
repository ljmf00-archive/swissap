#ifndef STDCRYPTOGRAPHY_H_INCLUDED
#define STDCRYPTOGRAPHY_H_INCLUDED

#include "../lib/libs.hpp"

class crypt
{
public:
    int string_to_int(const string &s)
    {
        int i;
        stringstream ss;
        ss << s;
        ss >> i;
        return i;
    }

    string int_to_string(int i)
    {
        stringstream ss;
        ss << i;
        return ss.str();
    }
};

#endif // STDCRYPTOGRAPHY_H_INCLUDED
