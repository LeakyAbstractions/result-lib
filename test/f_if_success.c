
# include "testing.h"

/**
 * `result_if_success` should ignore `action`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_failure(int_short_result_t, 10);
    // When
    result_if_success(result, int value, {
        (void) value;
        TEST_FAIL;
    });
    // Then (action was ignored)
}
