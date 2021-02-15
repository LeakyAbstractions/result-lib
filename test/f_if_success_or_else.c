
# include "testing.h"

/**
 * `result_if_success_or_else` should perform the second `action` only.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    bool failure_action_was_executed = false;
    // When
    result_if_success_or_else(result,
        int value, {
            (void) value;
            TEST_FAIL;
        },
        short value, {
            TEST_ASSERT(value == 10);
            failure_action_was_executed = true;
        }
    );
    // Then
    TEST_ASSERT(failure_action_was_executed);
}
