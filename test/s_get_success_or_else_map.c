
# include "testing.h"

static int mapper(short value);

/**
 * `result_get_success_or_else_map` should ignore `mapper`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    const int value = result_get_success_or_else_map(result, mapper);
    // Then
    TEST_ASSERT(value == 1234);
}

static int mapper(short value) {
    (void) value;
    TEST_FAIL;
}
