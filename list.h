/*
 * @Author: your name
 * @Date: 2021-08-22 08:49:01
 * @LastEditTime: 2021-08-22 10:02:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /cpp_example/list.h
 */

#ifndef LIST_H
#define LIST_H

#include <stddef.h>     // NULL defined in this file.

class ListElement;

class List {
    public:
        List();
        ~List();

        void Prepend(int value);
        int Remove();

        bool Empty();

        void SelfTest();
    
    private:
        ListElement *first;
        ListElement *last;
};

#endif