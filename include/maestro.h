/**
  **********************************************
  *                               __           
  *    ____ ___  ____ ____  _____/ /__________ 
  *   / __ `__ \/ __ `/ _ \/ ___/ __/ ___/ __ \
  *  / / / / / / /_/ /  __(__  ) /_/ /  / /_/ /
  * /_/ /_/ /_/\__,_/\___/____/\__/_/   \____/ 
  *                                            
  **********************************************
  * @file   maestro.h
  * @author Lucas Anatole Marchetti
  * @brief  Maestro is a C library to simplify
  *         dynamic allocations more easily.
  **********************************************
  * @attention
  *
  * Copyright (c) 2024 L.A. MARCHETTI
  * MIT License
  **********************************************
  * This header file defines the `maestro`
  * structure and its associated functions for
  * managing a dynamic array in C. The `maestro`
  * structure provides methods for adding,
  * removing, and manipulating elements in the
  * array.
  *
  * @note The `maestro` structure uses void
  *       pointers to allow for dynamic storage
  *       of any data type. The caller is
  *       responsible for managing the memory
  *       of the data stored in the array.
  */

#ifndef MAESTRO_H
#define MAESTRO_H

#define DEFAULT_LENGTH 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  * @struct maestro
  * @brief Structure representing a dynamic array.
  *
  * This structure holds the data for a dynamic array, including its size,
  * length, and function pointers for manipulating the array.
  */
typedef struct maestro {
    void* data;                       /**< Pointer to the array data */
    size_t element_size;              /**< Size of each element in bytes */
    size_t length;                    /**< Current number of elements in the array */
    void (*push_back)(struct maestro* ptr_maestro, const void* value); /**< Function to add an element */
    void (*erase)(struct maestro* ptr_maestro);                        /**< Function to erase all elements */
    void (*pop_back)(struct maestro* ptr_maestro);                     /**< Function to remove the last element */
    void (*insert)(struct maestro* ptr_maestro, int pos, const void* value); /**< Function to insert an element at a specific position */
} maestro;

/**
  * @brief  Create a new maestro instance.
  *
  * This function allocates memory for a new maestro instance and initializes
  * its properties.
  *
  * @param element_size Size of each element that will be stored in the array.
  * @retval Pointer to the newly created maestro instance, or NULL if allocation fails.
  */
maestro* maestro_new(size_t element_size);

/**
  * @brief Append a new element to the maestro instance.
  *
  * This function reallocates memory to accommodate the new element. If 
  * reallocation fails, the original data remains unchanged.
  *
  * @param ptr_maestro Pointer to the maestro instance.
  * @param value Pointer to the value to be appended.
  */
void maestro_push_back(maestro* ptr_maestro, const void* value);

/**
  * @brief Erase a maestro instance and free associated memory.
  *
  * This function frees both the data array and the maestro
  * structure itself.
  *
  * @param ptr_maestro Pointer to the maestro instance.
  */
void maestro_erase(maestro* ptr_maestro);

/**
  * @brief Remove the last element from the maestro instance.
  *
  * This function reduces the length of the maestro instance by one. If 
  * it is empty, it frees memory and sets data pointer to NULL.
  *
  * @param ptr_maestro Pointer to the maestro instance.
  */
void maestro_pop_back(maestro* ptr_maestro);

#endif // MAESTRO_H
