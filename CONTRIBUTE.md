# Contributors Document

## Prereqs to being an contributor

- Python 3.8+ (search for "how to install python3 for [insert os]")
- g++11 (search for "how to install g++11 for [insert os]")
- CMake: `pip3 install cmake`
- Conan: `pip3 install conan`

## How to run unit tests

### Install conan

At the root of the repository

```
conan install .
```

### Run test

Building the test binary:

```
cd tests
mkdir build
cd build
conan install ..
cmake ..
make
```

Running the test:

```
./test
```
