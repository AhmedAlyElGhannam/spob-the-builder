#ifndef STRING_H
#define STRING_H

#include <stdbool.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#pragma GCC diagnostic ignored "-Wstringop-truncation"
#pragma GCC diagnostic ignored "-Wformat-truncation="
#pragma GCC diagnostic push

int8_t tolower(int8_t s1);
uint16_t strlen(const int8_t* ptr);
uint16_t strnlen(const int8_t* ptr, uint16_t max);
uint16_t strnlen_terminator(const int8_t* str, uint16_t max, int8_t terminator);
int16_t istrncmp(const int8_t* s1, const int8_t* s2, int16_t n);
int16_t strncmp(const int8_t* str1, const int8_t* str2, int16_t n);
int8_t* strcpy(int8_t* dest, const int8_t* src);
int8_t* strncpy(int8_t* dest, const int8_t* src, int16_t count);
bool isdigit(int8_t c);
int16_t tonumericdigit(int8_t c);
int8_t* strtok(int8_t* str, const int8_t* delimiters);
void printhex(int8_t *str, int16_t size, int8_t delim);
int16_t nstoh(int16_t srcport);
void zero(int8_t *str, int16_t size);

#endif

