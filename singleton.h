#ifndef SINGLETON_H
#define SINGLETON_H


class Singleton
{
public:
    static Singleton& get();
    Singleton(Singleton const&) = delete ;
    Singleton(Singleton&&) = delete ;
    Singleton& operator=(Singleton const&) = delete ;
    Singleton& operator=(Singleton &&) = delete ;
protected:

    Singleton();
};

class Printer
{
    static int id;
public:
    int get_id() const { return id;}
    void set_id(int value){ id = value;}
};
int Printer::id = 0;

#endif // SINGLETON_H
