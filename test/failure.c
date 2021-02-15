
# include "testing.h"

/**
 * `result_failure` should return a failed result containing the provided value.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // Then
    TEST_ASSERT_FAILURE(result, 10);
}
