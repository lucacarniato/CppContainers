#ifndef STACK_EXCEPTION_HPP
#define STACK_EXCEPTION_HPP

#include <iostream>
#include <sstream>

using std::string;
using std::stringstream;
using std::endl;

namespace Luca
{
  namespace Containers{
    class StackException{
    public:
      virtual string GetMessage() = 0;
    };

    class StackFullException :public StackException{
      int m_index;
    public:
      StackFullException( int i ) : m_index( i ) {};
      string GetMessage()
      {
        stringstream mess;
        mess << "The stack is full, all available " << m_index << "  elements have been written " << endl;
        return mess.str();
      }
    };

    class StackEmptyException :public StackException{
      int m_index;
    public:
      StackEmptyException() : m_index() {};
      string GetMessage()
      {
        stringstream mess;
        mess << "The stack is empty " << endl;
        return mess.str();
      }
    };
  }
}

#endif