
# ifndef TESTING_H
# define TESTING_H


# include <stdlib.h>
# include <stdio.h>
# include <result.h>


/* Test types */
typedef struct result_of(const int, const short) int_short_result_t;
typedef struct result_of(const long, const short) long_short_result_t;
struct int_char_result result_of(const int, const char);
struct long_char_result result_of(const long, const char);


/* Test Results */
# define TEST_RESULT_PASS   EXIT_SUCCESS
# define TEST_RESULT_SKIP   77
# define TEST_RESULT_FAIL   EXIT_FAILURE


/* Test Actions */
# define TEST_EXIT(RESULT)  exit(RESULT)
# define TEST_PASS          TEST_EXIT(TEST_RESULT_PASS)
# define TEST_SKIP          TEST_EXIT(TEST_RESULT_SKIP)
# define TEST_FAIL \
    do{ \
        (void) fprintf(stderr, "Test failed at line: %d\n", __LINE__); \
        TEST_EXIT(TEST_RESULT_FAIL); \
    }while(0)

# define TEST_ASSERT(CHECK) \
    do{ \
        if( !(CHECK) ){ \
            (void) fprintf(stderr, "Assertion failed: %s (at line: %d)\n", #CHECK, __LINE__); \
            TEST_FAIL; \
        } \
    }while(0)

# define TEST_ASSERT_SUCCESS(RESULT, EXPECTED) \
    do{ \
        TEST_ASSERT(result_is_success(RESULT)); \
        TEST_ASSERT(result_GET_SUCCESS(RESULT) == (EXPECTED)); \
    }while(0)

# define TEST_ASSERT_FAILURE(RESULT, EXPECTED) \
    do{ \
        TEST_ASSERT(result_is_failure(RESULT)); \
        TEST_ASSERT(result_GET_FAILURE(RESULT) == (EXPECTED)); \
    }while(0)


/* Test Cases */
# define TEST_CASE \
    \
    void test_case(void); \
    \
    int main(void){ \
        (void) printf("    - Running test %s...\n", __FILE__); \
        test_case(); \
        return(EXIT_SUCCESS); \
    } \
    \
    void test_case(void)


# endif
