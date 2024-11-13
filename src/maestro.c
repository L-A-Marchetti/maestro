#include "../include/maestro.h"

imaestro* imaestro_new()
{
    imaestro* ptr_imaestro = (imaestro*)malloc(sizeof(imaestro));
    if (ptr_imaestro == NULL)
    {
        fprintf(stderr, "Unable to create the new imaestro\n");
        return NULL;
    }
    ptr_imaestro->data = NULL;
    ptr_imaestro->size = DEFAULT_SIZE;
    ptr_imaestro->append = imaestro_append;
    ptr_imaestro->erase = imaestro_erase;
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

void imaestro_erase(imaestro *ptr_imaestro)
{
    if (ptr_imaestro == NULL)
    {
        fprintf(stderr, "Pointer to imaestro is NULL\n");
        return;
    }
    free(ptr_imaestro->data);
    free(ptr_imaestro);
}