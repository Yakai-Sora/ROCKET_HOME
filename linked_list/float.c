/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** float
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include "new.h"
#include "float.h"

typedef struct
{
    Class   base;
    float   f;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!this)
        raise("Can't do anything with (null) pointers\n");
    this->f = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void) this;
}

static Object *Float_add(FloatClass *a, FloatClass *b)
{
    if (!a || !b)
        raise("Can't do anything with (null) pointers\n");
    return new(Float, a->f + b->f);
}

static Object *Float_sub(FloatClass *a, FloatClass *b)
{
    if (!a || !b)
        raise("Can't do anything with (null) pointers\n");
    return new(Float, a->f - b->f);
}

static Object *Float_mul(FloatClass *a, FloatClass *b)
{
    if (!a || !b)
        raise("Can't do anything with (null) pointers\n");
    return new(Float, a->f * b->f);
}

static Object *Float_div(FloatClass *a, FloatClass *b)
{
    if (!a || !b)
        raise("Can't do anything with (null) pointers\n");
    else if (b->f == 0)
        raise("ERROR: dividing by zero\n");
    return new(Float, a->f / b->f);
}

static bool Float_eq(FloatClass *a, FloatClass *b)
{
    if (!a || !b)
        raise("Can't do anything with (null) pointers\n");
    return (a->f == b->f);
}

static bool Float_lt(FloatClass *a, FloatClass *b)
{
    if (!a || !b)
        raise("Can't do anything with (null) pointers\n");
    return (a->f < b->f);
}

static bool Float_gt(FloatClass *a, FloatClass *b)
{
    if (!a || !b)
        raise("Can't do anything with (null) pointers\n");
    return (a->f > b->f);
}

static char *Float_tostr(Object *this)
{
    char *string = NULL;
    FloatClass *f_num = (FloatClass *)this;
    int size = snprintf(NULL, 0, "<Float (%f)>", f_num->f);

    if (!(string = malloc(size + 1)))
        return (NULL);
    snprintf(string, size + 1, "<Float (%f)>", f_num->f);
    return (string);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_tostr,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__lt__ = (binary_comparator_t)&Float_lt,
        .__gt__ = (binary_comparator_t)&Float_gt
    },
    .f = 0,
};

const Class   *Float = (const Class *)&_description;