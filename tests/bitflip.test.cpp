#include <boost/ut.hpp>
#include <cstdint>
#include <libxbitset/bitset.hpp>

namespace xstd {
boost::ut::suite bitflip_test = [](){
    using namespace boost::ut;

    "bitset::flip() increment position (0)"_test = [](){
        xstd::bitset test_set(0); 
        expect(that % 0x0000'0001 == test_set.flip(0)); 
        expect(that % 0x0000'0003 == test_set.flip(1));
        expect(that % 0x0000'0007 == test_set.flip(2));
    };

    "bitset::flip() alternate (0)"_test = [](){
        xstd::bitset test_set(0); 
        expect(that % 0x0000'0001 == test_set.flip(0)); 
        expect(that % 0x0000'0000 == test_set.flip(0));
        expect(that % 0x0000'0001 == test_set.flip(0));
    };


    "bitset::flip() increment position (1)"_test = [](){
        xstd::bitset test_set(1); 
        expect(that % 0x0000'0000 == test_set.flip(0)); 
        expect(that % 0x0000'0002 == test_set.flip(1));
        expect(that % 0x0000'0006 == test_set.flip(2));
    };

    "bitset::flip() alternate (1)"_test = [](){
        xstd::bitset test_set(1); 
        expect(that % 0x0000'0000 == test_set.flip(0)); 
        expect(that % 0x0000'0001 == test_set.flip(0));
        expect(that % 0x0000'0000 == test_set.flip(0));
    };

    "bitset::flip() increment position (2)"_test = [](){
        xstd::bitset test_set(2);
        expect(that % 0x0000'0003 == test_set.flip(0));
        expect(that % 0x0000'0001 == test_set.flip(1));
        expect(that % 0x0000'0005 == test_set.flip(2));
    };

    "bitset::flip() alternate (2)"_test = [](){
        xstd::bitset test_set(2); 
        expect(that % 0x0000'0003 == test_set.flip(0)); 
        expect(that % 0x0000'0002 == test_set.flip(0));
        expect(that % 0x0000'0003 == test_set.flip(0));
    };

    "bitset::flip() increment position (10)"_test = [](){
        xstd::bitset test_set(0xA);
        expect(that % 0x0000'000B == test_set.flip(0));
        expect(that % 0x0000'0009 == test_set.flip(1));
        expect(that % 0x0000'000D == test_set.flip(2));
    };

    "bitset::flip() alternate (10)"_test = [](){
        xstd::bitset test_set(0xA); 
        expect(that % 0x0000'000B == test_set.flip(0)); 
        expect(that % 0x0000'000A == test_set.flip(0));
        expect(that % 0x0000'000B == test_set.flip(0));
    };

    "bitset::flip() increment position upper half (0x1'FFFF)"_test = [](){
        xstd::bitset test_set(0x1'FFFF);
        expect(that % 0x0000'FFFF == test_set.flip(16));
        expect(that % 0x0002'FFFF == test_set.flip(17));
        expect(that % 0x0006'FFFF == test_set.flip(18));
    };

    "bitset::flip() alternate upper half (0x1'FFFF)"_test = [](){
        xstd::bitset test_set(0x1'FFFF); 
        expect(that % 0x0000'FFFF == test_set.flip(16)); 
        expect(that % 0x0001'FFFF == test_set.flip(16));
        expect(that % 0x0000'FFFF == test_set.flip(16));
    };

    "bitset::flip() increment position lower half full (0xFFFF'FFFF)"_test = [](){
        xstd::bitset test_set(0xFFFF'FFFF);
        expect(that % 0xFFFF'FFFE == test_set.flip(0));
        expect(that % 0xFFFF'FFFC == test_set.flip(1));
        expect(that % 0xFFFF'FFF8 == test_set.flip(2));
    };

    "bitset::flip() alternate lower half full (0xFFFF'FFFF)"_test = [](){
        xstd::bitset test_set(0xFFFF'FFFF); 
        expect(that % 0xFFFF'FFFE == test_set.flip(0)); 
        expect(that % 0xFFFF'FFFF == test_set.flip(0));
        expect(that % 0xFFFF'FFFE == test_set.flip(0));
    };

    "bitset::flip() increment position upper half full (0xFFFF'FFFF)"_test = [](){
        xstd::bitset test_set(0xFFFF'FFFF);
        expect(that % 0xFFFE'FFFF == test_set.flip(16));
        expect(that % 0xFFFC'FFFF == test_set.flip(17));
        expect(that % 0xFFF8'FFFF == test_set.flip(18));
    };

    "bitset::flip() alternate upper half full (0xFFFF'FFFF)"_test = [](){
        xstd::bitset test_set(0xFFFF'FFFF); 
        expect(that % 0xFFFE'FFFF == test_set.flip(16)); 
        expect(that % 0xFFFF'FFFF == test_set.flip(16));
        expect(that % 0xFFFE'FFFF == test_set.flip(16));
    };

    "bitset::flip() set out of range"_test = [](){
        xstd::bitset test_set(0);
        expect(throws<std::out_of_range>([&test_set](){test_set.flip(32);}));
    };
};
}