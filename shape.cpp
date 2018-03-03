#include "shape.hpp"
#include "stdlib.h"
#include <sstream>
#include <iostream>

using namespace std;

namespace Luca
{
  namespace CAD{

    shape::shape() : m_id( rand() ){};

    shape::shape( const shape& s ){
      m_id = s.ID();
    };

    shape& shape::operator = ( const shape& s ){
      if ( &s != this ) m_id = s.ID();
      return *this;
    };

    int shape::ID() const{ return m_id; };

    std::string shape::ToString() const
    {
      std::stringstream storeString;
      storeString << " the shape ID is:" << m_id;
      return storeString.str();
    };

    shape::~shape()
    {
    };
  }
}