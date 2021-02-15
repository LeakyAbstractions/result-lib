
# include "testing.h"

static long s_mapper(int value);
static char f_mapper(short value);

/**
 * `result_map` should execute the first `mapper` only.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    const struct long_char_result mapped = result_map(result, struct long_char_result, s_mapper, f_mapper);
    // Then
    TEST_ASSERT_SUCCESS(mapped, 54321L);
}

static long s_mapper(int value) {
    (void) value;
    return 54321L;
}

static char f_mapper(short value) {
    (void) value;
    TEST_FAIL;
}
