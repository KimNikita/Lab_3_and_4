#include "Queue.h"
#include <fstream>
#include <../gtest/gtest.h>

TEST(TQueue, can_create_queue_positive_size)
{
  ASSERT_NO_THROW(TQueue<int>(3));
}

TEST(TQueue, throw_when_create_queue_negative_size)
{
  ASSERT_ANY_THROW(TQueue<int>(-3));
}

TEST(TQueue, can_push_any_elements)
{
  TQueue<int> Q(4);
  Q.Push(1);
  Q.Push(2);
  EXPECT_EQ(1, Q.Get());
}

TEST(TQueue, can_pop_any_elements)
{
  TQueue<int> Q(4);
  Q.Push(1);
  Q.Push(2);
  Q.Push(3);
  Q.Push(4);
  Q.Pop();
  Q.Pop();
  Q.Push(5);
  Q.Pop();
  EXPECT_EQ(4, Q.Get());
}

//доп задачи

TEST(TQueue, can_find_max_element)
{
  TQueue<int> Q(4);
  Q.Push(1);
  Q.Push(2);
  Q.Push(-1);
  EXPECT_EQ(2, Q.GetMaxElem());
}

TEST(TQueue, can_find_min_element)
{
  TQueue<int> Q(4);
  Q.Push(1);
  Q.Push(2);
  Q.Push(-1);
  EXPECT_EQ(-1, Q.GetMinElem());
}

TEST(TQueue, can_write_queue_to_file)
{
  const int size = 9;
  TQueue<int> Q(size);
  for (int i = 0; i < size / 2; i++)
    Q.Push(i);
  Q.WriteToFile("output_q.txt");
  string expS = "0123";
  string Queue = "";
  ifstream fin("output_q.txt");
  fin >> Queue;
  fin.close();
  EXPECT_EQ(expS, Queue);
}