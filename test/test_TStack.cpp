#include "Stack.h"
#include <fstream>
#include <../gtest/gtest.h>

TEST(TStack, can_create_stack_positive_size)
{
  ASSERT_NO_THROW(TStack<int>(3));
}

TEST(TStack, throw_when_create_stack_negative_size)
{
  ASSERT_ANY_THROW(TStack<int>(-3));
}

TEST(TStack, can_push_any_elements)
{
  TStack<int> S(4);
  S.Push(1);
  S.Push(2);
  EXPECT_EQ(2, S.Get());
}

TEST(TStack, can_pop_any_elements)
{
  TStack<int> S(4);
  S.Push(1);
  S.Push(2);
  S.Push(3);
  S.Pop();
  S.Pop();
  EXPECT_EQ(1, S.Get());
}

//доп задачи

TEST(TStack, can_find_max_element)
{
  TStack<int> S(4);
  S.Push(1);
  S.Push(2);
  S.Push(-1);
  EXPECT_EQ(2, S.GetMaxElem());
}

TEST(TStack, can_find_min_element)
{
  TStack<int> S(4);
  S.Push(1);
  S.Push(2);
  S.Push(-1);
  EXPECT_EQ(-1, S.GetMinElem());
}

TEST(TStack, can_write_stack_to_file)
{
  const int size = 9;
  TStack<int> S(size);
  for (int i = 0; i < size / 2; i++)
    S.Push(i);
  S.WriteToFile("output_s.txt");
  string expS = "0123";
  string Stack = "";
  ifstream fin("output_s.txt");
  fin >> Stack;
  fin.close();
  EXPECT_EQ(expS, Stack);
}


