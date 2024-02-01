# FastXor - SIMD-based XOR Encryption

FastXor is a C++ class that provides a fast XOR encryption method using SIMD instructions. It can be used to efficiently XOR data with a key.

[Intrinsics Guide](https://www.laruence.com/sse/#expand=5655&techs=SSE2,AVX,AVX2)

## Features

- SIMD-based XOR encryption for improved performance.
- Supports XOR operation on arrays, vectors, and strings.
- Easy-to-use C++ class interface.

## Installation

To use this package, you can clone the repository and compile it using a C++ compiler:

```bash
git clone https://github.com/NIR3X/FastXor.cpp
cd FastXor.cpp/sse2 # or /avx2
make
```

## Usage

To use the FastXor class, include the "FastXor.h" header in your project and make sure to link against the appropriate libraries.

### Example

```cpp
#include "FastXor.h"

// Your code...

// Example with vector<uint8_t>
std::vector<uint8_t> data = { /* your data */ };
std::vector<uint8_t> key = { /* your key */ };

CFastXor::Xor(data, key);

// Example with string
std::string strData = "YourStringData";
std::string strKey = "YourKey";

CFastXor::Xor(strData, strKey);

// Your code...
```

## License
[![GNU AGPLv3 Image](https://www.gnu.org/graphics/agplv3-155x51.png)](https://www.gnu.org/licenses/agpl-3.0.html)  

This program is Free Software: You can use, study share and improve it at your
will. Specifically you can redistribute and/or modify it under the terms of the
[GNU Affero General Public License](https://www.gnu.org/licenses/agpl-3.0.html) as
published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
