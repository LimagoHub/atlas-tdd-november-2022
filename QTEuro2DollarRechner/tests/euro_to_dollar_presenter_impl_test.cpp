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

TEST_F(euro_to_dollar_presenter_impl_test,beenden__happy_day__fenster_wird_geschlossen ) {

    EXPECT_CALL(euro_to_dollar_viewMock, dispose());
    object_under_test.beenden();
}

TEST_F(euro_to_dollar_presenter_impl_test,populate_items__happy_day__fenster_wird_mit_werten_initialisiert ) {

    EXPECT_CALL(euro_to_dollar_viewMock, set_euro("0"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("0"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true));
    object_under_test.populate_items();
}


TEST_F(euro_to_dollar_presenter_impl_test,rechnen__nan_in_eurofield__error_message_in_dollar_field ) {


    // Arrange
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(Return("Not a Number"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Keine Zahl"));

    object_under_test.rechnen();
}



TEST_F(euro_to_dollar_presenter_impl_test,rechnen__any_unexcpected_exception_in_underlying_service__error_message_in_dollar_field) {


    // Arrange
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(Return("10.0"));
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(_)).WillOnce(Throw(std::out_of_range{"Upps"}));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Fehler im Service"));
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test,rechnen__happy_day___euro_passed_to_service_and_result_in_dollarfield) {


    // Arrange
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(Return("10.0"));
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(10.0)).WillOnce(Return(1000.0));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("1000.000000"));
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test,update_rechnen_action_state__NAN_in_Eurofield__rechnen_disabled) {

    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(Return("Not a Number"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(false));
    object_under_test.update_rechnen_action_state();
}

TEST_F(euro_to_dollar_presenter_impl_test,update_rechnen_action_state__valid_number_in_Eurofield__rechnen_enabled) {

    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(Return("10.0"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true));
    object_under_test.update_rechnen_action_state();
}