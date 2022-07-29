#ifndef PROXY_H
#define PROXY_H

#include <ostream>
#include <iostream>
class Proxy
{
public:
    Proxy();
};

template<typename T>
class Property
{
public:
    Property(T value)
        : value{value}
    {

    }

    T operator=(const T value)
    {
        this->value = value;
    }
     operator T()
    {
        return value;
    }

protected:
    T value;
};
/////////// Virtual Proxy

class Image
{
public:
    virtual void draw() = 0;
};

class Bitmap: Image
{
public:
    Bitmap(const std::string& file_name):
        file_name{file_name}
    {
        std::cout<< "Loading "<<file_name<<
                    " From file.\n";
    }

    void draw() override
    {
        std::cout<<"Drawing the "<< file_name<<std::endl;
    }

private:
    std::string file_name;
};

class  LazyBitmap: Image
{
    LazyBitmap(const std::string& file_name):
        file_name{file_name}{}
    ~LazyBitmap(){delete bmp;}

    void draw() override
    {
        if(!bmp)
        {
            bmp = new Bitmap(file_name);
            bmp->draw();
        }

    }

private:
    Bitmap *bmp{nullptr};
    std::string file_name;

};

void draw_image(Image& img)
{
    std::cout<<"Gonna to draw the image"<<std::endl;
    img.draw();

}
#endif // PROXY_H


