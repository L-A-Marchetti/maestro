#include "../include/maestro.h"

maestro* maestro_new(size_t element_size)
{
    maestro* ptr_maestro = (maestro*)malloc(sizeof(maestro));
    if (ptr_maestro == NULL)
    {
        fprintf(stderr, "Unable to create a new maestro instance");
        return NULL;
    }
    ptr_maestro->data = NULL;
    ptr_maestro->length = DEFAULT_LENGTH;
    ptr_maestro->element_size = element_size;
    ptr_maestro->append = maestro_append;
    ptr_maestro->erase = maestro_erase;
    return ptr_maestro;
}

void maestro_append(maestro* ptr_maestro, const void* value) {
    if (ptr_maestro == NULL)
    {
        fprintf(stderr, "Pointer to maestro is NULL\n");
        return;
    }
    void* new_data = realloc(ptr_maestro->data, (ptr_maestro->length + 1) * ptr_maestro->element_size);
    if (new_data == NULL)
    {
        fprintf(stderr, "Unable to allocate or reallocate memory\n");
        return;
    }
    ptr_maestro->data = new_data;
    memcpy(
        (char*)ptr_maestro->data + (ptr_maestro->length * ptr_maestro->element_size),
        value,
        ptr_maestro->element_size
    );
    ptr_maestro->length++;
}

void maestro_erase(maestro *ptr_maestro)
{
    if (ptr_maestro == NULL)
    {
        fprintf(stderr, "Pointer to maestro is NULL\n");
        return;
    }
    free(ptr_maestro->data);
    free(ptr_maestro);
}