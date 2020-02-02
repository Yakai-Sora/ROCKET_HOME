#include "object.h"
#include "raise.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

Object  *va_new(const Class  *class, va_list* ap)
{
    Object *this = NULL;

    if ((this = malloc(class->__size__)) == NULL)
        raise("Out of memory");
    memcpy(this, (Object *)class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(this, ap);
    return (this);
}

Object *new(const Class *class, ...)
{
    va_list list;
    Object *this = NULL;

    if (!class)
        return NULL;
    va_start(list, class);
    this = va_new(class, &list);
    va_end(list);
    return (this);
}

void delete(Object *ptr)
{
    ((Class *)(ptr))->__dtor__((Class *)ptr);
    free(ptr);
    ptr = NULL;
}