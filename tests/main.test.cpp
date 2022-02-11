#include <boost/ut.hpp>
#include <cstdint>
#include <libxbitset/bitset.hpp>

using namespace boost::ut;

struct dummy_register
{
  volatile uint64_t CTRL1;
  volatile uint64_t CTRL2;
};

dummy_register memory{};
dummy_register* reg = &memory;

int main()
{
  static constexpr auto intensity =
    xstd::bitrange{ .position = 16, .width = 8 };
  static constexpr auto clock_divider = xstd::bitrange::from<42, 50>();
  xstd::bitmanip(reg->CTRL1)
    .insert<intensity>(7)
    .set(4)
    .reset(0)
    .insert<clock_divider>(3);

  expect(that % 0x0000'0C00'0007'0010 == reg->CTRL1);
}
