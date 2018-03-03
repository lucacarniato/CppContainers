#include "point.hpp"
#include "shape.hpp"
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>

namespace Luca
{
  namespace CAD{
    // the default constructor is used for the base class
    point::point() : shape(), m_x( 0 ), m_y( 0 )
    {
    }

    point::point( const double x, const double y ) : m_x( x ), m_y( y )
    {
    }

    point::~point()
    {
    }

    //base copy constructor is used for base class members
    point::point( const point& p ) :shape( p ){
      m_x = p.X();
      m_y = p.Y();
    }

    point& point::operator = ( const point& p ){
      if ( &p != this )
      {
        shape::operator=( p );
        m_x = p.m_x;
        m_y = p.m_y;
      }
      return *this;
    }

    double point::X() const{
      return m_x;
    }

    double point::Y() const {
      return m_y;
    }

    void point::X( const double x ){
      m_x = x;
    }

    void point::Y( const double y ){
      m_y = y;
    }

    double point::distance( const point p ) const {
      return ( std::sqrt( pow( m_x - p.X(), 2 ) + pow( m_y - p.Y(), 2 ) ) );
    }

    std::string point::ToString() const
    {
      std::stringstream storeString;
      storeString << "Point(" << m_x << ", " << m_y << ") and with " << shape::ToString();
      return storeString.str();
    }

    void point::Draw()
    {
      std::cout << "Drawing point" << endl;
    }
  }
}