#ifndef LINE_HPP
#define LINE_HPP
#include "shape.hpp"
#include "point.hpp"

namespace Luca
{
   namespace CAD
   {
      class line : public shape
      {
         point m_start;
         point m_end;
      public:
         line();
         line(const point& start, const point& end);
         double length() const;
         std::string ToString() const;
         void Draw();
      };
   }
}
#endif