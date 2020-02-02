/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 05
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "list.h"
#include "new.h"

typedef struct ListItemStruct
{
    Object *obj;
    struct ListItemStruct *next;
} ListItem;

typedef struct
{
    Iterator    base;
    ListItem   *_list;
    Class *_type;
}   ListIteratorClass;

typedef struct
{
    Container   base;
    Class       *_type;
    size_t      _size;
    ListItem    *_list;
} ListClass;


///////////////////////// ITERATOR /////////////////////////

static void     ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    ListClass *list = va_arg(*args, ListClass *);
    this->_list = list->_list;
    this->_type = list->_type;
}

static void     ListIterator_dtor(ListIteratorClass *this)
{
    (void)  this;
}

static Object   *ListIterator_getval(ListIteratorClass *this)
{
    return this->_list->obj;
}

static void     ListIterator_setval(ListIteratorClass *this, ...)
{
    va_list ap;

    va_start(ap, this);
    this->_list->obj = va_new(this->_type, &ap);
    va_end(ap);
}

static void  ListIterator_incr(ListIteratorClass *this)
{
 this->_list = this->_list->next;
}

static const ListIteratorClass   ListIteratorDescr = {
 {   /* Iterator struct */
     {   /* Class struct */
         .__size__ = sizeof(ListIteratorClass),
         .__name__ = "ListIterator",
         .__ctor__ = (ctor_t)&ListIterator_ctor,
         .__dtor__ = (dtor_t)&ListIterator_dtor,
         .__str__ = NULL,
         .__add__ = NULL,
         .__sub__ = NULL,
         .__mul__ = NULL,
         .__div__ = NULL,
         // .__eq__ = (binary_comparator_t)&ListIterator_eq,
         // .__gt__ = (binary_comparator_t)&ListIterator_gt,
         // .__lt__ = (binary_comparator_t)&ListIterator_lt,
     },
     .__incr__ = (incr_t)&ListIterator_incr,
     .__getval__ = (getval_t)&ListIterator_getval,
     .__setval__ = (setval_t)&ListIterator_setval,
 },
 ._list = NULL,
};

const Class     *ListIterator = (const Class *)&ListIteratorDescr;

static void List_push_elem_front(ListItem **list, Object *elem)
{
    ListItem *node = malloc(sizeof(ListItem));

    if (!node)
        raise("Out of memory");
    node->obj = elem;
    if (!list)
        raise("Empty pointer");
    if (!(*list)) {
        node->next = NULL;
        (*list) = node;
    } else {
        node->next = (*list);
        (*list) = node;
    }
}

// static void List_push_elem_back(ListItem **list, Object *elem)
// {
//     ListItem *it = NULL;
//     ListItem *node = malloc(sizeof(*node));

//     if (!node)
//         raise("Out of memory");
//     node->obj = elem;
//     node->next = NULL;
//     if (!(*list)) {
//         (*list) = node;
//         return;
//     }
//     for (it = (*list); it; it = it->next);
//     it->next = node;
// }

static void List_ctor(ListClass *this, va_list *args)
{
    va_list ap;
    size_t index = 0;

    this->_size = va_arg(*args, size_t);
    this->_type = va_arg(*args, Class *);
    this->_list = NULL;
    for (; index < this->_size; index++) {
        va_copy(ap, *args);
        List_push_elem_front(&(this->_list), va_new(this->_type, &ap));
    }
    va_end(ap);
}

static void List_del_elem_front(ListItem **list)
{
    ListItem *node = (*list);

    if (!node)
        return;
    else if (node->next == NULL) {
        free(node);
        list = NULL;
        return;
    }
    (*list) = node->next;
    free(node);
}

static void List_dtor(ListClass *this)
{
    if (!this)
        return;
    else if (!this->_list) {
        free(this);
        return;
    }
    while (this->_list)
        List_del_elem_front(&(this->_list));
    // free(this->_list);
    // free(this);
}

static size_t List_len(ListClass *this)
{
    size_t n = 0;

    if (!this || !(this->_list))
        return (0);
    for (ListItem *item = this->_list; item; item = item->next, ++n);
    return (n);
}

static const ListClass  list_descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        // .__begin__ = (iter_t)&List_begin,
        // .__end__ = (iter_t)&List_end,
        // .__getitem__ = (getitem_t)&List_getitem,
        // .__setitem__ = (setitem_t)&List_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._list = NULL
};

const Class     *List = (const Class *)&list_descr;