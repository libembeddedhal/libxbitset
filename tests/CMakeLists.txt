find_package(ut)

add_executable(libxbitset.test.exe
libxbitset/bitset.test.cpp
test/main.test.cpp)

target_link_libraries(libxbitset.test.exe
                      PRIVATE
                      libxbitset
                      ut)
