## json-test-asan

This is a simple program to benchmark nlohmann JSON parsing with and without address sanitizer (ASAN) enabled.

Usage:

```
make
./json-test-asan
./json-tests-no-asan
```

To test in Docker:

Ubuntu:

```
docker build -f Dockerfile.ubuntu -t json-test-asan-ubu .
docker run -it --rm json-test-asan-ubu
make
./json-test-asan
```

Debian:

```
docker build -f Dockerfile.debian -t json-test-asan-deb .
docker run -it --rm json-test-asan-deb
make
./json-test-asan
```
