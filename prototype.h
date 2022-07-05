#ifndef PROTOTYPE_H
#define PROTOTYPE_H
#include <string>
#include <boost/serialization/access.hpp>
using namespace std;

class Prototype
{
public:
    Prototype();
};

struct Address
{
    string street;
    string city;
    int suite;
//    Address(string street, string city, int suite):
//        street{street},
//        city{city},
//        suite{suite}
//    {}
//    Address(Address& address):
//        street{address.street},
//        city{address.city},
//        suite(address.suite)
//    {}
//    Address(
//            string street,
//            string city,
//            int   suite
//            ):
//        street{street},
//        city{city},
//        suite{suite}
//    {}
private:
    friend class boost::serialization::access;
    template<class Ar>
    void serialize (Ar& ar, const unsigned int version)
    {

        ar & street;
        ar & city;
        ar & suite;
    }
};

struct Contact
{
    string name;
    Address * address = nullptr;
//    Contact(){}
//    Contact(const Contact& other):
//        name{other.name},
//        address{new Address{*other.address}}
//    {
////        address = new Address(
////                    other.address->street,
////                    other.address->city,
////                    other.address->suite);
//        fprintf(stderr,
//                "name: %s\n"
//                "street: %s\n"
//                "city: %s\n"
//                "suite: %d\n",
//                this->name.c_str(),
//                this->address->street.c_str(),
//                this->address->city.c_str(),
//                this->address->suite
//                );
//    }

//    Contact& operator=(const Contact& other)
//    {
//        if(this == &other)
//            return *this;

//        name = other.name;
//        address = other.address;
//        return *this;
//    }
private:
    friend class boost::serialization::access;
    template<class Ar>
    void serialize(Ar& ar, const unsigned int version)
    {
        ar & name;
        ar & address;
    }
};

#endif // PROTOTYPE_H
