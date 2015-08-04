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
    T length = this->length();
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
std::istream& operator >> (std::istream& ins, Vector2<T>& v){
 ins >> v.x >> v.y;
 return ins;
}

/*********************************************************************************
 Vector3 -- 3D vector
*********************************************************************************/
template <class T>
class Vector3{
 public:
  T x;
  T y;
  T z;

  Vector3(const T& s = T()):x(s), y(s), z(s){}
  Vector3(const T& x, const T& y, const T& z):x(x), y(y), z(z){}
  Vector3(const Vector3<T>& v):x(v.x), y(v.y), z(v.z){}

  bool operator == (const Vector3<T>& v) const{
    return x == v.x && y == v.y && z == v.z;
  }
  bool operator != (const Vector3<T>& v) const{
    return x != v.x || y != v.y || z != v.z;
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
  Vector3<T> operator - () const{
    return Vector3<T>(-x, -y, -z);
  }
  Vector3<T> operator + (const Vector3<T>& v) const{
    return Vector3<T>(x + v.x, y + v.y, z + v.z);
  }
  Vector3<T> operator - (const Vector3<T>& v) const{
    return Vector3<T>(x - v.x, y - v.y, z - v.z);
  }
  Vector3<T> operator * (const T& s) const{
    return Vector3<T>(x * s, y * s, z * s);
  }
  Vector3<T> operator * (const Vector3<T>& v) const{
    return Vector3<T>(x * v.x, y * v.y, z * v.z);
  }
  Vector3<T> operator / (const T& s) const{
    return Vector3<T> (x / s, y / s, z / s);
  }

  /*******************************************
    Modifying Math Operators
  *******************************************/
  Vector3<T>& operator += (const Vector3<T>& v){
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }
  Vector3<T>& operator -= (const Vector3<T>& v){
    x -= v.x;
    y -= v.y;
    y -= v.z;
    return *this;
  }
  Vector3<T>& operator *= (const T& s){
    x *= s;
    y *= s;
    z *= s;
    return *this;
  }
  Vector3<T>& operator *= (const Vector3<T>& v){
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
  }
  Vector3<T>& operator /= (const T& s){
    x /= s;
    y /= s;
    z /= s;
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
    return std::sqrt(x * x + y * y + z * z);
  }
  T lengthSq() const {
    return x * x + y * y + z * z;
  }
  Vector3<T>& normalize(){
    T length = this->length();
    x /= length;
    y /= length;
    z /= length;
    return *this;
  }
  Vector3<T> unit() const{
    T length = length();
    return Vector3<T>(x / length, y / length, z / length);
  }
  T dot(const Vector3<T>& v) const{
    return x * v.x + y * v.y + z * v.z;
  }
 Vector3<T> cross(const Vector3<T>& v){ /* NOTE this function modifies the vector unlike 2D and non-member versions */
    T x_(x), y_(y), z_(z);
    x = y_*v.z - z_*v.y;
    y = z_*v.x - x_*v.z;
    z = x_*v.y - y_*v.x;
    return *this;
  }
};

template <class T>
T dot(const Vector3<T>& v1, const Vector3<T>& v2){
 return v1.dot(v2);
}
template <class T>
Vector3<T> cross(const Vector3<T>& v1, const Vector3<T>& v2){
 return Vector3<T>(v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y-v1.y*v2.x);
}

template <class T>
std::ostream& operator << (std::ostream& outs, const Vector3<T>& v){
 outs << "<" << v.x << ", " << v.y << ", " << v.z << ">";
 return outs;
}
template <class T>
std::istream& operator >> (std::istream& ins, Vector3<T>& v){
 ins >> v.x >> v.y >> v.z;
 return ins;
}

} // end CM namespace
