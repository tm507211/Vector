/************************************************************
    Author: Charlie Murphy
    Email:  tm507211@ohio.edu

    Date:   July 20, 2015

    Description: Implementation of vector classes
************************************************************/
#include <iostream>
#include <cmath>

namespace CM {


/***************************************************************************************
  Vector2  -- 2-D vector class
***************************************************************************************/
template <class T>
class Vector2{
  public:
   T x;
   T y;

  Vector2(const T& s = T()):x(s), y(s){}
  Vector2(const T& x, const T& y):x(x),y(y){}
  Vector2(const Vector2<T>& v):x(v.x),y(v.y){}

  bool operator == (const Vector2<T>& v) const{
    return x == v.x && y == v.y;
  }
  bool operator != (const Vector2<T>& v) const{
    return x != v.x || y != v.y;
  }

  /**********************************************
    Indexing operator
  **********************************************/
  T& operator [] (int i){
    return *(&x + i);
  }
  const T operator [] (int i) const{
    return *(&x + i);
  }

  /*********************************************
    Non modifying math operators
  *********************************************/
  Vector2<T> operator - () const{
    return Vector2<T>(-x, -y);
  }
  Vector2<T> operator + (const Vector2<T>& v) const{
    return Vector2<T>(x + v.x, y + v.y);
  }
  Vector2<T> operator - (const Vector2<T>& v) const{
    return Vector2<T>(x - v.x, y - v.y);
  }
  Vector2<T> operator * (const T& s) const{
    return Vector2<T>(x * s, y * s);
  }
  Vector2<T> operator * (const Vector2<T>& v) const{
    return Vector2<T>(x * v.x, y * v.y);
  }
  Vector2<T> operator / (const T& s) const{
    return Vector2<T> (x / s, y / s);
  }

  /*******************************************
    Modifying Math Operators
  *******************************************/
  Vector2<T>& operator += (const Vector2<T>& v){
    x += v.x;
    y += v.y;
    return *this;
  }
  Vector2<T>& operator -= (const Vector2<T>& v){
    x -= v.x;
    y -= v.y;
    return *this;
  }
  Vector2<T>& operator *= (const T& s){
    x *= s;
    y *= s;
    return *this;
  }
  Vector2<T>& operator *= (const Vector2<T>& v){
    x *= v.x;
    y *= v.y;
    return *this;
  }
  Vector2<T>& operator /= (const T& s){
    x /= s;
    y /= s;
    return *this;
  }

  /*******************************************
    Cast to T* (lets you use vec2 as T array)
  *******************************************/
  operator const T* () const{
    return static_cast<T*>(&x);
  }
  operator T* (){
    return static_cast<T*>(&x);
  }

  /********************************************
    Useful Vector Operations
  ********************************************/
  T length() const {
    return std::sqrt(x * x + y * y);
  }
  T lengthSq() const {
    return x * x + y * y;
  }
  Vector2<T>& normalize(){
    T length = length();
    x /= length;
    y /= length;
    return *this;
  }
  Vector2<T> unit() const{
    T length = length();
    return Vector2<T>(x / length, y / length);
  }
  T dot(const Vector2<T>& v) const{
    return x * v.x + y * v.y;
  }
  T cross(const Vector2<T>& v) const{ // 3-D cross product with z assumed 0
    return x * v.y +  v.x * y;        // return magnitude of resulting vector
  }
};

template <class T>
T dot(const Vector2<T>& v1, const Vector2<T>& v2){
  return v1.dot(v2);
}
template <class T>
T cross(const Vector2<T>& v1, const Vector2<T>& v2){
  return v1.cross(v2);
}

template <class T>
std::ostream& operator << (std::ostream& outs, const Vector2<T>& v){
 outs << "<" << v.x << ", " << v.y << ">";
 return outs;
}

template <class T>
std::istream& operator << (std::istream& ins, const Vector2<T>& v){
  ins >> v.x >> v.y;
}

/*********************************************************************************
 Vector3 -- 3D vector
*********************************************************************************/

}
