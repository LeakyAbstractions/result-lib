
# include "testing.h"

/**
 * `result_is_success` should return `false`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    const bool is_success = result_is_success(result);
    // Then
    TEST_ASSERT(is_success == false);
}
