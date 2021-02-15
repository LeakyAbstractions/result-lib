
# include "testing.h"

/**
 * `result_is_failure` should return `true`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    const bool is_failure = result_is_failure(result);
    // Then
    TEST_ASSERT(is_failure == true);
}
