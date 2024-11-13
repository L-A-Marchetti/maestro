#include "../include/maestro.h"

imaestro* imaestro_new()
{
    imaestro* ptr_imaestro = (imaestro*)malloc(sizeof(imaestro));
    if (ptr_imaestro == NULL)
    {
        fprintf(stderr, "unable to create the new imaestro");
        return NULL;
    }
    ptr_imaestro->data = NULL;
    ptr_imaestro->size = 0;
    return ptr_imaestro;
}

void imaestro_append(imaestro* ptr_imaestro, int value) {
    if (ptr_imaestro == NULL)
    {
        fprintf(stderr, "Pointer to imaestro is NULL\n");
        return;
    }
    int *new_data = (int*)realloc(ptr_imaestro->data, (ptr_imaestro->size + 1) * sizeof(int));
    if (new_data == NULL)
    {
        fprintf(stderr, "Unable to allocate or reallocate memory\n");
        return;
    }
    ptr_imaestro->data = new_data;
    ptr_imaestro->data[ptr_imaestro->size] = value;
    ptr_imaestro->size++;
}