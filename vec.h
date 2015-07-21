/************************************************************
    Author: Charlie Murphy
    Email:  tm507211@ohio.edu

    Date:   July 20, 2015

    Description: Implementation of vector classes
************************************************************/
namespace CM{

template <class T>
class Vector2{
 public:
  T x;
  T y;

  Vector2(const T& s = T());
  Vector2(const T& x, const T& y);
  Vector2(const Vector2<T>& v);

  bool operator == (const Vector2<T>& v) const;
  bool operator != (const Vector2<T>& v) const;

  T& operator [] (int i);
  const T operator [] (int i) const;

  Vector2<T> operator - () const;
  Vector2<T> operator + (const Vector2<T>& v) const;
  Vector2<T> operator - (const Vector2<T>& v) const;
  Vector2<T> operator * (const T& s) const;
  Vector2<T> operator * (const Vector2<T>& v) const;
  Vector2<T> operator / (const T& s) const;

  Vector2<T>& operator += (const Vector2<T>& v);
  Vector2<T>& operator -= (const Vector2<T>& v);
  Vector2<T>& operator *= (const T& s);
  Vector2<T>& operator *= (const Vector2<T>& v);
  Vector2<T>& operator /= (const T& s);

  friend std::ostream& operator << (std::ostream& outs, const Vector2<T>& v);
  friend std::istream& operator << (std::istream& outs, const Vector2<T>& v);

  operator const T* () const;
  operator T* ();

  T dot(const Vector2<T>& v) const;
  T length();
  Vector2<T>& normalize();
  Vector2<T> unit() const;
  Vector2<T> cross() const;
};

}

#include "vector.template"
