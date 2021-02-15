
# include "testing.h"

static bool predicate(int value);
static short mapper(int value);

/**
 * `result_filter` should execute `predicate` and then execute `mapper`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    const int_short_result_t filtered = result_filter(result, int_short_result_t, predicate, mapper);
    // Then
    TEST_ASSERT_FAILURE(filtered, 10);
}

static bool predicate(int value) {
    TEST_ASSERT(value == 1234);
    return false;
}

static short mapper(int value) {
    TEST_ASSERT(value == 1234);
    return 10;
}
