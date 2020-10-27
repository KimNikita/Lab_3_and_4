#include "Stack.h"
#include <fstream>
#include <../gtest/gtest.h>

TEST(TStack, can_create_stack_positive_size)
{
  ASSERT_NO_THROW(TStack<int>(3));
}

  