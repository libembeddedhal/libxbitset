#include <boost/ut.hpp>
#include <cstdint>
#include <libxbitset/bitset.hpp>

namespace xstd {
boost::ut::suite bitset_test = [](){
    using namespace boost::ut;

    "bitset::set() set no change (0)"_test = [](){
        xstd::bitset test_set(0); 
        expect(that % 0x0000'0000 == test_set.set(0,false)); 
    };

    "bitset::set() increment position (0)"_test = [](){
        xstd::bitset test_set(0); 
        expect(that % 0x0000'0001 == test_set.set(0)); 
        expect(that % 0x0000'0003 == test_set.set(1));
        expect(that % 0x0000'0007 == test_set.set(2));
    };

    "bitset::set() increment value (0)"_test = [](){
        xstd::bitset test_set(0);
        expect(that % 0x0000'0000 == test_set.set(0,false));
        expect(that % 0x0000'0001 == test_set.set(0,true));
    };

    "bitset::set() set no change (1)"_test = [](){
        xstd::bitset test_set(1); 
        expect(that % 0x0000'0001 == test_set.set(0)); 
    };

    "bitset::set() increment position (1)"_test = [](){
        xstd::bitset test_set(1); 
        expect(that % 0x0000'0001 == test_set.set(0)); 
        expect(that % 0x0000'0003 == test_set.set(1));
        expect(that % 0x0000'0007 == test_set.set(2));
    };

    "bitset::set() increment value (1)"_test = [](){
        xstd::bitset test_set(1);
        expect(that % 0x0000'0000 == test_set.set(0,false));
        expect(that % 0x0000'0001 == test_set.set(0));
    };

    "bitset::set() set no change (2)"_test = [](){
        xstd::bitset test_set(2);
        expect(that % 0x0000'0002 == test_set.set(0,false));
    };  

    "bitset::set() increment position (2)"_test = [](){
        xstd::bitset test_set(2);
        expect(that % 0x0000'0003 == test_set.set(0));
        expect(that % 0x0000'0003 == test_set.set(1));
        expect(that % 0x0000'0007 == test_set.set(2));
    };

    "bitset::set() increment val (2)"_test = [](){
        xstd::bitset test_set(2);
        expect(that % 0x0000'0002 == test_set.set(0,false));
        expect(that % 0x0000'0003 == test_set.set(0));
    };

    "bitset::set() set no change (10)"_test = [](){
        xstd::bitset test_set(0xA); 
        expect(that % 0x0000'000A == test_set.set(0,false));
    };  

    "bitset::set() increment position (10)"_test = [](){
        xstd::bitset test_set(0xA);
        expect(that % 0x0000'000B == test_set.set(0));
        expect(that % 0x0000'000B == test_set.set(1));
        expect(that % 0x0000'000F == test_set.set(2));
    };

    "bitset::set() increment val (10)"_test = [](){
        xstd::bitset test_set(0xA);
        expect(that % 0x0000'000A == test_set.set(0,false));
        expect(that % 0x0000'000B == test_set.set(0));
    };
 
    "bitset::set() set no change upper half (0x1'FFFF)"_test = [](){
        xstd::bitset test_set(0x1'FFFF); 
        expect(that % 0x0001'FFFF == test_set.set(16));
    };  

     "bitset::set() increment position upper half (0x1'FFFF)"_test = [](){
        xstd::bitset test_set(0x1'FFFF);
        expect(that % 0x0001'FFFF == test_set.set(16));
        expect(that % 0x0003'FFFF == test_set.set(17));
        expect(that % 0x0007'FFFF == test_set.set(18));
    };

    "bitset::set() increment val upper half (0x1'FFFF)"_test = [](){
        xstd::bitset test_set(0x1'FFFF);
        expect(that % 0x0000'FFFF == test_set.set(16,false));
        expect(that % 0x0001'FFFF == test_set.set(16));
    };
};
}