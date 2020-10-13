#pragma once
#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;
template <class T>
class Vector
{
protected:
  int length;
  T* x;
public:
  
  Vector();
  Vector(int _size);
  Vector(int rowsCount, T* _v);
  Vector(int rowsCount, T _v);
  Vector(Vector<T>& _v);
  ~Vector();

  Vector<T> operator +(Vector<T>& _v);
  Vector<T> operator -(Vector<T>& _v);
  T operator *(Vector<T>& _v);
  Vector<T> operator /(Vector<T>& _v);
  Vector<T>& operator =(Vector<T>& _v);
  T& operator[] (const int index);

  Vector<T>& operator ++();
  Vector<T>& operator --();
  Vector<T>& operator +=(Vector<T>& _v);
  Vector<T>& operator -=(Vector<T>& _v);
  bool operator == ( Vector<T>& other);
  template <class T1>
  friend ostream& operator<< (ostream& ostr, const Vector<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, Vector<T1> &A);

  int Length();
};

template <class T1>
ostream& operator<< (ostream& ostr, const Vector<T1> &A) {
  for (int i = 0; i < A.length; i++) {
    ostr << A.x[i] << endl;
  }
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, Vector<T1> &A) {
  for (int i = 0; i < A.length; i++) {
    istr >> A.x[i];
  }
  return istr;
}

#define MIN(a,b)(a>b?b:a)
#define MAX(a,b)(a>b?a:b)

template <class T>
Vector<T>::Vector()
{
  length = 0;
  x = 0;
}
template <class T>
Vector<T>::Vector(int _size)
{
    if (_size > MAX_VECTOR_SIZE)
        throw logic_error ("parametr_is_too_much");
  length = _size;
  x = new T [length];
  for(int i=0; i<length;i++)
  x[i] = 0;
}
template <class T>
Vector<T>::Vector(int rowsCount, T* _v)
{
    if (rowsCount < 0)
        throw logic_error("invalid_length_in_constructor");
  length = rowsCount;
  x = new T [length];
  for (int i = 0; i < length; i++)
    x[i] = _v[i];
}
template <class T>
Vector<T>::Vector(int rowsCount, T _v)
{
    if (rowsCount < 0)
        throw logic_error("invalid_length_in_constructor");
  length = rowsCount;
  x = new T [length];
  for (int i = 0; i < length; i++)
    x[i] = _v;
}
template <class T>
Vector<T>::Vector(Vector<T>& _v)
{
  length = _v.length;
  x = new T [length];
  for (int i = 0; i < length;i = i + 1)
    x[i] = _v.x[i];
}
template <class T>
Vector<T>::~Vector()
{
    if (this != 0)
    {
        length = 0;

        delete[] x;
        x = 0;
    }
}
template <class T>
Vector<T> Vector<T>::operator +(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] + _v.x[i];
  }
  return res;
}
template <class T>
Vector<T> Vector<T>::operator -(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] - _v.x[i];
  }
  return res;
}
template <class T>
T Vector<T>::operator *(Vector<T>& _v)
{
    if (length != _v.Length())
        throw (-1);
  T res=0;
  for (int i = 0; i < _v.length; i++)
  {
    res= res+ x[i] * _v.x[i];
  }
  return res;
}
template <class T>
Vector<T> Vector<T>::operator /(Vector<T>& _v)

{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T [res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] / _v.x[i];
  }
  return res;
}
template <class T>
Vector<T>& Vector<T>::operator =(Vector<T>& _v)
{
  if (this == &_v)
    return *this;

  length = _v.length;
  x = new T [length];
  for (int i = 0; i < length; i++)
    x[i] = _v.x[i];
  return *this;
}
template <class T>
T& Vector<T>::operator[] (const int index)
{

  if ((index >= 0) && (index < length))
    return x[index];
  else
      throw logic_error("invalid_index");
}

template <class T>
Vector<T>& Vector<T>::operator ++()
{
  for (int i = 0; i < length; i++)
    x[i]++;
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator --()
{
  for (int i = 0; i < length; i++)
    x[i]--;
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator +=(Vector<T>& _v)
{
  length = MIN(length, _v.length);
  for (int i = 0; i < length; i++)
  {
    x[i] += _v.x[i];
  }
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator -=(Vector<T>& _v)
{
  length = MIN(length, _v.length);
  for (int i = 0; i < length; i++)
  {
    x[i] -= _v.x[i];
  }
  return *this;
}
template<class T>
inline bool Vector<T>::operator==( Vector<T>& _v) 
{
    int f;
    if (length!=_v.Length())
    return false;
    for (int i = 0; i < _v.Length(); i++)
    {
        f = (x[i] == _v.x[i]);
            if (f==0)
                return false;
    }
    return true;
}
template <class T>
int Vector<T>::Length()
{
  return length;
}



template <class T>
class Matrix :public Vector<Vector<T>>
{
public:
    Matrix(int _size = 0);
    Matrix<T>(const Matrix<T>& A);
    bool operator == (Matrix<T> & A);
    Matrix<T>& operator = (const Matrix<T> & A);
    Matrix<T>& operator + (const Matrix<T> & A);
    Matrix<T>& operator - (const Matrix<T> & A);
    Vector<T>& operator[](int n);
    
    template<class T>
    friend istream& operator>>(istream& in, Matrix<T>& A);
    template<class T>
    friend ostream& operator<<(ostream& out, const Matrix<T>& A);
};

template<class T>
istream& operator>>(istream& in, Matrix<T>& A)
{
    for (int i = 0; i < A.length; i++)
        in >> A.vec[i];
    return in;
}
template<class T>
ostream& operator<<(ostream& out, const Matrix<T>& A)
{
    for (int i = 0; i < A.length; i++)
        out << A.vec[i] << endl;
    return out;
}
template<class T>
inline Matrix<T>::Matrix(int _size)
{
    if ((_size < 0) || (_size > MAX_MATRIX_SIZE))
        throw logic_error("invalid_length_in_constructor");
    x = new Vector<T>[_size];
    for (int i = 0; i < _size; i++)
    {
        Vector<T> v(i + 1);
        x[i] = v;
    }
    length = _size;
}
template<class T>
inline Matrix<T>::Matrix(const Matrix<T>& A)
{
    (*this).length = A.length;
    x = new Vector<T>[(*this).length];
    for (int i = 0; i < (*this).length; i++)
        (*this).x[i] = A.x[i];

}
template<class T>
inline bool Matrix<T>::operator==(Matrix<T>& A)
{
    if ((*this).length != A.length)
        return false;
    for (int i = 0; i < A.length; i++)
     { 
        if ((*this).x[i] == A.x[i])
          continue;
        return false;
     }
    return true;
}
template<class T>
inline Matrix<T>& Matrix<T>::operator=(const Matrix<T>& A)
{
    if (this == &A)
        return(*this);
    if ((*this).length != A.length)
    {
        delete[]x;
        (*this).length = A.length;
        x = new Vector<T>[(*this).length];
    }
    for (int i = 0; i < (*this).length; i++)
        x[i] = A.x[i];
}
template<class T>
inline Matrix<T>& Matrix<T>::operator+(const Matrix<T>& A)
{
    if ((*this).length != A.length)
        throw logic_error("matrix_sizes_must_be_similar");
    Matrix<T> temp(*this);
    for (int i = 0; i < (*this).length; i++)
        temp.x[i] = temp.x[i] + A.x[i];
    
    (*this) = temp;
     return (*this);
}
template<class T>
inline Matrix<T>& Matrix<T>::operator-(const Matrix<T>& A)
{
    if((*this).length!=A.length)
        throw logic_error("matrix_sizes_must_be_similar");
    Matrix<T> temp(*this);
    for (int i = 0; i < (*this).length; i++)
        temp.x[i] = temp.x[i] - A.x[i];
    return temp;

}

template<class T>
inline Vector<T>& Matrix<T>::operator[](int n)
{
    if ((n>(*this).length)||(n<0))
        throw logic_error("matrix_sizes_must_be_similar");
    return(x[n]);
}
#endif