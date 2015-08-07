/******************************************************************************************
    Author: Charlie Murphy
    Email:  tm507211@ohio.edu

    Date:   Augost 7, 2015

    Description: Defines point class.
******************************************************************************************/
#include "vector.h"

namespace CM{

template <class T>
class Point3D{
 public:
   T x;
   T y;
   T z;
   T w;

   Point3D(const T& s = T()):x(s), y(s), z(s), w(s){}
   Point3D(const T& x, const T& y, const T& z, const T& w):x(x), y(y), z(z), w(w){}
   Point3D(const Point3D<T>& p):x(p.x), y(p.y), z(p.z), w(p.w){}
   Point3D(const Point3D<T>& p, const Vector3<T>& v):x(p.x+v.x), y(p.y+v.y), z(p.z+v.z), w(p.w){}
};

}
