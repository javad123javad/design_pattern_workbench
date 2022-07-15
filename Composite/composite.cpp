#include "composite.h"

Composite::Composite()
{

}

int main(int argc, char *argv[])
{
    Circle c1, c2;
    ObjectGroup g1;
    ObjectGroup g2;
    g2.insert_object(new Circle);
    g1.insert_object(&c1);
    g1.insert_object(&c2);
    g1.insert_object(&g2);
    g1.draw();
    return 0;
}
