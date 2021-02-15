#
# result
#
# Copyright (c) 2021 Guillermo Calvo
# Licensed under the GNU Lesser General Public License
#

AUTOMAKE_OPTIONS = foreign subdir-objects

AM_CFLAGS = -Wall -Wextra -Werror --pedantic -std=c11 -I$(RESULT_PATH)


# Library

RESULT_PATH         = src


# Install

include_HEADERS     = src/result.h


# Documentation

docdir              = $(datadir)/doc/result
doc_DATA            = doc/*


# Cleanup

CLEANFILES          = *.log


# Check

check_PROGRAMS      = $(TESTS)

TESTS =                                 \
	bin/test/f_filter                   \
	bin/test/f_flat_map                 \
	bin/test/f_flat_map_failure         \
	bin/test/f_flat_map_success         \
	bin/test/f_get_failure_or_else      \
	bin/test/f_get_success_or_else      \
	bin/test/f_get_success_or_else_map  \
	bin/test/f_handle                   \
	bin/test/f_handle_failure           \
	bin/test/f_handle_success           \
	bin/test/f_if_failure               \
	bin/test/f_if_success               \
	bin/test/f_if_success_or_else       \
	bin/test/f_is_failure               \
	bin/test/f_is_success               \
	bin/test/f_map                      \
	bin/test/f_map_failure              \
	bin/test/f_map_success              \
	bin/test/failure                    \
	bin/test/s_filter_false             \
	bin/test/s_filter_true              \
	bin/test/s_flat_map                 \
	bin/test/s_flat_map_failure         \
	bin/test/s_flat_map_success         \
	bin/test/s_get_failure_or_else      \
	bin/test/s_get_success_or_else      \
	bin/test/s_get_success_or_else_map  \
	bin/test/s_handle                   \
	bin/test/s_handle_failure           \
	bin/test/s_handle_success           \
	bin/test/s_if_failure               \
	bin/test/s_if_success               \
	bin/test/s_if_success_or_else       \
	bin/test/s_is_failure               \
	bin/test/s_is_success               \
	bin/test/s_map                      \
	bin/test/s_map_failure              \
	bin/test/s_map_success              \
	bin/test/success

# Tests

bin_test_f_filter_SOURCES                   = test/f_filter.c
bin_test_f_flat_map_SOURCES                 = test/f_flat_map.c
bin_test_f_flat_map_failure_SOURCES         = test/f_flat_map_failure.c
bin_test_f_flat_map_success_SOURCES         = test/f_flat_map_success.c
bin_test_f_get_failure_or_else_SOURCES      = test/f_get_failure_or_else.c
bin_test_f_get_success_or_else_SOURCES      = test/f_get_success_or_else.c
bin_test_f_get_success_or_else_map_SOURCES  = test/f_get_success_or_else_map.c
bin_test_f_handle_SOURCES                   = test/f_handle.c
bin_test_f_handle_failure_SOURCES           = test/f_handle_failure.c
bin_test_f_handle_success_SOURCES           = test/f_handle_success.c
bin_test_f_if_failure_SOURCES               = test/f_if_failure.c
bin_test_f_if_success_SOURCES               = test/f_if_success.c
bin_test_f_if_success_or_else_SOURCES       = test/f_if_success_or_else.c
bin_test_f_is_failure_SOURCES               = test/f_is_failure.c
bin_test_f_is_success_SOURCES               = test/f_is_success.c
bin_test_f_map_SOURCES                      = test/f_map.c
bin_test_f_map_failure_SOURCES              = test/f_map_failure.c
bin_test_f_map_success_SOURCES              = test/f_map_success.c
bin_test_failure_SOURCES                    = test/failure.c
bin_test_s_filter_false_SOURCES             = test/s_filter_false.c
bin_test_s_filter_true_SOURCES              = test/s_filter_true.c
bin_test_s_flat_map_SOURCES                 = test/s_flat_map.c
bin_test_s_flat_map_failure_SOURCES         = test/s_flat_map_failure.c
bin_test_s_flat_map_success_SOURCES         = test/s_flat_map_success.c
bin_test_s_get_failure_or_else_SOURCES      = test/s_get_failure_or_else.c
bin_test_s_get_success_or_else_SOURCES      = test/s_get_success_or_else.c
bin_test_s_get_success_or_else_map_SOURCES  = test/s_get_success_or_else_map.c
bin_test_s_handle_SOURCES                   = test/s_handle.c
bin_test_s_handle_failure_SOURCES           = test/s_handle_failure.c
bin_test_s_handle_success_SOURCES           = test/s_handle_success.c
bin_test_s_if_failure_SOURCES               = test/s_if_failure.c
bin_test_s_if_success_SOURCES               = test/s_if_success.c
bin_test_s_if_success_or_else_SOURCES       = test/s_if_success_or_else.c
bin_test_s_is_failure_SOURCES               = test/s_is_failure.c
bin_test_s_is_success_SOURCES               = test/s_is_success.c
bin_test_s_map_SOURCES                      = test/s_map.c
bin_test_s_map_failure_SOURCES              = test/s_map_failure.c
bin_test_s_map_success_SOURCES              = test/s_map_success.c
bin_test_success_SOURCES                    = test/success.c
