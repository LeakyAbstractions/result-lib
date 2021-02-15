
# include "testing.h"

static void s_handler(int value);
static void f_handler(short value);
static bool s_handler_was_executed = false;

/**
 * `result_handle` should invoke the first `handler` only.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    result_handle(result, s_handler, f_handler);
    // Then
    TEST_ASSERT(s_handler_was_executed);
}

static void s_handler(int value) {
    TEST_ASSERT(value == 1234);
    s_handler_was_executed = true;
}

static void f_handler(short value) {
    (void) value;
    TEST_FAIL;
}
