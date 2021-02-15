
# include "testing.h"

/**
 * `result_if_success` should perform `action`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    bool action_was_executed = false;
    // When
    result_if_success(result, int value, {
        TEST_ASSERT(value == 1234);
        action_was_executed = true;
    });
    // Then
    TEST_ASSERT(action_was_executed);
}
