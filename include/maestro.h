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

#define DEFAULT_SIZE 0

#include <stdio.h>
#include <stdlib.h>

typedef struct imaestro {
    int *data;
    size_t size;
    void (*append)(struct imaestro*, int);
    void (*erase)(struct imaestro*);
} imaestro;

imaestro* imaestro_new();
void imaestro_append(imaestro* ptr_imaestro, int value);
void imaestro_erase(imaestro* ptr_imaestro);

#endif //MAESTRO_H