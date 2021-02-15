
# include "testing.h"

/**
 * `result_is_failure` should return `false`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    const bool is_failure = result_is_failure(result);
    // Then
    TEST_ASSERT(is_failure == false);
}
