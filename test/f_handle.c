
# include "testing.h"

static void s_handler(int value);
static void f_handler(short value);
static bool f_handler_was_executed = false;

/**
 * `result_handle` should invoke the second `handler` only.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    result_handle(result, s_handler, f_handler);
    // Then
    TEST_ASSERT(f_handler_was_executed);
}

static void s_handler(int value) {
    (void) value;
    TEST_FAIL;
}

static void f_handler(short value) {
    TEST_ASSERT(value == 10);
    f_handler_was_executed = true;
}
