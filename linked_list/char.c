/*
** EPITECH PROJECT, 2019
** cpp_rush1_2019
** File description:
** char
*/

#include "char.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include "new.h"

typedef struct
{
   Class base;
   int c;
} Charclass;

static void Char_ctor(Charclass *this, va_list *args)
{
    this->c = va_arg(*args, int);
}

static void Char_dtor(Charclass *this)
{
    (void) this;
}

static char *Char_tostr(Object *this)
{
    char *string = NULL;
    Charclass *chr = (Charclass *)this;
    int size = snprintf(NULL, 0, "<Char (%c)>", chr->c);

    if (!(string = malloc(size + 1)))
        return (NULL);
    snprintf(string, size + 1, "<Char (%c)>", chr->c);
    return (string);
}

static Object *Char_add(Charclass *a, Charclass *b)
{
    if (!a || !b)
        raise("Error with pointers");
    return new(Char, a->c + b->c);
}

static Object *Char_sub(Charclass *a, Charclass *b)
{
    if (!a || !b)
        raise("Error with pointers");
    return new(Char, a->c - b->c);
}

static Object *Char_mul(Charclass *a, Charclass *b)
{
    if (!a || !b)
        raise("Error with pointers");
    return new(Char, a->c * b->c);
}

static Object *Char_div(Charclass *a, Charclass *b)
{
    if (!a || !b)
        raise("Error with pointers");
    if (b->c == 0)
        raise("Error : division by 0");
    return new(Char, a->c / b->c);
}

static bool Char_eq(Charclass *a, Charclass *b)
{
    if (!a || !b)
        raise("Error with pointers");
    return (a->c == b->c);
}

static bool Char_gt(Charclass *a, Charclass *b)
{
    if (!a || !b)
        raise("Error with pointers");
    return (a->c > b->c);
}

static bool Char_lt(Charclass *a, Charclass *b)
{
    if (!a || !b)
        raise("Error with pointers");
    return (a->c < b->c);
}

static const Charclass _description = {
    {   /* Class struct */
        .__size__ = sizeof(Charclass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_tostr,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .c = 0,
};

const Class   *Char = (const Class *)&_description;
