
# include "testing.h"

/**
 * `result_is_success` should return `true`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    const bool is_success = result_is_success(result);
    // Then
    TEST_ASSERT(is_success == true);
}
