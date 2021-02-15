
# include "testing.h"

static short default_value();

/**
 * `result_get_failure_or_else` should ignore `expression`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    const short value = result_get_failure_or_else(result, default_value());
    // Then
    TEST_ASSERT(value == 10);
}

static short default_value() {
    TEST_FAIL;
}
