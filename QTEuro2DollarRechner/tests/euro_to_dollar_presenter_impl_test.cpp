//
// Created by JoachimWagner on 31.05.2022.
//
#include <stdexcept>
#include "euro_to_dollar_presenter_impl_test.h"
using namespace testing;
void euro_to_dollar_presenter_impl_test::SetUp()  {
    object_under_test.set_model(&euro_to_dollar_calculatorMock);
    object_under_test.set_view(&euro_to_dollar_viewMock);
}

