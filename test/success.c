
# include "testing.h"

/**
 * `result_success` should return a successful result containing the provided value.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // Then
    TEST_ASSERT_SUCCESS(result, 1234);
}
