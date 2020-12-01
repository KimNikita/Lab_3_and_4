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
  TQueue(const TQueue<T>& q);
  ~TQueue();

  TQueue<T>& operator=(const TQueue<T>& q);

  void Push(T n);
  void Pop();
  T Get();
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
  void WriteToFile(string name);
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
inline TQueue<T>::TQueue(const TQueue<T>& q)
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
  if (this->back >= this->length)
    this->back -= this->length;
  this->queue[this->back] = n;
  this->count++;
}

template<class T>
inline void TQueue<T>::Pop()
{
  if (this->count > 0)
  {
    this->front++;
    if (this->front >= this->length)
      this->front -= this->length;
    this->count--;
  }
}

template<class T>
inline T TQueue<T>::Get()
{
  if (this->count <= 0)
    throw exception();
  return this->queue[this->front];
}

template<class T>
inline bool TQueue<T>::IsEmpty()
{
  if (this->count > 0)
    return false;
  return true;
}

template<class T>
inline bool TQueue<T>::IsFull()
{
  if (this->count == this->length)
    return true;
  return false;
}

template<class T>
inline int TQueue<T>::Length()
{
  return this->length;
}

template <class T1>
ostream& operator<<(ostream& ostr, const TQueue<T1>& Q)
{
  int i = Q.front;
  if (Q.front <= Q.back)
    for (i; i <= Q.back; i++)
      ostr << Q.queue[i];
  else
  {
    for (i; i < Q.length; i++)
      ostr << Q.queue[i];
    i = 0;
    for (i; i <= Q.back; i++)
      ostr << Q.queue[i];
  }
  return ostr;
}

template <class T1>
istream& operator>>(istream& istr, TQueue<T1>& Q)
{
  int n;
  T1 t;
  istr >> n;
  for (int i = 0; i < n; i++)
  {
    istr >> t;
    Q.Push(t);
  }
  return istr;
}

// доп задачи

template<class T>
inline T TQueue<T>::GetMaxElem()
{
  if (IsEmpty())
    throw exception();
  int i = this->front;
  int ind = i;
  if (this->front <= this->back)
  {
    for (i; i <= this->back; i++)
      if (this->queue[i] > this->queue[ind])
        ind = i;
  }
  else
  {
    for (i; i < this->length; i++)
      if (this->queue[i] > this->queue[ind])
        ind = i;
    i = 0;
    for (i; i <= this->back; i++)
      if (this->queue[i] > this->queue[ind])
        ind = i;
  }
  return this->queue[ind];
}

template<class T>
inline T TQueue<T>::GetMinElem()
{
  if (IsEmpty())
    throw exception();
  int i = this->front;
  int ind = i;
  if (this->front <= this->back)
  {
    for (i; i <= this->back; i++)
      if (this->queue[i] < this->queue[ind])
        ind = i;
  }
  else
  {
    for (i; i < this->length; i++)
      if (this->queue[i] < this->queue[ind])
        ind = i;
    i = 0;
    for (i; i <= this->back; i++)
      if (this->queue[i] < this->queue[ind])
        ind = i;
  }
  return this->queue[ind];
}

template<class T>
inline void TQueue<T>::WriteToFile(string name)
{
  ofstream fout(name.c_str());
  fout << *this;
  fout.close();
}

template<class T1>
inline ofstream& operator<<(ofstream& ofstr, const TQueue<T1>& Q)
{
  int i = Q.front;
  if (Q.front <= Q.back)
    for (i; i <= Q.back; i++)
      ofstr << Q.queue[i];
  else
  {
    for (i; i < Q.length; i++)
      ofstr << Q.queue[i];
    i = 0;
    for (i; i <= Q.back; i++)
      ofstr << Q.queue[i];
  }
  return ofstr;
}

#endif

