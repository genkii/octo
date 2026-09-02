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

- [ ] Add memory bounds checks