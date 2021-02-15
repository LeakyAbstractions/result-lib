
# include "testing.h"

static bool predicate(int value);
static short mapper(int value);

/**
 * `result_filter` should execute the `predicate` and then ignore `mapper`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    const int_short_result_t filtered = result_filter(result, int_short_result_t, predicate, mapper);
    // Then
    TEST_ASSERT_SUCCESS(filtered, 1234);
}

static bool predicate(int value) {
    TEST_ASSERT(value == 1234);
    return true;
}

static short mapper(int value) {
    (void) value;
    TEST_FAIL;
}
