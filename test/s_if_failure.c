
# include "testing.h"

/**
 * `result_if_failure` should ignore `action`.
 */
TEST_CASE {
    // Given
    const int_short_result_t result = result_success(int_short_result_t, 1234);
    // When
    result_if_failure(result, short value, {
        (void) value;
        TEST_FAIL;
    });
    // Then (action was ignored)
}
