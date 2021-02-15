
# include "testing.h"

static struct long_char_result s_flat_mapper(int value);
static struct long_char_result f_flat_mapper(short value);

/**
 * `result_flat_map` should execute the first `flat_mapper` only.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    const struct long_char_result flat_mapped = result_flat_map(result, s_flat_mapper, f_flat_mapper);
    // Then
    TEST_ASSERT_SUCCESS(flat_mapped, 54321L);
}

static struct long_char_result s_flat_mapper(int value) {
    TEST_ASSERT(value == 1234);
    return result_success(struct long_char_result, 54321L);
}

static struct long_char_result f_flat_mapper(short value) {
    (void) value;
    TEST_FAIL;
}
