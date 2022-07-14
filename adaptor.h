#ifndef ADAPTOR_H
#define ADAPTOR_H

#include <iostream>
#include <vector>

struct Point
{
    int x, y;
};

struct Line
{
    friend class Adaptor;
    Line(Point & begin, Point& end):
        begin(begin),
        end(end){}
    Line(int x0,int y0, int x1, int y1)
    {
        begin.x = x0;
        begin.y = y0;
        end.x = x1;
        end.y = y1;

    }

private:
    Point begin;
    Point end;
};

struct drawLine{
    drawLine(Point& begin, Point & end)
    {
        std::cout<<"Drawing a line from: ("<<begin.x<<", "<<begin.y<<") to"\
                   " ("<<end.x<<", "<<end.y<<")."<<std::endl;
    }
};

struct Adaptor
{
    public:
    Adaptor() = delete ;
    Adaptor(Line& line):
        a_begin(line.begin),
        a_end(line.end)
    {}

    std::vector<Point> get_points()
    {
        std::vector<Point> points{a_begin, a_end};
        return points;
    }

private:
    Point a_begin;
    Point a_end;

};

#endif // ADAPTOR_H
