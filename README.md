# Octo

Octo is an small 16-bit vCPU build in C++

## Building

```bash
cmake --preset debug
cmake --build --preset debug
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

## Tests

```bash
cmake --build --preset release
ctest --test-dir build/release --output-on-failure
```


## Tasks

- [ x ] Add memory bounds checks
- [  ] Refactor register ids to be enforced (hard coded) and checkable over an enum class. Use registers array in CPU and introduce 8 new registers + PC. (R0, R1, R2, R3, R4, R5, R6, R7)