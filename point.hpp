#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include "shape.hpp"

using  namespace std;

namespace Luca
{
  namespace CAD{
    class point : public shape
    {
      double m_x;
      double m_y;
    public:
      point();
      point( const double x, const double y );
      point( const point& p );							
      point& operator = (const point& p);
      ~point();

      double X() const;
      double Y() const;
      void X( const double x );
      void Y( const double y );

      double distance( const point p = point( 0, 0 ) ) const;
      std::string ToString() const;
      void Draw();
    };
  }
}
#endif