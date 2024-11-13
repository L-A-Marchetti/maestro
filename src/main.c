#include "../include/maestro.h"

int main()
{
    imaestro* my_imaestro = imaestro_new();
    imaestro_append(my_imaestro, 5);
    imaestro_append(my_imaestro, 20);
    imaestro_append(my_imaestro, 400);
    for (size_t i = 0; i < my_imaestro->size; i++)
    {
        printf("%d\n", my_imaestro->data[i]);
    }
    return 0;
}