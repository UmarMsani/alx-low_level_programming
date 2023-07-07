#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>

int _putchar(char c);
unsigned int binary_to_uint(const char *d);
void print_binary(unsigned long int a);
int get_bit(unsigned long int v, unsigned int index);
int set_bit(unsigned long int *v, unsigned int index);
int clear_bit(unsigned long int *v, unsigned int index);
unsigned int flip_bits(unsigned long int v, unsigned long int u);
int get_endianness(void);

#endif
