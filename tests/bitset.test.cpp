#include <boost/ut.hpp>
#include <cstdint>
#include <libxbitset/bitset.hpp>

namespace xstd {
boost::ut::suite bitset_test = [](){
    using namespace boost::ut;

    "bitset::set() set no change 1"_test = [](){
        xstd::bitset test_set(1); 
        //maintain intial value for odd number using set(0,true)
        expect(that % 0x0000'0001 == test_set.set(0,true)); 
        expect(that % 0x0000'0001 == test_set.set(0,true));
    };

    "bitset::set() increment position 1"_test = [](){
        xstd::bitset test_set(1); 
        expect(that % 0x0000'0001 == test_set.set(0,true)); 
        expect(that % 0x0000'0003 == test_set.set(1));
        expect(that % 0x0000'0007 == test_set.set(2));
        expect(that % 0x0000'000F == test_set.set(3));
    };

    "bitset::set() increment value 1"_test = [](){
        xstd::bitset test_set(1);
        expect(that % 0x0000'0000 == test_set.set(0,false));
        expect(that % 0x0000'0001 == test_set.set(0,true));
    };

    "bitset::set() set no change 2"_test = [](){
        xstd::bitset test_set(2);
        //maintain initial value for even number using set(0,false)
        expect(that % 0x0000'0002 == test_set.set(0,false));
        expect(that % 0x0000'0002 == test_set.set(0,false));
    };  

    "bitset::set() increment position 2"_test = [](){
        xstd::bitset test_set(2);
        expect(that % 0x0000'0003 == test_set.set(0,true));
        expect(that % 0x0000'0003 == test_set.set(1));
        expect(that % 0x0000'0007 == test_set.set(2));
        expect(that % 0x0000'000F == test_set.set(3));
    };

    "bitset::set() increment val 2"_test = [](){
        xstd::bitset test_set(2);
        expect(that % 0x0000'0002 == test_set.set(0,false));
        expect(that % 0x0000'0003 == test_set.set(0,true));
    };

    "bitset::set() set no change 3"_test = [](){
        xstd::bitset test_set(3); 
        //maintain intial value for odd number using set(0,true)
        expect(that % 0x0000'0003 == test_set.set(0,true));
        expect(that % 0x0000'0003 == test_set.set(0,true));
    };  

     "bitset::set() increment position 3"_test = [](){
        xstd::bitset test_set(3);
        expect(that % 0x0000'0003 == test_set.set(0,true));
        expect(that % 0x0000'0003 == test_set.set(1));
        expect(that % 0x0000'0007 == test_set.set(2));
        expect(that % 0x0000'000F == test_set.set(3));
    };

    "bitset::set() increment val 3"_test = [](){
        xstd::bitset test_set(3);
        expect(that % 0x0000'0002 == test_set.set(0,false));
        expect(that % 0x0000'0003 == test_set.set(0,true));
    };

    "bitset::set() set no change 4"_test = [](){
        xstd::bitset test_set(4); 
        //maintain initial value for even number using set(0,false)
        expect(that % 0x0000'0004 == test_set.set(0,false));
        expect(that % 0x0000'0004 == test_set.set(0,false));
    };  

    "bitset::set() increment position 4"_test = [](){
        xstd::bitset test_set(4);
        expect(that % 0x0000'0005 == test_set.set(0,true));
        expect(that % 0x0000'0007 == test_set.set(1));
        expect(that % 0x0000'0007 == test_set.set(2));
        expect(that % 0x0000'000F == test_set.set(3));
    };

    "bitset::set() increment val 4"_test = [](){
        xstd::bitset test_set(4);
        expect(that % 0x0000'0004 == test_set.set(0,false));
        expect(that % 0x0000'0005 == test_set.set(0,true));
    };

    "bitset::set() set no change 5"_test = [](){
        xstd::bitset test_set(5); 
        //maintain intial value for odd number using set(0,true)
        expect(that % 0x0000'0005 == test_set.set(0,true));
        expect(that % 0x0000'0005 == test_set.set(0,true));
    };  

     "bitset::set() increment position 5"_test = [](){
        xstd::bitset test_set(5);
        expect(that % 0x0000'0005 == test_set.set(0,true));
        expect(that % 0x0000'0007 == test_set.set(1));
        expect(that % 0x0000'0007 == test_set.set(2));
        expect(that % 0x0000'000F == test_set.set(3));
    };

    "bitset::set() increment val 5"_test = [](){
        xstd::bitset test_set(5);
        expect(that % 0x0000'0004 == test_set.set(0,false));
        expect(that % 0x0000'0005 == test_set.set(0,true));
    };

    "bitset::set() set no change 10"_test = [](){
        xstd::bitset test_set(0xA); 
        //maintain initial value for even number using set(0,false)
        expect(that % 0x0000'000A == test_set.set(0,false));
        expect(that % 0x0000'000A == test_set.set(0,false));
    };  

    "bitset::set() increment position 10"_test = [](){
        xstd::bitset test_set(0xA);
        expect(that % 0x0000'000B == test_set.set(0,true));
        expect(that % 0x0000'000B == test_set.set(1));
        expect(that % 0x0000'000F == test_set.set(2));
        expect(that % 0x0000'000F == test_set.set(3));
    };

    "bitset::set() increment val 10"_test = [](){
        xstd::bitset test_set(0xA);
        expect(that % 0x0000'000A == test_set.set(0,false));
        expect(that % 0x0000'000B == test_set.set(0,true));
    };

    "bitset::set() set no change 11"_test = [](){
        xstd::bitset test_set(0xB); 
        //maintain intial value for odd number using set(0,true)
        expect(that % 0x0000'000B == test_set.set(0,true));
        expect(that % 0x0000'000B == test_set.set(0,true));
    };  

     "bitset::set() increment position 11"_test = [](){
        xstd::bitset test_set(0xB);
        expect(that % 0x0000'000B == test_set.set(0,true));
        expect(that % 0x0000'000B == test_set.set(1));
        expect(that % 0x0000'000F == test_set.set(2));
        expect(that % 0x0000'000F == test_set.set(3));
    };

    "bitset::set() increment val 11"_test = [](){
        xstd::bitset test_set(0xB);
        expect(that % 0x0000'000A == test_set.set(0,false));
        expect(that % 0x0000'000B == test_set.set(0,true));
    };
 
    "bitset::set() set no change UH1"_test = [](){
        xstd::bitset test_set(0x1'FFFF); 
        //maintain intial value for odd number using set(0,true)
        expect(that % 0x0001'FFFF == test_set.set(16,true));
        expect(that % 0x0001'FFFF == test_set.set(16,true));
    };  

     "bitset::set() increment position UH1"_test = [](){
        xstd::bitset test_set(0x1'FFFF);
        expect(that % 0x0001'FFFF == test_set.set(16,true));
        expect(that % 0x0003'FFFF == test_set.set(17));
        expect(that % 0x0007'FFFF == test_set.set(18));
        expect(that % 0x000F'FFFF == test_set.set(19));
    };

    "bitset::set() increment val UH1"_test = [](){
        xstd::bitset test_set(0x1'FFFF);
        expect(that % 0x0000'FFFF == test_set.set(16,false));
        expect(that % 0x0001'FFFF == test_set.set(16,true));
    };

};
}