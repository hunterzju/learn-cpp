/*
 * @Author: hunter_zju
 * @Date: 2021-08-22 08:58:44
 * @LastEditTime: 2021-08-22 10:04:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /cpp_example/list.cc
 */

#include "list.h"

extern "C" {
#include <assert.h>

#define ASSERT(expression)  assert(expression)
}

// const int NULL = 0;

/**
 * @description: the class defines a list element. 
 * @param {*}
 * @return {*}
 */
class ListElement {
    public:
        ListElement(int value) { item = value; next = NULL;};

        ListElement *next;

        int item;
};

/**
 * @description: constructor for List class.
 * @param {*}
 * @return {*}
 */
List::List() {
    first = last = NULL;
}

/**
 * @description: destructor for List class 
 * @param {*}
 * @return {*}
 */
List::~List() {
    while (!Empty())
    (void) Remove();
}

/**
 * @description: Insert a value before first.
 * @param {int} value -- number to insert.
 * @return {*}
 */
void List::Prepend(int value)
{
    ListElement *element = new ListElement(value);

    if(Empty()) {
        first = element;
        last = element;
    }
    else {
        element->next = first;
        first = element;
    }
}

/**
 * @description: Remove a value from List.
 * @param {*}
 * @return {*}
 */
int List::Remove()
{
    ListElement * element = first;
    int value;

    ASSERT(!Empty());

    element = first;
    value = first->item;

    if(first == last) {
        first = NULL;
        last = NULL;
    }
    else {
        first = element->next;
    }

    delete element;
    return value;
}

/**
 * @description: Return True if List is empty.
 * @param {*}
 * @return {*}
 */
bool List::Empty()
{
    return (first == NULL);
}