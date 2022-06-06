#ifndef PERSON_H
#define PERSON_H


class Person
{
public:
    Person(int age);

    int getAge() const;

    void setAge(int value);

private:
    int age;

};

#endif // PERSON_H
