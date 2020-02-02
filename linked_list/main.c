/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "int.h"
#include "new.h"

int main(void)
{
    Object *list = new(List, 3, Int, 10);
    (void) list;
    // Object *inc = new(ListIterator, list);
    // Object *inc2 = new(ListIterator, list);

    // setval(inc, 10);
    // incr(inc);
    // setval(inc, 12);
    // incr(inc);
    // setval(inc, 13);
    // for (size_t i = 0; i < 3; i++){
    //     printf("%s", str(getval(inc2)));
    //     incr(inc2);
    // }
    // delete(list);
    return (0);
}