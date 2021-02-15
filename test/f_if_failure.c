
# include "testing.h"

/**
 * `result_if_failure` should perform `action`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    bool action_was_executed = false;
    // When
    result_if_failure(result, short value, {
        TEST_ASSERT(value == 10);
        action_was_executed = true;
    });
    // Then
    TEST_ASSERT(action_was_executed);
}
