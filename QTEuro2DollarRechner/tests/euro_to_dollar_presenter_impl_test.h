//
// Created by JoachimWagner on 31.05.2022.
//

#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../presenter/euro_to_dollar_presenter_impl.h"
#include "Mockeuro_to_dollar_calculator.h"
#include "Mockeuro_to_dollar_view.h"

class euro_to_dollar_presenter_impl_test : public testing::Test{

protected:
    Mockeuro_to_dollar_calculator  euro_to_dollar_calculatorMock;
    Mockeuro_to_dollar_view  euro_to_dollar_viewMock;
    euro_to_dollar_presenter_impl object_under_test;

    void SetUp() override;
};




