#include "creational.h"

Creational::Creational()
{

}
/**
 * @brief get_create
 * @return the owner says to the function caller
 *      that you are responsible of the returned pointer
 *      you should manage it, whether delete or assign to
 *      a shared pointer.
 */
gsl::owner<Creational*> get_create()
{

    return (new Creational());
}

int main(int argc, char *argv[])
{

    Creational *crt = get_create();
    delete crt;

    return 0;
}

