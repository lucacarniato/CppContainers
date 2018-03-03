#include "shape.hpp"
#include "point.hpp"
#include "line.hpp"
#include "ArrayException.hpp"
#include "StackException.hpp"
#include "MyArray.hpp"
#include "PointArray.hpp"
#include "NumericArray.hpp"
#include "Stack.hpp"
#include <iostream>

using namespace Luca;

//default size for doubles
size_t Containers::MyArray<double>::def_size = 30;
//default size for the others
template <class T>
size_t Containers::MyArray<T>::def_size = 10;

int main()
{
   try
   {

      Containers::NumericArray<int>       intArray1{ 1, 2, 3 };
      Containers::NumericArray<double>    doubleArray1{ 0.0, 10.0, 20.0, 30.0 };
      Containers::NumericArray<int>       intArray2(intArray1);
      Containers::NumericArray<double>    doubleArray2{ 0.0, 1.0, 0.0, 1.0};
      Containers::MyArray<int>            intArray3{1,2};
      double prod = doubleArray1 % doubleArray2;

      std::cout << "intArray1.size() " << intArray1.size() << " doubleArray2.size() " << doubleArray1.size() << " intArray2.size() "<< intArray2.size() << std::endl;
      std::cout << "prod "<< prod << std::endl;

      Containers::Stack<char> doubleStack1;
      Containers::Stack<char> doubleStack2;
      doubleStack1 = doubleStack2;
      doubleStack1.Push('L');
      doubleStack1.Pop();

      Containers::MyArray<CAD::shape*> shapeArray1{new CAD::point(10,10), new CAD::point(30,30), new CAD::line()};

      for ( size_t i = 0; i < shapeArray1.size(); ++i )
      {
         CAD::point* point = dynamic_cast<CAD::point*>(shapeArray1[i]);
         if ( point ) std::cout << "the distance is "<< point->distance() << std::endl;
         delete shapeArray1[i];
      }  
   }
   catch ( Containers::ArrayException & e )
   {
      std::cout << e.GetMessage() << std::endl;
      return -1;
   }
   catch ( Containers::StackException & e )
   {
      std::cout << e.GetMessage() << std::endl;
      return -1;
   }
   catch ( ... )
   {
      std::cout << "Unknown exception" << std::endl;
   }

   getchar();
   return 0;
}