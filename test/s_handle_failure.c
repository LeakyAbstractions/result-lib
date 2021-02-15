
# include "testing.h"

static void handler(short value);

/**
 * `result_handle_failure` should ignore `handler`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    result_handle_failure(result, handler);
    // Then (handler was ignored)
}

static void handler(short value) {
    (void) value;
    TEST_FAIL;
}
