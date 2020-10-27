#include "Queue.h"
#include <fstream>
#include <../gtest/gtest.h>

TEST(TQueue, can_create_queue_positive_size)
{
  ASSERT_NO_THROW(TQueue<int>(3));
}
