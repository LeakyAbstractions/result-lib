
# result

[![Last release](https://img.shields.io/github/tag/LeakyAbstractions/log.svg?label=release&colorB=007ec6)](https://github.com/LeakyAbstractions/log/releases)
[![Build status](https://travis-ci.org/LeakyAbstractions/log.svg?branch=master)](https://travis-ci.org/LeakyAbstractions/log)
[![Code coverage](https://codecov.io/github/LeakyAbstractions/log/coverage.svg?branch=master)](https://codecov.io/github/LeakyAbstractions/log?branch=master)
[![Static analysis](https://scan.coverity.com/projects/14165/badge.svg)](https://scan.coverity.com/projects/leakyabstractions-log)

> Handle success/failure results

![](https://github.com/LeakyAbstractions/result-lib/raw/master/doc/result-banner-centered.png)


## A tiny C result library

Handle success and failure like a boss.

> This software adheres to [Pragmatic Versioning](https://pragver.github.io/).


## API


### Macros

- `result_of`: Define result structure
- `result_failure`: Create new failed result object
- `result_success`: Create new successful result object
- `result_is_failure`: Check if failed result
- `result_is_success`: Check if successful result
- `result_get_failure_or_else`: Return failure value or evaluate expression
- `result_get_success_or_else`: Return success value or evaluate expression
- `result_get_success_or_else_map`: Return success value or transform failure value
- `result_filter`: Transform into a failed result if success value does not match a predicate
- `result_map`: Transform success/failure value
- `result_map_failure`: Transform failure value
- `result_map_success`: Transform success value
- `result_flat_map`: Transform success/failure into a result object
- `result_flat_map_failure`: Transform failure into a result object
- `result_flat_map_success`: Transform success into a result object
- `result_handle`: Pass success/failure value to function
- `result_handle_failure`: Pass failure value to function
- `result_handle_success`: Pass success value to function
- `result_if_success_or_else`: Execute block of code depending on failed/successful result
- `result_if_failure`: Execute block of code if failed result
- `result_if_success`: Execute block of code if successful result


## Author

Copyright 2021 [Guillermo Calvo](https://github.com/guillermocalvo)

[![](https://guillermo.dev/assets/images/thumb.png)](https://guillermo.dev/)


## License

This is free software: you can redistribute it and/or modify it under the terms
of the **GNU Lesser General Public License** as published by the
*Free Software Foundation*, either version 3 of the License, or (at your option)
any later version.

This software is distributed in the hope that it will be useful, but
**WITHOUT ANY WARRANTY**; without even the implied warranty of
**MERCHANTABILITY** or **FITNESS FOR A PARTICULAR PURPOSE**. See the
[GNU Lesser General Public License](http://www.gnu.org/licenses/lgpl.html) for
more details.

You should have received a copy of the GNU Lesser General Public License along
with this software. If not, see <http://www.gnu.org/licenses/>.

### Required

- **License and copyright notice**: Include a copy of the license and copyright
notice with the code.
- **Library usage**: The library may be used within a non-open-source
application.
- **Disclose Source**: Source code for this library must be made available when
distributing the software.

### Permitted

- **Commercial Use**: This software and derivatives may be used for commercial
purposes.
- **Modification**: This software may be modified.
- **Distribution**: You may distribute this software.
- **Sublicensing**: You may grant a sublicense to modify and distribute this
software to third parties not included in the license.
- **Patent Grant**: This license provides an express grant of patent rights from
the contributor to the recipient.

### Forbidden

- **Hold Liable**: Software is provided without warranty and the software
author/license owner cannot be held liable for damages.
