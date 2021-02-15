
# include "testing.h"

static char mapper(short value);

/**
 * `result_map_failure` should execute `mapper`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    const struct int_char_result mapped = result_map_failure(result, struct int_char_result, mapper);
    // Then
    TEST_ASSERT_FAILURE(mapped, 'A');
}

static char mapper(short value) {
    TEST_ASSERT(value == 10);
    return 'A';
}
