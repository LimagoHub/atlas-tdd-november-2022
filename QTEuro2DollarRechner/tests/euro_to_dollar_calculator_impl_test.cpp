//
// Created by JoachimWagner on 30.05.2022.
//

#include "euro_to_dollar_calculator_impl_test.h"

TEST_F(euro_to_dollar_calculator_impl_test, convert__xx) {
    const double exchange_rate = 1.1;

    EXPECT_CALL(exchange_rate_service_mock, get_rate_for(testing::Eq("USD"))).WillOnce(testing::Return(exchange_rate));

    //const auto object_under_test.convert(10.0);

}