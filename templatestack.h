/*
 * @Author: hunter_zju
 * @Date: 2021-08-22 21:21:48
 * @LastEditTime: 2021-08-22 22:04:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /cpp_example/templatestack.h
 */

#ifndef TEMPLATESTACK_H
#define TEMPLATESTACK_H

/**
 * @description: Stack impletation using template.
 * @param {*}
 * @return {*}
 */
template <class T>
class Stack {
    public:
        Stack(int sz);
        ~Stack();

        void Push(T value);
        T Pop();

        bool Full();
        bool Empty();

        void SelfTest(T start);
    
    private:
        int size;
        int top;
        T *stack;
};

#endif