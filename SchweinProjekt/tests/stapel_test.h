#pragma once

#include "gtest/gtest.h"
#include "../source/stapel.h"
using namespace testing;

class stapel_test:public Test
{
protected:
	stapel object_under_test;
};