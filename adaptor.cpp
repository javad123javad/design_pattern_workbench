#include "adaptor.h"



int main()
{
    Line l1(0, 0, 10, 10);
    Adaptor a1(l1);
    drawLine drl(a1.get_points()[0],a1.get_points()[1]);
    return 0;
}
