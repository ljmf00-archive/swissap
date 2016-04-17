#ifndef BSSSTRING_INT_HPP_INCLUDED
#define BSSSTRING_INT_HPP_INCLUDED

#include <sstream>

namespace bssConvert
{
int stringToInt(const std::string &s)
{
    int i;
    std::stringstream ss;
    ss << s;
    ss >> i;
    return i;
}
std::string intToString(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}
}

#endif // BSSSTRING_INT_HPP_INCLUDED
