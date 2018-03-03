#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
namespace Luca
{
  namespace CAD{
    class shape
    {
      int m_id;
    public:
      shape();
      virtual ~shape();
      shape( const shape& s );
      shape& operator = ( const shape& s );

      int ID() const;
      virtual std::string ToString() const;
      virtual void Draw() = 0;
    };
  }
}
#endif