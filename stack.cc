/*
 * @Author: hunter_zju
 * @Date: 2021-08-21 16:24:15
 * @LastEditTime: 2021-08-21 17:22:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /cpp_example/stack.cc
 */

#include <iostream>
#include "stack.h"

extern "C" {
#include <assert.h>

#define ASSERT(expression)  assert(expression)
}

/**
 * @description: constructor for Stack class.
 * @param {int} sz -- max number of elements on the Stack.
 * @return {*}
 */
Stack::Stack(int sz)
{
    ASSERT(sz >= 1);

    size = sz;
    top = 0;
    stack = new int[size];
}

/**
 * @description: destructor for Stack class.
 * @param {*}
 * @return {*}
 */
Stack::~Stack()
{
    delete [] stack;
}

/**
 * @description: put an integer on the top of the stack.
 * @param {int} value -- the value to put on the stack.
 * @return {*}
 */
void Stack::Push(int value)
{
    ASSERT(!Full());

    stack[top++] = value;
}

/**
 * @description: remove an integer from the top of the stack. Error if the stack is empty.
 * @param {*}
 * @return {*}
 */
int Stack::Pop()
{
    ASSERT(!Empty());

    return (stack[--top]);
}

/**
 * @description: return True if the stack has no more room.
 * @param {*}
 * @return {*}
 */
bool Stack::Full()
{
    return (top == size);
}

/**
 * @description: return True if the stack is empty.
 * @param {*}
 * @return {*}
 */
bool Stack::Empty()
{
    return (top == 0);
}

/**
 * @description: Test stack implementation by pushing 10 numbers onto the stack.
 * @param {*}
 * @return {*}
 */
void Stack::SelfTest()
{
    int count = 17;

    while(!Full()){
        cout << "pushing " << count << "\n";
        Push(count++);
    }

    while(!Empty()){
        cout << "poping " << Pop() << "\n";
    }
}

/**
 * @description: run test code for stack implementation. 
 * @param {*}
 * @return {*}
 */
int main()
{
    Stack *stack = new Stack(10);

    stack->SelfTest();

    delete stack;
    return 0;
}