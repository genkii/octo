## Building

```bash
CC=clang CXX=clang++ cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
```

```bash
# Development
cmake --build --preset debug

# Release
cmake --build --preset release

# Tests + coverage
cmake --build --preset coverage --target coverage
```

## Coverage

```bash
cmake --preset coverage
cmake --build --preset coverage --target coverage
```
