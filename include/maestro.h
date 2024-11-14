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
  */

#ifndef MAESTRO_H
#define MAESTRO_H

#define DEFAULT_LENGTH 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct maestro {
    void* data;
    size_t element_size;
    size_t length;
    void (*push_back)(struct maestro* ptr_maestro, const void* value);
    void (*erase)(struct maestro* ptr_maestro);
    void (*pop_back)(struct maestro* ptr_maestro);
} maestro;

maestro* maestro_new(size_t element_size);
void maestro_push_back(maestro* ptr_maestro, const void* value);
void maestro_erase(maestro* ptr_maestro);
void maestro_pop_back(maestro* ptr_maestro);

#endif //MAESTRO_H