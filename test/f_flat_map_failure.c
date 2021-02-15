
# include "testing.h"

static struct int_char_result flat_mapper(short value);

/**
 * `result_flat_map_failure` should execute `flat_mapper`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    const struct int_char_result mapped = result_flat_map_failure(result, struct int_char_result, flat_mapper);
    // Then
    TEST_ASSERT_SUCCESS(mapped, 1234);
}

static struct int_char_result flat_mapper(short value) {
    TEST_ASSERT(value == 10);
    return result_success(struct int_char_result, 1234);
}
