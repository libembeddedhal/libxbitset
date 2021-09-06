#pragma once

#include <bitset>
#include <cinttypes>
#include <limits>
#include <type_traits>

namespace xstd {

struct bitrange {
  uint32_t position;
  uint32_t width;

  template <size_t start, size_t end>
  static constexpr bitrange from() {
    static_assert(end > start, "The start bit must be less then the end bit!");
    return bitrange{.position = start, .width = end - start};
  }

  template <typename T>
  constexpr auto origin_mask() const {
    // Need to use an unsigned version of the type T for the mask to make sure
    // that the shift right doesn't result in a sign extended shift.
    using UnsignedT = typename std::make_unsigned<T>::type;

    // At compile time, generate variable containing all 1s with the size of the
    // target parameter.
    constexpr UnsignedT kFieldOfOnes = std::numeric_limits<UnsignedT>::max();

    // At compile time calculate the number of bits in the target parameter.
    constexpr size_t kTargetWidth = sizeof(T) * 8;

    // Create mask by shifting the set of 1s down so that the number of 1s from
    // bit position 0 is equal to the width parameter.
    UnsignedT bitmask_at_origin =
        static_cast<UnsignedT>(kFieldOfOnes >> (kTargetWidth - width));

    return bitmask_at_origin;
  }

  template <typename T>
  constexpr auto mask() const {
    // Need to use an unsigned version of the type T for the mask to make sure
    // that the shift right doesn't result in a sign extended shift.
    using UnsignedT = decltype(origin_mask<T>());

    return static_cast<UnsignedT>(origin_mask<T>() << position);
  }

  template <typename T>
  constexpr auto inverted_mask() const {
    return ~mask<T>();
  }
};

template <typename T>
class bitset : public std::bitset<sizeof(T) * 8> {
 public:
  static constexpr size_t kBitWidth = sizeof(T) * 8;
  bitset(T initial_value) : std::bitset<kBitWidth>(initial_value) {}

  auto& set(std::size_t pos, bool value = true) {
    static_cast<std::bitset<kBitWidth>*>(this)->set(pos, value);
    return *this;
  }

  auto& reset(std::size_t pos) {
    static_cast<std::bitset<kBitWidth>*>(this)->reset(pos);
    return *this;
  }

  auto& flip(std::size_t pos) {
    static_cast<std::bitset<kBitWidth>*>(this)->flip(pos);
    return *this;
  }

  template <bitrange field, typename U>
  constexpr auto& insert(U value) {
    using NormalT = std::remove_volatile_t<T>;
    auto kBitmask = field.mask<std::remove_volatile_t<T>>();
    auto kInvertedBitmask = field.inverted_mask<std::remove_volatile_t<T>>();

    // Clear width's number of bits in the target value at the bit position
    // specified.
    *this &= kInvertedBitmask;

    // AND value with mask to remove any bits beyond the specified width.
    // Shift masked value into bit position and OR with target value.
    *this |= (static_cast<NormalT>(value) << field.position) & kBitmask;

    return *this;
  }

  template <bitrange mask>
  [[nodiscard]] constexpr auto extract() {
    // Create mask by shifting the set of 1s down so that the number of 1s
    // from bit position 0 is equal to the width parameter.
    return std::bitset<mask.width>(this->to_ullong() >> mask.position);
  }
};

template <typename T>
class bitmanip : public xstd::bitset<T> {
 public:
  bitmanip(T& register_reference)
      : xstd::bitset<T>(register_reference),
        register_reference_(register_reference) {}

  void save() { register_reference_ = static_cast<T>(this->to_ullong()); }

  ~bitmanip() { save(); }

 private:
  T& register_reference_;
};
}  // namespace xstd
