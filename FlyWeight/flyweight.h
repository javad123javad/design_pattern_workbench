#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <stdint.h>
#include <string>
#include <boost/bimap.hpp>
#include <iostream>
typedef uint32_t key;
using std::string;

class FlyWeight
{
public:
    FlyWeight();
};

struct User
{

User(
        const string& first_name,
        const string& last_name
     ):
    first_name{add(first_name)},
    last_name{add(last_name)}
{}
const string& get_first_name() const
{
    return names.left.find(first_name)->second;
}
const string& get_last_name() const
{
    return names.left.find(last_name)->second;
}

friend std::ostream& operator<<(std::ostream& os, const User&obj)
{
    return os
            <<"first name: "<<obj.get_first_name()<<std::endl
           << "last name: "<< obj.get_last_name();

}
protected:
    key first_name, last_name;
    static boost::bimap<key, std::string> names;
    static key seed;
    static key add(const string& s)
    {
        auto it = names.right.find(s);
        if(it == names.right.end())
        {
            // add it
            names.insert({++seed, s});
            return seed;
        }

        return it->second;

    }

};
boost::bimap<key, std::string> User::names;
key User::seed;
#endif // FLYWEIGHT_H
