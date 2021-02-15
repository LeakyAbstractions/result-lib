
# include "testing.h"

static void handler(int value);

/**
 * `result_handle_success` should ignore `handler`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    result_handle_success(result, handler);
    // Then (action was ignored)
}

static void handler(int value) {
    (void) value;
    TEST_FAIL;
}
