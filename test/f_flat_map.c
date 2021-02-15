
# include "testing.h"

static struct long_char_result s_flat_mapper(int value);
static struct long_char_result f_flat_mapper(short value);

/**
 * `result_flat_map` should execute the second `flat_mapper` only.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    const struct long_char_result flat_mapped = result_flat_map(result, s_flat_mapper, f_flat_mapper);
    // Then
    TEST_ASSERT_FAILURE(flat_mapped, 'A');
}

static struct long_char_result s_flat_mapper(int value) {
    (void) value;
    TEST_FAIL;
}

static struct long_char_result f_flat_mapper(short value) {
    TEST_ASSERT(value == 10);
    return result_failure(struct long_char_result, 'A');
}
