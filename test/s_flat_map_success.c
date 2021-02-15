
# include "testing.h"

static long_short_result_t flat_mapper(int value);

/**
 * `result_flat_map_success` should execute `flat_mapper`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    const long_short_result_t mapped = result_flat_map_success(result, long_short_result_t, flat_mapper);
    // Then
    TEST_ASSERT_FAILURE(mapped, 10);
}

static long_short_result_t flat_mapper(int value) {
    TEST_ASSERT(value == 1234);
    return result_failure(long_short_result_t, 10);
}
