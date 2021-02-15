
# include "testing.h"

/**
 * `result_get_failure_or_else` should evaluate `expression`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    const short value = result_get_failure_or_else(result, 10);
    // Then
    TEST_ASSERT(value == 10);
}
