#ifndef LISKOV_H
#define LISKOV_H

class Rectangle
{
public:
    Rectangle() = delete ;
protected:
    int width, height;
public:
    Rectangle(const int width, const int height): width(width), height(height){}

    int get_width() const {return width;}
    virtual void set_width(const int width)
    {
        this->width = width;
    }

    int get_height() const {return height;}
    virtual void set_height(const int height)
    { this->height = height;}

    int area() const {return width * height;}

};

class Square: public Rectangle
{
public:
    Square(int size): Rectangle(size, size) {}
    void set_width(const int width) override
    {
        this->width = height = width;
    }
    void set_height(const int height) override
    {
        this->height = width = height;
    }

};

#endif // LISKOV_H
