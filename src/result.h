/**
 *
 * @file        result.h
 *
 * result library macros
 *
 * @version     1.0.0.0
 * @author      Copyright (c) 2021 Guillermo Calvo
 *
 * A result object represents the outcome of an operation that may have either
 * succeeded or failed.
 *
 * Results are data structures that describe one of these two mutually-exclusive
 * fulfillment states:
 *
 * - **Success**: the operation completed entirely and produced a success value
 * - **Failure**: the operation couldn't go through and produced a failure value
 *
 * On the one hand, a result object conveys fulfillment state. On the other
 * hand, it also holds a value produced by the operation. Its meaning totally
 * depends on the semantics defined by the operation:
 *
 * - If the fulfillment state is **success**, `result_is_success` will yield
 *   `true` and `result_is_failure` will yield `false`.
 * - If the fulfillment state is **failure**, `result_is_failure` will yield
 *   yield `true` and `result_is_success` will yield `false`.
 *
 * Additional macros that depend on fulfillment state are provided, such as
 * `result_get_success_or_else` (return an alternative success value if the
 * operation failed) and `if_success` (execute a block of code if the operation
 * succeeded).
 */

#ifndef RESULT_H
#define RESULT_H

#include <stdbool.h>

/**
 * Define a `struct` that represents the oucome of an operation that may produce
 * either a succeess value of type `SUCCESS_TYPE`
 * or a failure value of type `FAILURE_TYPE`.
 *
 * Result structures should be named (or aliased via `typedef`) so that values
 * produced by result expressions can be assigned to variables that hold that
 * specific type of results.
 *
 * Example:
 *
 * ```
 * struct my_result result_of(int, const char *);
 * typedef struct result_of(int, const char *) my_result_t;
 * ```
 *
 * @param   SUCCESS_TYPE
 *          The type of the success value
 * @param   FAILURE_TYPE
 *          The type of the failure value
 * @return  The `struct` definition of a result type that can contain
 *          either a success value of type `SUCCESS_TYPE`
 *          or a failure value of type `FAILURE_TYPE`
 */
#define result_of(SUCCESS_TYPE, FAILURE_TYPE) \
    { \
        union { \
            SUCCESS_TYPE _success; \
            FAILURE_TYPE _failure; \
        }; \
        bool _is_failure; \
    }

/**
 * Create a new failed result object
 * holding the failure value produced by `EXPRESSION`.
 *
 * Example:
 *
 * ```
 * my_result_t result = result_failure(my_result_t, "Something went wrong");
 * ```
 *
 * @param   RESULT_TYPE
 *          The type of the result
 * @param   EXPRESSION
 *          The expression that will be evaluated to produce the success value
 * @return  A new failed result object that can be assigned
 *          to an lvalue of type `RESULT_TYPE`
 */
#define result_failure(RESULT_TYPE, EXPRESSION) \
    ( (RESULT_TYPE) { ._failure = (EXPRESSION), ._is_failure = true } )

/**
 * Create a new successful result object
 * holding the success value produced by `EXPRESSION`.
 *
 * Example:
 *
 * ```
 * struct my_result result = result_success(struct my_result, 123);
 * ```
 *
 * @param   RESULT_TYPE
 *          The type of the result
 * @param   EXPRESSION
 *          The expression that will be evaluated to produce the failure value
 * @return  A new successful result object that can be assigned
 *          to an lvalue of type `RESULT_TYPE`
 */
#define result_success(RESULT_TYPE, EXPRESSION) \
    ( (RESULT_TYPE) { ._success = (EXPRESSION), ._is_failure = false } )

/**
 * Return `true` if `RESULT` is a failed result; otherwise return `false`.
 *
 * ```
 * bool operation_failed = result_is_failure(result);
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @return  `true` if `RESULT` is a failed result; otherwise `false`.
 */
#define result_is_failure(RESULT) \
    ( !!(RESULT)._is_failure )

/**
 * Return `true` if `RESULT` is a successful result; otherwise return `false`.
 *
 * Example:
 *
 * ```
 * bool operation_succeeded = result_is_success(result);
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @return  `true` if `RESULT` is a successful result; otherwise `false`
 */
#define result_is_success(RESULT) \
    (  !(RESULT)._is_failure )

/**
 * Return the failure value held by `RESULT` if it is a failed result;
 * otherwise evaluate and return `EXPRESSION`.
 *
 * Example:
 *
 * ```
 * const char * message = result_get_failure_or_else(result, NULL);
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   EXPRESSION
 *          The expression that will be evaluated to produce the failure value
 * @return  Either the failure value held by `RESULT`,
 *          or the value produced by `EXPRESSION`
 */
#define result_get_failure_or_else(RESULT, EXPRESSION) \
    ( result_is_failure(RESULT) ? result_GET_FAILURE(RESULT) : (EXPRESSION) )

/**
 * Return the failure value held by `RESULT` if it is a failed result;
 * otherwise **undefined behavior**.
 *
 * Most of the use cases that depend on the failure value held by a result
 * object are already covered by other macros, so this macro should not be used
 * directly. In any case, it must not be used unless `result_is_failure(RESULT)`
 * yields `true`.
 *
 * Example:
 *
 * ```
 * const char * message = NULL;
 * if (result_is_failure(result)) {
 *     message = result_GET_FAILURE(result);
 * }
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @return  The failure value held by `RESULT`
 */
#define result_GET_FAILURE(RESULT) \
    ( (RESULT)._failure )

/**
 * Return the success value held by `RESULT` if it is a successful result;
 * otherwise evaluate and return `EXPRESSION`.
 *
 * Example:
 *
 * ```
 * int number = result_get_success_or_else(result, -1);
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   EXPRESSION
 *          The expression that will be evaluated to produce the success value
 * @return  Either the success value held by `RESULT`,
 *          or the value produced by `EXPRESSION`
 */
#define result_get_success_or_else(RESULT, EXPRESSION) \
    ( result_is_success(RESULT) ? result_GET_SUCCESS(RESULT) : (EXPRESSION) )

/**
 * Return the success value held by `RESULT` if it is a successful result;
 * otherwise return a success value produced by `MAPPER`.
 *
 * Example:
 *
 * ```
 * size_t number = result_get_success_or_else_map(result, strlen);
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   MAPPER
 *          The function or macro that will accept the failure value and produce
 *          a success value
 * @return  Either the success value held by `RESULT`,
 *          or the value produced by `MAPPER`
 */
#define result_get_success_or_else_map(RESULT, MAPPER) \
    ( result_is_success(RESULT) ? \
        result_GET_SUCCESS(RESULT) : MAPPER(result_GET_FAILURE(RESULT)) )

/**
 * Return the success value held by `RESULT` if it is a successful result;
 * otherwise undefined behavior.
 *
 * Most of the use cases that depend on the success value held by a result
 * object are already covered by other macros, so this macro should not be used
 * directly. In any case, it must not be used unless `result_is_success(RESULT)`
 * yields `true`.
 *
 * Example:
 *
 * ```
 * const char * number = -1;
 * if (result_is_success(result)) {
 *     number = result_GET_SUCCESS(result);
 * }
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @return  The success value held by `RESULT`
 */
#define result_GET_SUCCESS(RESULT) \
    ( (RESULT)._success )

/**
 * Return a new failed result object if `RESULT` is a successful result
 * whose value does not match `PREDICATE`; otherwise return `RESULT`.
 *
 * ```
 * #define IS_NEGATIVE(NUMBER) ((NUMBER) < 0)
 * #define MUST_BE_NEGATIVE(NUMBER) "Number must be negative"
 * my_result_t filtered = result_filter(result, IS_NEGATIVE, MUST_BE_NEGATIVE);
 * #undefine IS_NEGATIVE
 * #undefine MUST_BE_NEGATIVE
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   RESULT_TYPE
 *          The type of the result
 * @param   PREDICATE
 *          The function or macro that will accept the success value and then
 *          produce a boolean expression indicating whether or not
 *          `MAPPER` must be executed to produce a failure value
 * @param   MAPPER
 *          The function or macro that will accept the success value and
 *          produce a failure value
 * @return  `RESULT` if it is a successful result
 *          and its success value matches the predicate;
 *          otherwise a failed result containing the value produced by `MAPPER`
 */
#define result_filter(RESULT, RESULT_TYPE, PREDICATE, MAPPER) \
    ( result_is_failure(RESULT) || (PREDICATE(result_GET_SUCCESS(RESULT))) \
        ? (RESULT) \
        : result_failure(RESULT_TYPE, MAPPER(result_GET_SUCCESS(RESULT))) )

/**
 * Apply the appropriate `MAPPER` to the success/failure value held by `RESULT`
 * and return a new result object with the produced value.
 *
 * ```
 * struct bar result_of(long, char);
 * #define TEN_TIMES(NUMBER) (10L * (NUMBER))
 * #define FIRST_CHAR(MESSAGE) ((MESSAGE)[0])
 * struct bar mapped = result_map(result, struct bar, TEN_TIMES, FIRST_CHAR);
 * #undefine TEN_TIMES
 * #undefine FIRST_CHAR
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   RESULT_TYPE
 *          The type of the mapped result
 * @param   S_MAPPER
 *          The function or macro that will map the success value
 * @param   F_MAPPER
 *          The function or macro that will map the failure value
 * @return  A new result object that can be assigned to an lvalue of type
 *          `RESULT_TYPE` containing the mapped value
 */
#define result_map(RESULT, RESULT_TYPE, S_MAPPER, F_MAPPER) \
    ( result_is_success(RESULT) \
        ? result_success(RESULT_TYPE, S_MAPPER(result_GET_SUCCESS(RESULT))) \
        : result_failure(RESULT_TYPE, F_MAPPER(result_GET_FAILURE(RESULT))) )

/**
 * Apply `MAPPER` to the failure value if `RESULT` is a failed result
 * and return a new result object with the produced value;
 * otherwise return a new result object with the success value held by `RESULT`.
 *
 * ```
 * struct baz result_of(int, char);
 * #define FIRST_CHAR(MESSAGE) ((MESSAGE)[0])
 * struct baz mapped = result_map_failure(result, struct baz, FIRST_CHAR);
 * #undefine FIRST_CHAR
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   RESULT_TYPE
 *          The type of the mapped result
 * @param   MAPPER
 *          The function or macro that will map the failure value
 * @return  A new result object that can be assigned to an lvalue of type
 *          `RESULT_TYPE` containing either the mapped failure value
 *          or the success value held by `RESULT`
 */
#define result_map_failure(RESULT, RESULT_TYPE, MAPPER) \
    ( result_is_failure(RESULT) \
        ? result_failure(RESULT_TYPE, MAPPER(result_GET_FAILURE(RESULT))) \
        : result_success(RESULT_TYPE, result_GET_SUCCESS(RESULT)) )

/**
 * Apply `MAPPER` to the success value if `RESULT` is a successful result
 * and return a new result object with the produced value;
 * otherwise return a new result object with the failure value held by `RESULT`.
 *
 * ```
 * typedef struct result_of(long, const char *) qux;
 * #define TEN_TIMES(NUMBER) (10L * (NUMBER))
 * qux mapped = result_map(result, qux, TEN_TIMES);
 * #undefine TEN_TIMES
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   RESULT_TYPE
 *          The type of the mapped result
 * @param   MAPPER
 *          The function or macro that will map the success value
 * @return  A new result object that can be assigned to an lvalue of type
 *          `RESULT_TYPE` containing either the mapped success value
 *          or the failure value held by `RESULT`
 */
#define result_map_success(RESULT, RESULT_TYPE, MAPPER) \
    ( result_is_success(RESULT) \
        ? result_success(RESULT_TYPE, MAPPER(result_GET_SUCCESS(RESULT))) \
        : result_failure(RESULT_TYPE, result_GET_FAILURE(RESULT)) )

/**
 * Apply the appropriate result-bearing `FLAT_MAPPER` to the success/failure
 * value held by `RESULT` and return the produced result object.
 *
 * ```
 * typedef struct result_of(short, bool) quux;
 *
 * quux yay(int number) {
 *     if(number < 0) {
 *         return result_failure(true);
 *     }
 *     return result_success(10);
 * }
 *
 * quux nay(const char * message) {
 *     if(message == NULL) {
 *         return result_failure(false);
 *     }
 *     return result_success(0);
 * }
 *
 * quux transform_result(foobar result) {
 *     return result_flat_map(result, quux, yay, nay);
 * }
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   S_FLAT_MAPPER
 *          The function or macro that will map the success value to a new
 *          result value
 * @param   F_FLAT_MAPPER
 *          The function or macro that will map the failure value to a new
 *          result value
 * @return  A result object produced by the appropriate `FLAT_MAPPER`
 */
#define result_flat_map(RESULT, S_FLAT_MAPPER, F_FLAT_MAPPER) \
    ( result_is_success(RESULT) \
        ? S_FLAT_MAPPER(result_GET_SUCCESS(RESULT)) \
        : F_FLAT_MAPPER(result_GET_FAILURE(RESULT)) )

/**
 * Apply the result-bearing `FLAT_MAPPER` to the failure value
 * and return the produced result object if `RESULT` is a failed result;
 * otherwise return a new result object with the success value held by `RESULT`.
 *
 * ```
 * typedef struct result_of(int, bool) quuz;
 *
 * quuz nay(const char * message) {
 *     if(message == NULL) {
 *         return result_failure(false);
 *     }
 *     return result_success(0);
 * }
 *
 * quuz result_flat_map_failure(foobar result) {
 *     return result_flat_map_failure(result, quux, nay);
 * }
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   RESULT_TYPE
 *          The type of the returned result
 * @param   FLAT_MAPPER
 *          The function or macro that will map the failure value to a new
 *          result value
 * @return  Either a result object produced by `FLAT_MAPPER`
 *          or a new successful result containing the value held by `RESULT`
 */
#define result_flat_map_failure(RESULT, RESULT_TYPE, FLAT_MAPPER) \
    ( result_is_failure(RESULT) \
        ? FLAT_MAPPER(result_GET_FAILURE(RESULT)) \
        : result_success(RESULT_TYPE, result_GET_SUCCESS(RESULT)) )

/**
 * Apply the result-bearing `FLAT_MAPPER` to the success value
 * and return the produced result object if `RESULT` is a successful result;
 * otherwise return a new result object with the failure value held by `RESULT`.
 *
 * ```
 * typedef struct result_of(short, const char *) foobaz;
 *
 * foobaz yay(int number) {
 *     if(number < 0) {
 *         return result_failure("Less than zero");
 *     }
 *     return result_success(10);
 * }
 *
 * quux transform_result(foobar result) {
 *     return result_flat_map_success(result, quux, yay);
 * }
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   RESULT_TYPE
 *          The type of the returned result
 * @param   MAPPER
 *          The function or macro that will map the success value to a new
 *          result value
 * @return  Either a result object produced by `FLAT_MAPPER`
 *          or a new failed result containing the value held by `RESULT`
 */
#define result_flat_map_success(RESULT, RESULT_TYPE, FLAT_MAPPER) \
    ( result_is_success(RESULT) \
        ? FLAT_MAPPER(result_GET_SUCCESS(RESULT)) \
        : result_failure(RESULT_TYPE, result_GET_FAILURE(RESULT)) )

/**
 * Execute the appropriate `HANDLER` with the success/failure value held by
 * `RESULT`.
 *
 * ```
 * void commit(int number) {
 *     printf("Committing %d changes\n", number);
 *     // ...
 * }
 *
 * void rollback(const char * error) {
 *     printf("Rolling back (error: %s)\n", error);
 *     // ...
 * }
 *
 * void handle_result(my_result_t result) {
 *     return result_handle(result, commit, rollback);
 * }
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   S_HANDLER
 *          The function or macro that will accept the success value
 * @param   F_HANDLER
 *          The function or macro that will accept the failure value
 */
#define result_handle(RESULT, S_HANDLER, F_HANDLER) \
    do { \
        if (result_is_success(RESULT)) { \
            S_HANDLER(result_GET_SUCCESS(RESULT)); \
        } else { \
            F_HANDLER(result_GET_FAILURE(RESULT)); \
        } \
    } while (0)

/**
 * Execute `HANDLER` with the failure value if `RESULT` is a failed result;
 * otherwise do nothing.
 *
 * ```
 * void rollback(const char * error) {
 *     printf("Rolling back (error: %s)\n", error);
 *     // ...
 * }
 *
 * void handle_result(my_result_t result) {
 *     return result_handle_failure(result, commit, rollback);
 * }
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   HANDLER
 *          The function or macro that will accept the failure value
 */
#define result_handle_failure(RESULT, HANDLER) \
    do { \
        if (result_is_failure(RESULT)) { \
            HANDLER(result_GET_FAILURE(RESULT)); \
        } \
    } while (0)

/**
 * Execute `HANDLER` with the success value if `RESULT` is a successful result;
 * otherwise do nothing.
 *
 * ```
 * void commit(int number) {
 *     printf("Committing %d changes\n", number);
 *     // ...
 * }
 *
 * void handle_result(my_result_t result) {
 *     return result_handle_success(result, commit);
 * }
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   HANDLER
 *          The function or macro that will accept the success value
 */
#define result_handle_success(RESULT, HANDLER) \
    do { \
        if (result_is_success(RESULT)) { \
            HANDLER(result_GET_SUCCESS(RESULT)); \
        } \
    } while (0)

/**
 * Assign the success/failure value held by `RESULT` to the appropriate `LVALUE`
 * and then evaluate the appropriate `ACTION`.
 *
 * ```
 * return result_if_success_or_else(result,
 *     int number -> {
 *         printf("Committing %d changes\n", number);
 *         // ...
 *     },
 *     const char * error -> {
 *         printf("Rolling back (error: %s)\n", error);
 *         // ...
 *     }
 * );
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   S_LVALUE
 *          The lvalue that will be assigned with the success value
 * @param   S_ACTION
 *          The block of code that will be executed right after assigning the
 *          success value to the previous lvalue
 * @param   F_LVALUE
 *          The lvalue that will be assigned with the failure value
 * @param   F_ACTION
 *          The block of code that will be executed right after assigning the
 *          failure value to the previous lvalue
 */
#define result_if_success_or_else(RESULT, S_LVALUE, S_ACTION, F_LVALUE, F_ACTION) \
    do { \
        if (result_is_success(RESULT)) { \
            S_LVALUE = result_GET_SUCCESS(RESULT); \
            S_ACTION \
        } else { \
            F_LVALUE = result_GET_FAILURE(RESULT); \
            F_ACTION \
        } \
    } while (0)

/**
 * Assign the failure value to `LVALUE` and then evaluate `ACTION`
 * if `RESULT` is a failed result; otherwise do nothing.
 *
 * ```
 * return result_if_failure(result, const char * error -> {
 *     printf("Rolling back (error: %s)\n", error);
 *     // ...
 * });
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   LVALUE
 *          The lvalue that will be assigned with the failure value
 * @param   ACTION
 *          The block of code that will be executed right after assigning the
 *          failure value to the previous lvalue
 */
#define result_if_failure(RESULT, LVALUE, ACTION) \
    do { \
        if (result_is_failure(RESULT)) { \
            LVALUE = result_GET_FAILURE(RESULT); \
            ACTION \
        } \
    } while (0)

/**
 * Assign the success value to `LVALUE` and then evaluate `ACTION`
 * if `RESULT` is a successful result; otherwise do nothing.
 *
 * ```
 * return result_if_success(result, int number -> {
 *     printf("Committing %d changes\n", number);
 *     // ...
 * });
 * ```
 *
 * @param   RESULT
 *          The result object to work with
 * @param   LVALUE
 *          The lvalue that will be assigned with the success value
 * @param   ACTION
 *          The block of code that will be executed right after assigning the
 *          success value to the previous lvalue
 */
#define result_if_success(RESULT, LVALUE, ACTION) \
    do { \
        if (result_is_success(RESULT)) { \
            LVALUE = result_GET_SUCCESS(RESULT); \
            ACTION \
        } \
    } while (0)

#endif
