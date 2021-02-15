
# include "testing.h"

static bool predicate(int value);
static short mapper(int value);

/**
 * `result_filter` should ignore `predicate` and `mapper`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    const int_short_result_t filtered = result_filter(result, int_short_result_t, predicate, mapper);
    // Then
    TEST_ASSERT_FAILURE(filtered, 10);
}

static bool predicate(int value) {
    (void) value;
    TEST_FAIL;
}

static short mapper(int value) {
    (void) value;
    TEST_FAIL;
}
