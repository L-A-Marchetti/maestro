#include "../include/maestro.h"

int main()
{
    imaestro* my_imaestro = imaestro_new();
    if (my_imaestro == NULL) {
        return 0;
    }
    my_imaestro->append(my_imaestro, 5);
    my_imaestro->append(my_imaestro, 20);
    my_imaestro->append(my_imaestro, 400);
    for (size_t i = 0; i < my_imaestro->size; i++)
    {
        printf("%d\n", my_imaestro->data[i]);
    }
    my_imaestro->erase(my_imaestro);
    return 0;
}