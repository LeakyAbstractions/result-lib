
# include "testing.h"

static long mapper(int value);

/**
 * `result_map_success` should ignore `mapper`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    const long_short_result_t mapped = result_map_success(result, long_short_result_t, mapper);
    // Then
    TEST_ASSERT_FAILURE(mapped, 10);
}

static long mapper(int value) {
    (void) value;
    TEST_FAIL;
}
