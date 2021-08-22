/*
 * @Author: hunter_zju
 * @Date: 2021-08-22 09:54:01
 * @LastEditTime: 2021-08-22 22:11:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /cpp_example/inheritstack.cc
 */

#include "inheritstack.h"
#include <iostream>

extern "C" {
#include <assert.h>

#define ASSERT(expression)  assert(expression)
}

using namespace std;

Stack::Stack() {}
Stack::~Stack() {}

ArrayStack::ArrayStack(int sz) : Stack()
{
    ASSERT(sz >= 1);

    size = sz;
    top = 0;
    stack = new int[size];
}

ArrayStack::~ArrayStack()
{
    delete [] stack;
}

void ArrayStack::Push(int value)
{
    ASSERT(!Full());

    stack[top++] = value;
}

int ArrayStack::Pop()
{
    ASSERT(!Empty());

    return (stack[--top]);
}

bool ArrayStack::Full()
{
    return (top == size);
}

bool ArrayStack::Empty()
{
    return (top == 0);
}

ListStack::ListStack() : Stack()
{
    stack = new List;
}

ListStack::~ListStack()
{
    delete stack;
}

void ListStack::Push(int value) {
    stack->Prepend(value);
}

int ListStack::Pop()
{
    ASSERT(!Empty());

    return stack->Remove();
}

bool ListStack::Full()
{
    return FALSE;
}

bool ListStack::Empty()
{
    return stack->Empty();
}

void Stack::SelfTest(int numToPush)
{
    int count = 17;

    for(int i=0; i<numToPush; i++) {
        ASSERT(!Full());
        cout << "pushing " << count << "\n";
        Push(count++);
    }

    while(!Empty()) {
        cout << "popping " << Pop() << "\n";
    }
}

int main()
{
    Stack *s1 = new ArrayStack(10);
    Stack *s2 = new ListStack();

    cout << "Testing ArrayStack.\n";
    s1->SelfTest(10);

    cout << "Testing ListStack.\n";
    s2->SelfTest(10);

    delete s1;
    delete s2;
    return 0;
}