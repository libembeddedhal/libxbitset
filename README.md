# libxbitset

Single header only C++20 extension of std::bitset that includes multi-bit
insertion and extraction and more.

## Features

- `xstd::bitset` adopts and inherits all of the traits and capabilities of
  `std::bitset`.
- Express compile time bit field ranges using the `xstd::bitrange` class.
- Compile time errors when bit ranges are outside of the range of the bitfield.
- Manipulate volatile integral types (registers) using the `xstd::bitmanip`
  class, which has performance as good or better than hand written alternatives.

### Caveats

- Currently, the bit range for insertion and extraction must be known at compile
  time.

## Installation

### Direct inclusion

Simply download and place the `include/libxbitset/bitset.hpp` file in your C++
project's include directory.

### Using conan (not available yet)

If you use conan, you can add `libxbitset/0.0.1` to your `conanfile.txt`.

### Using CMake FetchContent

TBD

## [API]()

For the detailed API for everything please see the Doxygen page found
[here]().

## Usage & Examples

Note that in every location where `xstd::bitmanip` is used, `xstd::bitset` can
also be used.
The difference between them is as follows:

- `xstd::bitmanip` saves a copy and reference to the integral passed to it vs
  `xstd::bitset` which only saves a copy.
- `xstd::bitmanip` supports `save()` which saves the bitset contents to the
  reference.
- `xstd::bitmanip` supports `update()` which reads and overwrites the contents
  of the bitset with the reference value.
- `xstd::bitmanip` will save its contents to the reference on destruction.

### Register bit manipulation

```C++
// Example register to act as a substitute for a hardware peripherals' register
// file
struct ExampleRegister
{
  volatile uint64_t CTRL1 = 0;
  volatile uint64_t CTRL2 = 0;
};

// Creating a global instance of ExampleRegister to be manipulated
ExampleRegister memory{};

// Created a pointer to the memory as this is what will be done on most/all
// system, where memory is accessed by address literals directly.
ExampleRegister* reg = &memory;

int main()
{
  // Create a compile time xstd::bitrange that starts at bit position 16 and is
  // 8-bits in length.
  constexpr auto intensity = xstd::bitrange{ .position = 16, .width = 8 };

  // Create another compile time bit range but this time using the ::from()
  // factory function.
  constexpr auto clock_divider = xstd::bitrange::from<42, 50>();

  // Create a temporary instance of xstd::bitmanip and have it manipulate
  // reg->CTRL1.
  //
  // The constructor copies the register contents and manipulates that and not
  // the register directly as volatile register access is slower than CPU
  // register or cache access.
  xstd::bitmanip(reg->CTRL1)
    .insert<intensity>(7)      // Insert 7 into the `intensity` location
    .set(4)                    // Set bit 4 to 1
    .reset(0)                  // Set bit 0 to 0
    .insert<clock_divider>(3); // Insert 3 into into `clock_divider` location
  // On destruction, the changes are saved to the register

  // This assertion should be correct
  assert(0x0000'0C00'0007'0010 == reg->CTRL1);
}
```

### Polling

Unlike the manipulation case where you modify the registers, this action can be
done in a temporary, when you poll a register's bits, you will always need to
request the data from the register each time.

```C++
// Using a single template argument for the ::from() factory will create a bit
// range for width 1 bit and position 5.
constexpr auto system_ready = xstd::bitrange::from<5>();

// Here a new bitmanip object is constructed each iteration of the while loop
while(xstd::bitmanip(reg->STATUS).test(system_read)) {
  continue;
}
```

```C++
// Using a single template argument for the ::from() factory will create a bit
// range for width 1 bit and position 5.
constexpr auto system_ready = xstd::bitrange::from<5>();

// Here we create a bitmanip object and save the object into a status (lvalue)
// variable.
auto status = xstd::bitmanip(reg->STATUS);

// In order to ensure that you are reading from actual current value of the
// register, and not the cached copy you NEED to run the `update()` function,
// before calling test.
while(status.update().test(system_read)) {
  continue;
}
```

Both of these examples of polling are equivalent in performance.

### Saving Registers Early

When you create a `xstd::bitmanip` lvalue reference (variable),

```C++
// Create a xstd::bitmanip control object
xstd::bitmanip control(reg->CTRL2);

// Lets say that this sets some
control.set(5);

// In order for the 5th bit to be saved to the actual register, you'll need to
// use the `save()` method.
control.save();
while(control.update().test(1)) {
  continue;
}
```

## Benchmarks

Generally, you will see that at reasonable optimization levels (above O0) most
compilers eliminate the majority of the code and leave only the few required
instructions needed to change the registers. Constructors and destructors get
eliminated and almost all function calls are eliminated.

TBD

