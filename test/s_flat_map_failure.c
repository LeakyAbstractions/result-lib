
# include "testing.h"

static struct int_char_result flat_mapper(short value);

/**
 * `result_flat_map_failure` should ignore `flat_mapper`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    const struct int_char_result mapped = result_flat_map_failure(result, struct int_char_result, flat_mapper);
    // Then
    TEST_ASSERT_SUCCESS(mapped, 1234);
}

static struct int_char_result flat_mapper(short value) {
    (void) value;
    TEST_FAIL;
}
