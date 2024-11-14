/**
  **********************************************
  *                               __           
  *    ____ ___  ____ ____  _____/ /__________ 
  *   / __ `__ \/ __ `/ _ \/ ___/ __/ ___/ __ \
  *  / / / / / / /_/ /  __(__  ) /_/ /  / /_/ /
  * /_/ /_/ /_/\__,_/\___/____/\__/_/   \____/ 
  *                                            
  **********************************************
  * @file   maestro.c
  * @author Lucas Anatole Marchetti
  * @brief  Maestro is a C library to simplify
  *         dynamic allocations more easily.
  **********************************************
  * @attention
  *
  * Copyright (c) 2024 L.A. MARCHETTI
  * MIT License
  **********************************************
  */

#include "../include/maestro.h"

/**
  * @brief  Create a new maestro instance.
  * @param  element_size: Size of individual elements (e.g., sizeof(int) or sizeof(<your_custom_typedef>)).
  * @warning It is good practice to check if the returned pointer is NULL before using it.
  * @note   This function allocates memory for the maestro structure but not for the data array.
  * @retval Pointer to the newly created maestro instance, or NULL if allocation fails.
  */
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
    ptr_maestro->push_back = maestro_push_back;
    ptr_maestro->erase = maestro_erase;
    ptr_maestro->pop_back = maestro_pop_back;
    return ptr_maestro;
}

/**
  * @brief  Append a new element to the maestro instance.
  * @param  ptr_maestro: Pointer to the maestro instance.
  * @param  value: Pointer to the value to be appended.
  * @note   This function reallocates memory to accommodate the new element.
  *         If reallocation fails, the original data remains unchanged.
  * @note   The function uses memcpy to copy the new element, so the caller
  *         is responsible for managing any dynamic memory within the element.
  * @retval None
  */
void maestro_push_back(maestro* ptr_maestro, const void* value) {
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

/**
  * @brief  Erase a maestro instance and free associated memory.
  * @param  ptr_maestro: Pointer to the maestro instance to be erased.
  * @note   This function frees both the data array and the maestro structure itself.
  * @note   After calling this function, the ptr_maestro should not be used anymore.
  * @retval None
  */
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


/**
  * @brief  Remove the last element from the maestro instance.
  * @param  ptr_maestro: Pointer to the maestro instance.
  * @note   This function reduces the length of the maestro instance by one.
  * @note   If the maestro instance is empty, it frees the memory and sets
  *         the data pointer to NULL.
  *         If reallocation fails while attempting to shrink the memory,
  *         the original data remains unchanged and an error message is printed.
  * @retval None
  */
void maestro_pop_back(maestro *ptr_maestro)
{
    if (ptr_maestro == NULL)
    {
        fprintf(stderr, "Pointer to maestro is NULL\n");
        return;
    }
    if (ptr_maestro->length-1 == 0)
    {
        free(ptr_maestro->data);
        ptr_maestro->data = NULL;
        ptr_maestro->length = 0;
        return;
    }
    void* new_data = realloc(ptr_maestro->data, (ptr_maestro->length - 1) * ptr_maestro->element_size);
    if (new_data == NULL)
    {
        fprintf(stderr, "Unable to allocate or reallocate memory\n");
        return;
    }
    ptr_maestro->data = new_data;
    ptr_maestro->length--;
}