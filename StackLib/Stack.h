#ifndef _Stack_
#define _Stack_

#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class TStack
{
protected:
  int length;
  T* stack;
  int front;
public:
  TStack(int size = 0);
  TStack(TStack<T>& s);
  ~TStack();

  TStack<T>& operator=(const TStack<T>& s);

  void Push(T n);
  void Pop();
  T Get();
  bool IsEmpty();
  bool IsFull();
  int Length();

  template <class T1>
  friend ostream& operator<<(ostream& ostr, const TStack<T1>& S);
  template <class T1>
  friend istream& operator>>(istream& istr, TStack<T1>& S);

  // ��� ������

  T GetMaxElem();
  T GetMinElem();
  template <class T1>
  friend ofstream& operator<<(ofstream& ofstr, const TStack<T1>& S);
};

template<class T>
inline TStack<T>::TStack(int size)
{
  if (size < 0)
    throw exception();
  this->length = size;
  this->stack = new T[size];
  for (int i = 0; i < size; i++)
    this->stack[i] = 0;
  this->front = -1;
}

template<class T>
inline TStack<T>::TStack(TStack<T>& s)
{
  this->length = s.length;
  this->front = s.front;
  this->stack = new T[s.length];
  for (int i = 0; i < s.length; i++)
    this->stack[i] = s.stack[i];
}

template<class T>
inline TStack<T>::~TStack()
{
  this->length = 0;
  if (this->stack != 0)
    delete[] this->stack;
  this->stack = 0;
}

template<class T>
inline TStack<T>& TStack<T>::operator=(const TStack<T>& s)
{
  if (this == &s)
    return *this;
  if (this->length != s.length)
  {
    this->length = s.length;
    delete[] this->stack;
    this->stack = new T[s.length];
  }
  this->front = s.front;
  for (int i = 0; i < s.length; i++)
    this->stack[i] = s.stack[i];
  return *this;
}

template<class T>
inline void TStack<T>::Push(T n)
{
  if (this->front + 1 >= this->length)
    throw exception();
  this->stack[++this->front] = n;
}

template<class T>
inline void TStack<T>::Pop()
{
  if (this->front >= 0)
    this->front--;
}

template<class T>
inline T TStack<T>::Get()
{
  if (this->front == -1)
    throw exception();
  return this->stack[this->front];
}

template<class T>
inline bool TStack<T>::IsEmpty()
{
  if (this->front == this->length - 1)
    return false;
  return true;
}

template<class T>
inline bool TStack<T>::IsFull()
{
  return !IsEmpty();
}

template<class T>
inline int TStack<T>::Length()
{
  return this->length;
}

template <class T1>
ostream& operator<<(ostream& ostr, const TStack<T1>& S)
{
  for (int i = 0; i <= S.front; i++)
    ostr << S.stack[i];
  return ostr;
}

template <class T1>
istream& operator>>(istream& istr, TStack<T1>& S)
{
  int n;
  T1 t;
  istr >> n;
  for (int i = 0; i < n; i++)
  {
    istr >> t;
    S.Push(t);
  }
  return istr;
}

// ��� ������

template<class T>
inline T TStack<T>::GetMaxElem()
{
  if (IsEmpty())
    throw exception();
  int ind = 0;
  for (int i = 1; i <= this->front; i++)
    if (this->stack[i] > this->stack[ind])
      ind = i;
  return this->stack[ind];
}

template<class T>
inline T TStack<T>::GetMinElem()
{
  if (IsEmpty())
    throw exception();
  int ind = 0;
  for (int i = 1; i <= this->front; i++)
    if (this->stack[i] < this->stack[ind])
      ind = i;
  return this->stack[ind];
}

template<class T1>
inline ofstream& operator<<(ofstream& ofstr, const TStack<T1>& S)
{
  for (int i = 0; i <= S.front; i++)
    ofstr << S.stack[i];
  return ofstr;
}

#endif

