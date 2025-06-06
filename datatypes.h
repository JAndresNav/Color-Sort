/*
 * datatypes.h
 *
 *  Created on: 21 feb 2024
 *      Author: jluis
 */

#ifndef EXAMEN_2_DATATYPES_H
#define EXAMEN_2_DATATYPES_H

typedef enum {FALSE,TRUE} BOOL;

typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned long long UINT64;
typedef signed char SINT8;
typedef signed short SINT16;
typedef signed int SINT32;
typedef signed long long SINT64;

typedef void TYPE;

TYPE *char_new(char c);
char char_val(TYPE *e);
TYPE *sint32_new(SINT32 i);
SINT32 sint32_val(TYPE *e);

TYPE *string_new(char *s);
char *string_ptr(TYPE *e);

#endif //EXAMEN_2_DATATYPES_H
