#ifndef POINTARRAY_HPP
#define POINTARRAY_HPP

#include "MyArray.hpp"
#include "point.hpp"

//concrete inheritance

namespace Luca
{
  namespace CAD{

    class PointArray : public Containers::MyArray<point>
    {
    public:
      //constructor, destructor and assignment operator
      PointArray();
      PointArray( int dim );
      ~PointArray();
      PointArray& operator = ( const PointArray& a );
      PointArray(const PointArray& a);
      double length();
    };

    PointArray::PointArray() : MyArray<point>()
    {
    }

    PointArray::PointArray( int dim ) : MyArray<point>( dim )
    {
    }

    PointArray::~PointArray()
    {
    }

    PointArray& PointArray::operator = (const PointArray& a)
    {
       if ( &a == this ) return *this;
       MyArray<point>::operator=(a);
       return *this;
    }

    PointArray::PointArray(const PointArray& a): MyArray<point>(a)
    {
    }

    double PointArray::length()
    {
      double totLength = 0.0;
      for ( size_t i = 0; i < m_size - 1; ++i ) totLength += m_data.get()[i].distance(m_data.get()[i+1]);
      return totLength;
    }
  }
}
#endif