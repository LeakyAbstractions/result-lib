
# include "testing.h"

static long mapper(int value);

/**
 * `result_map_success` should execute `mapper`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    const long_short_result_t mapped = result_map_success(result, long_short_result_t, mapper);
    // Then
    TEST_ASSERT_SUCCESS(mapped, 54321L);
}

static long mapper(int value) {
    (void) value;
    return 54321L;
}
