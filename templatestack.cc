/*
 * @Author: hunter_zju
 * @Date: 2021-08-22 21:22:40
 * @LastEditTime: 2021-08-22 22:10:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /cpp_example/templatestack.cc
 */

#include <iostream>
#include "templatestack.h"

extern "C" {
#include <assert.h>

#define ASSERT(expression)  assert(expression)
}

using namespace std;

/**
 * @description: Stack constructor using template.
 * @param {*}
 * @return {*}
 */
template <class T>
Stack<T>::Stack(int sz) {
    ASSERT(sz >= 1);

    size = sz;
    top = 0;
    stack = new T[size];
}

/**
 * @description: Stack destructor using template.
 * @param {*}
 * @return {*}
 */
template <class T>
Stack<T>::~Stack() {
    delete [] stack;
}

/**
 * @description: push value into stack.
 * @param {*}
 * @return {*}
 */
template <class T>
void Stack<T>::Push(T value)
{
    ASSERT(!Full());

    stack[top++] = value;
}

/**
 * @description: pop value from stack.
 * @param {*}
 * @return {*}
 */
template <class T>
T Stack<T>::Pop()
{
    ASSERT(!Empty());

    return (stack[--top]);
}

/**
 * @description: check if stack full.
 * @param {*}
 * @return {*}
 */
template <class T>
bool Stack<T>::Full()
{
    return (top == size);
}

/**
 * @description: check if stack empty.
 * @param {*}
 * @return {*}
 */
template <class T>
bool Stack<T>::Empty()
{
    return (top == 0);
}

/**
 * @description: Stack test function.
 * @param {*}
 * @return {*}
 */
template <class T>
void Stack<T>::SelfTest(T start)
{
    T count = start;

    while(!Full()) {
        cout << "pushing " << count << "\n";
        Push(count++);
    }

    while(!Empty()) {
        cout << "poping " << Pop() << "\n";
    }
}

/**
 * @description: main function to run test.
 * @param {*}
 * @return {*}
 */
int main()
{
    Stack<int> *s1 = new Stack<int>(10);
    Stack<char> *s2 = new Stack<char>(10);

    cout << "Testing Stack<int>\n";
    s1->SelfTest(17);

    cout << "Testing Stack<char>\n";
    s2->SelfTest('a');

    delete s1;
    delete s2;
    return 0;
}