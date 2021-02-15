
# include "testing.h"

static long_short_result_t flat_mapper(int value);

/**
 * `result_flat_map_success` should ignore `flat_mapper`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    const long_short_result_t mapped = result_flat_map_success(result, long_short_result_t, flat_mapper);
    // Then
    TEST_ASSERT_FAILURE(mapped, 10);
}

static long_short_result_t flat_mapper(int value) {
    (void) value;
    TEST_FAIL;
}
