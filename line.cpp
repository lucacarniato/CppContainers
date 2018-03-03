#include "line.hpp"
#include <sstream>
#include <string>
#include <iostream>

namespace Luca
{
   namespace CAD
   {
      line::line() :shape(), m_start(), m_end() {}

      line::line(const point& start, const point& end) : m_start(start), m_end(end) {}

      double line::length() const
      {
         return  m_start.distance(m_end);
      }

      std::string line::ToString() const
      {
         std::stringstream storeString;
         storeString << "Line from " << m_start.ToString() << " to " << m_end.ToString() << " and " << shape::ToString() << endl;
         return storeString.str();
      }

      void line::Draw()
      {
         std::cout << "Drawing line" << endl;
      }
   }
}

