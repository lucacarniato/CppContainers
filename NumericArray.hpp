#ifndef NUMERICARRAY_HPP
#define NUMERICARRAY_HPP

#include "MyArray.hpp"
#include "ArrayException.hpp"

namespace Luca
{
   namespace Containers{
      template <class Numeric>
      class NumericArray : public MyArray < Numeric >
      {
      public:
         //constructor, destructor and assignment operator
         NumericArray();
         NumericArray(const NumericArray<Numeric>& a);
         ~NumericArray();
         NumericArray(int size, Numeric value);
         NumericArray(std::initializer_list<Numeric> l);

         NumericArray<Numeric>& operator = (const NumericArray<Numeric>& a);
         NumericArray<Numeric>& operator * (Numeric factor);
         NumericArray<Numeric>& operator + (const NumericArray<Numeric>& a);
         Numeric operator % (const NumericArray<Numeric>& a) const;
      };

      template <class Numeric>
      NumericArray<Numeric>::NumericArray() : MyArray<Numeric>()
      {
      }

      template <class Numeric>
      NumericArray<Numeric>::NumericArray(const NumericArray<Numeric>& a) : MyArray<Numeric>(a)
      {
      }

      template <class Numeric>
      NumericArray<Numeric>::NumericArray(int size, Numeric value) : MyArray<Numeric>(size, value)
      {
      }

      template <class Numeric>
      NumericArray<Numeric>::NumericArray(std::initializer_list<Numeric> l) : MyArray<Numeric>(l)
      {
      }

      template <class Numeric>
      NumericArray<Numeric>::~NumericArray()
      {
      }

      template <class Numeric>
      NumericArray<Numeric>& NumericArray<Numeric>::operator = (const NumericArray<Numeric>& a)
      {
         if ( &a == this ) return *this;
         //copy the base class part
         MyArray<Numeric>::operator=(a);
         return *this;
      }

      template <class Numeric>
      NumericArray<Numeric>&  NumericArray<Numeric>::operator * (Numeric factor)
      {
         for ( size_t i = 0; i < m_size; ++i ) m_data.get()[i] * factor;
         //return object
         return *this;
      }

      template <class Numeric>
      NumericArray<Numeric>&  NumericArray<Numeric>::operator + (const NumericArray<Numeric>& a)
      {
         if ( m_size != a.m_size )
         {
            throw notEqualSize();
         }
         else
            for ( size_t i = 0; i < m_size; ++i ) m_data.get()[i] = m_data.get()[i] + a.m_data.get()[i];
         //return object
         return *this;
      }

      //sum the elementwise products
      template <class Numeric>
      Numeric  NumericArray<Numeric>::operator % (const NumericArray<Numeric>& a) const
      {
         Numeric sum(0);
         if ( m_size != a.m_size )
            throw notEqualSize();
         else
            for ( size_t i = 0; i < m_size; ++i )
            {
               sum += m_data.get()[i] * a.m_data.get()[i];
            }
         return sum;
      }
   }
}

#endif