#ifndef _Queue_
#define _Queue_

#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class TQueue
{
protected:
  int length;
  T* queue;
  int front;
  int back;
  int count;
public:
  TQueue(int size = 0);
  TQueue(TQueue<T>& q);
  ~TQueue();

  TQueue<T>& operator=(const TQueue<T>& q);

  void Push(T n);
  void Pop();
  T GetBack();
  T GetFront();
  bool IsEmpty();
  bool IsFull();
  int Length();

  template <class T1>
  friend ostream& operator<<(ostream& ostr, const TQueue<T1>& Q);
  template <class T1>
  friend istream& operator>>(istream& istr, TQueue<T1>& Q);

  // доп задачи

  T GetMaxElem();
  T GetMinElem();
  template <class T1>
  friend ofstream& operator<<(ofstream& ofstr, const TQueue<T1>& Q);
};

template<class T>
inline TQueue<T>::TQueue(int size)
{
  if (size < 0)
    throw exception();
  this->length = size;
  this->queue = new T[size];
  for (int i = 0; i < size; i++)
    this->queue[i] = 0;
  this->front = 0;
  this->back = -1;
  this->count = 0;
}

template<class T>
inline TQueue<T>::TQueue(TQueue<T>& q)
{
  this->length = q.length;
  this->front = q.front;
  this->back = q.back;
  this->count = q.count;
  this->queue = new T[q.length];
  for (int i = 0; i < q.length; i++)
    this->queue[i] = q.queue[i];
}

template<class T>
inline TQueue<T>::~TQueue()
{
  this->length = 0;
  if (this->queue != 0)
    delete[] this->queue;
  this->queue = 0;
}

template<class T>
inline TQueue<T>& TQueue<T>::operator=(const TQueue<T>& q)
{
  if (this == &q)
    return *this;
  if (this->length != q.length)
  {
    this->length = q.length;
    delete[] this->queue;
    this->queue = new T[q.length];
  }
  this->front = q.front;
  this->back = q.back;
  this->count = q.count;
  for (int i = 0; i < q.length; i++)
    this->queue[i] = q.queue[i];
  return *this;
}

template<class T>
inline void TQueue<T>::Push(T n)
{
  if (this->count >= this->length)
    throw exception();
  this->back++;
  if (this->back >= = this->length)
    this->back -= this->length;
  this->queue[this->back] = n;
  this->count++;
}

template<class T>
inline void TQueue<T>::Pop()
{
  if (this->front >= 0)
    this->front--;
}

template<class T>
inline T TQueue<T>::Get()
{
  if (this->front == -1)
    throw exception();
  return this->queue[this->front];
}

template<class T>
inline bool TQueue<T>::IsEmpty()
{
  if (this->front == this->length - 1)
    return false;
  return true;
}

template<class T>
inline bool TQueue<T>::IsFull()
{
  return !IsEmpty();
}

template<class T>
inline int TQueue<T>::Length()
{
  return this->length;
}

template <class T1>
ostream& operator<<(ostream& ostr, const TQueue<T1>& S)
{
  for (int i = 0; i <= S.front; i++)
    ostr << S.queue[i];
  return ostr;
}

template <class T1>
istream& operator>>(istream& istr, TQueue<T1>& S)
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

// доп задачи

template<class T>
inline T TQueue<T>::GetMaxElem()
{
  if (IsEmpty())
    throw exception();
  int ind = 0;
  for (int i = 1; i <= this->front; i++)
    if (this->queue[i] > this->queue[ind])
      ind = i;
  return this->queue[ind];
}

template<class T>
inline T TQueue<T>::GetMinElem()
{
  if (IsEmpty())
    throw exception();
  int ind = 0;
  for (int i = 1; i <= this->front; i++)
    if (this->queue[i] < this->queue[ind])
      ind = i;
  return this->queue[ind];
}

template<class T1>
inline ofstream& operator<<(ofstream& ofstr, const TQueue<T1>& S)
{
  for (int i = 0; i <= S.front; i++)
    ofstr << S.queue[i];
  return ofstr;
}

#endif

