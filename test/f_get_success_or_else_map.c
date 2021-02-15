
# include "testing.h"

static int default_value(short value);

/**
 * `result_get_success_or_else_map` should invoke `mapper`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    const int value = result_get_success_or_else_map(result, default_value);
    // Then
    TEST_ASSERT(value == 1234);
}

static int default_value(short value) {
    TEST_ASSERT(value == 10);
    return 1234;
}
