/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include "new.h"
#include "int.h"

typedef struct
{
    Class   base;
    int     nb;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->nb = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void) this;
}

static Object *Int_add(IntClass *a, IntClass *b)
{
    if (!a || !b) raise("Cant do anything with (NULL) pointers");
    return new(Int, a->nb + b->nb);
}

static Object *Int_sub(IntClass *a, IntClass *b)
{
    if (!a || !b) raise("Cant do anything with (NULL) pointers");
    return new(Int, a->nb - b->nb);
}

static Object *Int_mul(IntClass *a, IntClass *b)
{
    if (!a || !b) raise("Cant do anything with (NULL) pointers");
    return new(Int, a->nb * b->nb);
}

static Object *Int_div(IntClass *a, IntClass *b)
{
    if (!a || !b) raise("Cant do anything with (NULL) pointers");
    if (b->nb == 0)
        raise("Division by 0");
    return new(Int, a->nb / b->nb);
}

static bool Int_equal(IntClass *a, IntClass *b)
{
    if (!a || !b) raise("Cant do anything with (NULL) pointers");
    return a->nb == b->nb;
}

static bool Int_less(IntClass *a, IntClass *b)
{
    if (!a || !b) raise("Cant do anything with (NULL) pointers");
    return a->nb < b->nb;
}

static bool Int_more(IntClass *a, IntClass *b)
{
    if (!a || !b) raise("Cant do anything with (NULL) pointers");
    return a->nb > b->nb;
}

static char *Int_tostr(Object *this)
{
    char *string = NULL;
    IntClass *i_num = (IntClass *)this;
    int size = snprintf(NULL, 0, "<Int (%d)>", i_num->nb);

    if (!(string = malloc(size + 1)))
        raise("Unable to allocate memory");
    snprintf(string, size + 1, "<Int (%d)>", i_num->nb);
    return (string);
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_tostr,
        .__add__ = (binary_operator_t)&Int_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Int_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_equal,
        .__gt__ = (binary_comparator_t)&Int_more,
        .__lt__ = (binary_comparator_t)&Int_less
    },
    .nb = 0,
};

const Class   *Int = (const Class *)&_description;
