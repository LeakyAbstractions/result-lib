
# include "testing.h"

/**
 * `result_if_success_or_else` should perform the first `action` only.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    bool success_action_was_executed = false;
    // When
    result_if_success_or_else(result,
        int value, {
            TEST_ASSERT(value == 1234);
            success_action_was_executed = true;
        },
        short value, {
            (void) value;
            TEST_FAIL;
        }
    );
    // Then
    TEST_ASSERT(success_action_was_executed);
}
