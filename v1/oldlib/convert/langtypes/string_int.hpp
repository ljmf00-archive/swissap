#ifndef SSSTRINGINTCONVERT_H_INCLUDED
#define SSSTRINGINTCONVERT_H_INCLUDED


class TypesConverter
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

#endif // SSSTRINGINTCONVERT_H_INCLUDED
