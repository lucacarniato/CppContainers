#ifndef STACK_HPP
#define STACK_HPP

#include "MyArray.hpp"
#include "ArrayException.hpp"
#include "StackException.hpp"
#include <iostream>

namespace Luca
{
   namespace Containers
   {
      template <class T>
      class Stack
      {
         size_t m_current;
         MyArray<T> m_array; // stack uses composition, not inheritance

      public:         
         Stack();
         Stack(int dim);

         //push and pop operators
         void Push(T a);
         T Pop();
      };


      template <class T>
      Stack<T>::Stack() :m_current(0), m_array() 
      {
      };

      template <class T>
      Stack<T>::Stack(int dim) :m_current(0), m_array(dim)
      {
      };

      template <class T>
      void Stack<T>::Push(T a)
      {
         try
         {
            m_array[m_current] = a;
            cout << "Element " << a << " pushed"<< endl;
            ++m_current;
         }
         catch ( OutOfBounds )
         {
            throw (StackFullException(m_current));
         }
      };

      template <class T>
      T Stack<T>::Pop()
      {
         T a;
         try
         {
            --m_current;
            a = m_array[m_current];
            cout << "Element " << a << " Pop" << endl;
         }
         catch ( OutOfBounds )
         {
            throw (StackEmptyException());
         }
         return a;
      };
   }
}


#endif