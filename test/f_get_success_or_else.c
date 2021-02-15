
# include "testing.h"

/**
 * `result_get_success_or_else` should evaluate `expression`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    const int value = result_get_success_or_else(result, 1234);
    // Then
    TEST_ASSERT(value == 1234);
}
