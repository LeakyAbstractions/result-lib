
# include "testing.h"

static void handler(int value);
static bool handler_was_executed = false;

/**
 * `result_handle_success` should invoke `handler`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    result_handle_success(result, handler);
    // Then
    TEST_ASSERT(handler_was_executed);
}

static void handler(int value) {
    TEST_ASSERT(value == 1234);
    handler_was_executed = true;
}
