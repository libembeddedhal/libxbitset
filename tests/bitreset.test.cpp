#include <boost/ut.hpp>
#include <cstdint>
#include <libxbitset/bitset.hpp>

namespace xstd {
boost::ut::suite bitreset_test = [](){
    using namespace boost::ut;

    "bitset::reset() increment position (0)"_test = [](){
        xstd::bitset test_set(0); 
        expect(that % 0x0000'0000 == test_set.reset(0)); 
        expect(that % 0x0000'0000 == test_set.reset(1));
        expect(that % 0x0000'0000 == test_set.reset(2));
    };

    "bitset::reset() increment position (1)"_test = [](){
        xstd::bitset test_set(1); 
        expect(that % 0x0000'0000 == test_set.reset(0)); 
        expect(that % 0x0000'0000 == test_set.reset(1));
        expect(that % 0x0000'0000 == test_set.reset(2));
    };

    "bitset::reset() increment position (2)"_test = [](){
        xstd::bitset test_set(2);
        expect(that % 0x0000'0002 == test_set.reset(0));
        expect(that % 0x0000'0000 == test_set.reset(1));
        expect(that % 0x0000'0000 == test_set.reset(2));
    };

    "bitset::reset() increment position (10)"_test = [](){
        xstd::bitset test_set(0xA);
        expect(that % 0x0000'000A == test_set.reset(0));
        expect(that % 0x0000'0008 == test_set.reset(1));
        expect(that % 0x0000'0008 == test_set.reset(2));
    };

    "bitset::reset() increment position upper half (0x1'FFFF)"_test = [](){
        xstd::bitset test_set(0x1'FFFF);
        expect(that % 0x0000'FFFF == test_set.reset(16));
        expect(that % 0x0000'FFFF == test_set.reset(17));
        expect(that % 0x0000'FFFF == test_set.reset(18));
    };

    "bitset::reset() increment position lower half full (0xFFFF'FFFF)"_test = [](){
        xstd::bitset test_set(0xFFFF'FFFF);
        expect(that % 0xFFFF'FFFE == test_set.reset(0));
        expect(that % 0xFFFF'FFFC == test_set.reset(1));
        expect(that % 0xFFFF'FFF8 == test_set.reset(2));
    };

    "bitset::reset() increment position upper half full (0xFFFF'FFFF)"_test = [](){
        xstd::bitset test_set(0xFFFF'FFFF);
        expect(that % 0xFFFE'FFFF == test_set.reset(16));
        expect(that % 0xFFFC'FFFF == test_set.reset(17));
        expect(that % 0xFFF8'FFFF == test_set.reset(18));
    };

    "bitset::reset() set out of range"_test = [](){
        xstd::bitset test_set(0);
        expect(throws<std::out_of_range>([&test_set](){test_set.reset(32);}));
    };
};
}