# Contributors Document

## Prereqs to being an contributor

- Python 3.8+ (search for "how to install python3 for [insert os]")
- g++11 (search for "how to install g++11 for [insert os]")
- CMake: `pip3 install cmake`
- Conan: `pip3 install conan`

## How to run unit tests

### Install conan

At the root of the repository run:

```
conan install .
```

### Run test

At the root of the repository run:

```
conan create .
```