/*
 * @Author: hunter_zju
 * @Date: 2021-08-22 08:46:52
 * @LastEditTime: 2021-08-22 22:12:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /cpp_example/inheritstack.h
 */

#ifndef INHERITSTACK_H
#define INHERITSTACK_H

#include "list.h"

const bool FALSE = false;
const bool TRUE = true;

/**
 * @description: stack impletation using inherit.
 * @param {*}
 * @return {*}
 */
class Stack {
    public:
        virtual ~Stack();

        virtual void Push(int value) = 0;
        virtual int Pop() = 0;

        virtual bool Empty() = 0;
        virtual bool Full() = 0;

        void SelfTest(int numToPush);
    
    protected:
        Stack();
};

class ArrayStack : public Stack {
    public:
        ArrayStack(int sz);
        ~ArrayStack();

        void Push(int value);
        int Pop();

        bool Full();
        bool Empty();

    private:
        int size;
        int top;
        int *stack;
};

class ListStack : public Stack {
    public:
        ListStack();
        ~ListStack();

        void Push(int value);
        int Pop();

        bool Full();
        bool Empty();
    
    private:
        List *stack;
};

#endif
