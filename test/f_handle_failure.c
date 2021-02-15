
# include "testing.h"

static void handler(short value);
static bool handler_was_executed = false;

/**
 * `result_handle_failure` should invoke `handler`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    result_handle_failure(result, handler);
    // Then
    TEST_ASSERT(handler_was_executed);
}

static void handler(short value) {
    TEST_ASSERT(value == 10);
    handler_was_executed = true;
}
