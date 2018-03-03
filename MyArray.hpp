#ifndef MY_ARRAY_TPP
#define MY_ARRAY_TPP
#include <memory>
#include <algorithm>
#include <initializer_list>

#include "ArrayException.hpp"

namespace Luca
{
   namespace Containers
   {
      template <class T>
      class MyArray
      {
      protected: 
         size_t m_size;
         std::unique_ptr<T> m_data;
         static size_t def_size;
      public:
         MyArray();                                       
         MyArray(size_t size);                            
         MyArray(const MyArray<T>& a); 
         MyArray(std::initializer_list<T> l);

         virtual ~MyArray();   

         //constructor with size and value
         MyArray(const size_t size, const T& value);
         //assignment operator
         MyArray<T>& operator = (const MyArray<T>& a);    

         //brackets operators
         T& operator[] (size_t index);
         const T& operator[] (size_t index) const;

         //get the size of the array
         size_t size() const;
      };

      template <class T>
      MyArray<T>::MyArray(): m_size(def_size)
      {
         m_data.reset(new T[m_size]);
      }

      template <class T>
      MyArray<T>::MyArray(size_t size): m_size(size)
      {
         m_data.reset(new T[m_size]);
      }

      template <class T>
      MyArray<T>::MyArray(const MyArray<T>& a)
      {
         m_size = a.size();
         m_data.reset(new T[m_size]);
         //copy elements
         for ( size_t i = 0; i < m_size; ++i ) m_data.get()[i] = a[i];
      }

      template <class T>
      MyArray<T>::MyArray(const size_t size, const T& value) :m_size(size)
      {
         m_data.reset(new T[size]);
         for ( size_t i = 0; i < m_size; ++i ) m_data.get()[i] = value;
      }

      template <class T>
      size_t MyArray<T>::size() const
      {
         return m_size;
      };

      template <class T>
      MyArray<T>::~MyArray()
      {
      };

      template <class T>
      MyArray<T>::MyArray(std::initializer_list<T> l)
      {
         m_size = l.size();
         m_data.reset(new T[m_size]);
         size_t ii = 0;
         for ( auto i = l.begin(); i != l.end(); ++i, ++ii ) m_data.get()[ii] = *i;
      }

      template <class T>
      MyArray<T>& MyArray<T>::operator = (const MyArray<T>& a)
      {

         if ( &a == this ) return *this;
         m_size = a.size();
         m_data.reset(new T[m_size]);
         // copy elements
         for ( size_t i = 0; i < m_size; ++i ) m_data.get()[i] = a[i];
         return *this;
      };

      //set the element
      template <class T>
      T& MyArray<T>::operator[] (size_t index)
      {
         if ( index >= m_size || index < 0)
            throw OutOfBounds(index);
         else
            return m_data.get()[index];
      };

      //get the element
      template <class T>
      const T& MyArray<T>::operator[] (size_t index) const
      {
         if ( index >= m_size || index < 0 )
            throw OutOfBounds(index);
         else
            return m_data.get()[index];
      };
   }
}

#endif