#ifndef ARRAY_EXCEPTION_HPP
#define ARRAY_EXCEPTION_HPP

#include <iostream>
#include <sstream>

using std::string;
using std::stringstream;
using std::endl;

namespace Luca
{
   namespace Containers
   {
      class ArrayException{
      public:
         virtual string GetMessage() = 0;
      };

      class OutOfBounds : public ArrayException
      {
         int m_index;
      public:
         OutOfBounds(int i) : m_index(i) {};
         string GetMessage()
         {
            stringstream mess;
            mess << "I am out of index, because the index is " << m_index << endl;
            return mess.str();
         }
      };

      class notEqualSize : public ArrayException
      {
      public:
         notEqualSize() {};
         string GetMessage()
         {
            stringstream mess;
            mess << "The sizes of the arrays are not equal" << endl;
            return mess.str();
         }
      };
   }
}

#endif