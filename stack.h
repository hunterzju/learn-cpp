/*
 * @Author: hunter_zju
 * @Date: 2021-08-21 16:24:11
 * @LastEditTime: 2021-08-21 17:21:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /cpp_example/stack.h
 */

#ifndef STACK_H
#define STACK_H

using namespace std;

class Stack {
    public:
        Stack(int sz);
        ~Stack();   

        void Push(int value);
        int Pop();

        bool Full();
        bool Empty();   
        
        void SelfTest();
    
    private:
        int size;
        int top;
        int *stack;
};

#endif
