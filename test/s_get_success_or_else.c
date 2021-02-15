
# include "testing.h"

static short default_value();

/**
 * `result_get_success_or_else` should ignore `expression`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    const int value = result_get_success_or_else(result, default_value());
    // Then
    TEST_ASSERT(value == 1234);
}

static short default_value() {
    TEST_FAIL;
}
