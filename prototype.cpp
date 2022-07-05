#include "prototype.h"
#include <stdio.h>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <fstream>

Prototype::Prototype()
{

}

auto clone1 = [](const Contact& c)
{
    ostringstream oss;
    boost::archive::text_oarchive oa(oss);

    oa <<c;

    string s = oss.str();

    istringstream iss(oss.str());
    boost::archive::text_iarchive ia(iss);

    Contact result;
    ia >> result;
    return result;
};


int main(void)
{
    Contact j;
    Contact s = clone1(j);

}
