#include <boost/ut.hpp>
#include <cstdint>
#include <libxbitset/bitset.hpp>

namespace embed {
boost::ut::suite bitset_test = [](){
    using namespace boost::ut;

    //TEST SET() FOR INITIAL VALUE OF 1
    "bitset::set()_set_no_change_1"_test = [](){
        xstd::bitset<int> test_set(1); 
        //maintain intial value for odd number using set(0,true)
        expect(that % 0x0000'0001 == test_set.set(0,true)); 
        expect(that % 0x0000'0001 == test_set.set(0,true));
    };

    "bitset::set()_increment_position_1"_test = [](){
        xstd::bitset<int> test_set(1);
        //incrementing position with same value
        expect(that % 0x0000'0001 == test_set.set(0,true)); 
        expect(that % 0x0000'0003 == test_set.set(1,true));
        expect(that % 0x0000'0007 == test_set.set(2,true));
        expect(that % 0x0000'000F == test_set.set(3,true));
    };

    "bitset::set()_increment_value_1"_test = [](){
        xstd::bitset<int> test_set(1);
        //incrementing value with same position
        expect(that % 0x0000'0000 == test_set.set(0,false));
        expect(that % 0x0000'0001 == test_set.set(0,true));
    };

    //TEST SET() FOR INITIAL VALUE OF 2
    "bitset::set()_set_no_change_2"_test = [](){
        xstd::bitset<int> test_set(2); 
        //maintain initial value for even number using set(0,false)
        expect(that % 0x0000'0002 == test_set.set(0,false));
        expect(that % 0x0000'0002 == test_set.set(0,false));
    };  

    "bitset::set()_increment_position_2"_test = [](){
        xstd::bitset<int> test_set(2);
        //incrementing position with same value
        expect(that % 0x0000'0003 == test_set.set(0,true));
        expect(that % 0x0000'0003 == test_set.set(1,true));
        expect(that % 0x0000'0007 == test_set.set(2,true));
        expect(that % 0x0000'000F == test_set.set(3,true));
    };

    "bitset::set()_increment_val_2"_test = [](){
        xstd::bitset<int> test_set(2);
        //incrementing value with same position
        expect(that % 0x0000'0002 == test_set.set(0,false));
        expect(that % 0x0000'0003 == test_set.set(0,true));
    };

    //TEST SET() FOR INITIAL VALUE OF 3
    "bitset::set()_set_no_change_3"_test = [](){
        xstd::bitset<int> test_set(3); 
        //maintain intial value for odd number using set(0,true)
        expect(that % 0x0000'0003 == test_set.set(0,true));
        expect(that % 0x0000'0003 == test_set.set(0,true));
    };  

     "bitset::set()_increment_position_3"_test = [](){
        xstd::bitset<int> test_set(3);
        //incrementing position with same value
        expect(that % 0x0000'0003 == test_set.set(0,true));
        expect(that % 0x0000'0003 == test_set.set(1,true));
        expect(that % 0x0000'0007 == test_set.set(2,true));
        expect(that % 0x0000'000F == test_set.set(3,true));
    };

    "bitset::set()_increment_val_3"_test = [](){
        xstd::bitset<int> test_set(3);
        //incrementing value with same position
        expect(that % 0x0000'0002 == test_set.set(0,false));
        expect(that % 0x0000'0003 == test_set.set(0,true));
    };

    //TEST SET() FOR INITIAL VALUE OF 4
    "bitset::set()_set_no_change_4"_test = [](){
        xstd::bitset<int> test_set(4); 
        //maintain initial value for even number using set(0,false)
        expect(that % 0x0000'0004 == test_set.set(0,false));
        expect(that % 0x0000'0004 == test_set.set(0,false));
    };  

    "bitset::set()_increment_position_4"_test = [](){
        xstd::bitset<int> test_set(4);
        //incrementing position with same value
        expect(that % 0x0000'0005 == test_set.set(0,true));
        expect(that % 0x0000'0007 == test_set.set(1,true));
        expect(that % 0x0000'0007 == test_set.set(2,true));
        expect(that % 0x0000'000F == test_set.set(3,true));
    };

    "bitset::set()_increment_val_4"_test = [](){
        xstd::bitset<int> test_set(4);
        //incrementing value with same position
        expect(that % 0x0000'0004 == test_set.set(0,false));
        expect(that % 0x0000'0005 == test_set.set(0,true));
    };

    //TEST SET() FOR INITIAL VALUE OF 5
    "bitset::set()_set_no_change_5"_test = [](){
        xstd::bitset<int> test_set(5); 
        //maintain intial value for odd number using set(0,true)
        expect(that % 0x0000'0005 == test_set.set(0,true));
        expect(that % 0x0000'0005 == test_set.set(0,true));
    };  

     "bitset::set()_increment_position_5"_test = [](){
        xstd::bitset<int> test_set(5);
        //incrementing position with same value
        expect(that % 0x0000'0005 == test_set.set(0,true));
        expect(that % 0x0000'0007 == test_set.set(1,true));
        expect(that % 0x0000'0007 == test_set.set(2,true));
        expect(that % 0x0000'000F == test_set.set(3,true));
    };

    "bitset::set()_increment_val_5"_test = [](){
        xstd::bitset<int> test_set(5);
        //incrementing value with same position
        expect(that % 0x0000'0004 == test_set.set(0,false));
        expect(that % 0x0000'0005 == test_set.set(0,true));
    };

    //TEST SET() FOR INITIAL VALUE OF 10
    "bitset::set()_set_no_change_10"_test = [](){
        xstd::bitset<int> test_set(0xA); 
        //maintain initial value for even number using set(0,false)
        expect(that % 0x0000'000A == test_set.set(0,false));
        expect(that % 0x0000'000A == test_set.set(0,false));
    };  

    "bitset::set()_increment_position_10"_test = [](){
        xstd::bitset<int> test_set(0xA);
        //incrementing position with same value
        expect(that % 0x0000'000B == test_set.set(0,true));
        expect(that % 0x0000'000B == test_set.set(1,true));
        expect(that % 0x0000'000F == test_set.set(2,true));
        expect(that % 0x0000'000F == test_set.set(3,true));
    };

    "bitset::set()_increment_val_10"_test = [](){
        xstd::bitset<int> test_set(0xA);
        //incrementing value with same position
        expect(that % 0x0000'000A == test_set.set(0,false));
        expect(that % 0x0000'000B == test_set.set(0,true));
    };

    //TEST SET() FOR INITIAL VALUE OF 11
    "bitset::set()_set_no_change_11"_test = [](){
        xstd::bitset<int> test_set(0xB); 
        //maintain intial value for odd number using set(0,true)
        expect(that % 0x0000'000B == test_set.set(0,true));
        expect(that % 0x0000'000B == test_set.set(0,true));
    };  

     "bitset::set()_increment_position_11"_test = [](){
        xstd::bitset<int> test_set(0xB);
        //incrementing position with same value
        expect(that % 0x0000'000B == test_set.set(0,true));
        expect(that % 0x0000'000B == test_set.set(1,true));
        expect(that % 0x0000'000F == test_set.set(2,true));
        expect(that % 0x0000'000F == test_set.set(3,true));
    };

    "bitset::set()_increment_val_11"_test = [](){
        xstd::bitset<int> test_set(0xB);
        //incrementing value with same position
        expect(that % 0x0000'000A == test_set.set(0,false));
        expect(that % 0x0000'000B == test_set.set(0,true));
    };

    //TEST SET() FOR UPPER HALF 
    "bitset::set()_set_no_change_UH1"_test = [](){
        xstd::bitset<int> test_set(0x1'FFFF); 
        //maintain intial value for odd number using set(0,true)
        expect(that % 0x0001'FFFF == test_set.set(16,true));
        expect(that % 0x0001'FFFF == test_set.set(16,true));
    };  

     "bitset::set()_increment_position_UH1"_test = [](){
        xstd::bitset<int> test_set(0x1'FFFF);
        //incrementing position with same value
        expect(that % 0x0001'FFFF == test_set.set(16,true));
        expect(that % 0x0003'FFFF == test_set.set(17,true));
        expect(that % 0x0007'FFFF == test_set.set(18,true));
        expect(that % 0x000F'FFFF == test_set.set(19,true));
    };

    "bitset::set()_increment_val_UH1"_test = [](){
        xstd::bitset<int> test_set(0x1'FFFF);
        //incrementing value with same position
        expect(that % 0x0000'FFFF == test_set.set(16,false));
        expect(that % 0x0001'FFFF == test_set.set(16,true));
    };

};
}