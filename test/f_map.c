
# include "testing.h"

static long s_mapper(int value);
static char f_mapper(short value);

/**
 * `result_map` should execute the second `mapper` only.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    const struct long_char_result mapped = result_map(result, struct long_char_result, s_mapper, f_mapper);
    // Then
    TEST_ASSERT_FAILURE(mapped, 'A');
}

static long s_mapper(int value) {
    (void) value;
    TEST_FAIL;
}

static char f_mapper(short value) {
    TEST_ASSERT(value == 10);
    return 'A';
}
