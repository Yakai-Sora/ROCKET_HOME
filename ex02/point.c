/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdarg.h>
#include "new.h"
#include "point.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void) this;
}

static Object *Point_add(PointClass *a, PointClass *b)
{
    return new(Point, a->x + b->x, a->y + b->y);
}

static Object *Point_sub(PointClass *a, PointClass *b)
{
    return new(Point, a->x - b->x, a->y - b->y);
}

static char *Point_tostr(Object *this)
{
    char *string = NULL;
    PointClass *point = (PointClass *)this;
    int size = snprintf(NULL, 0, "<Point (%d, %d)>", point->x, point->y);

    if (!(string = malloc(size + 1)))
        return (NULL);
    snprintf(string, size + 1, "<Point (%d, %d)>", point->x, point->y);
    return (string);
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_tostr,
        .__add__ = (binary_operator_t)&Point_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Point_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;