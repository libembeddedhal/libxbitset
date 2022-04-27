#include <boost/ut.hpp>
#include <cstdint>
#include <libxbitset/bitset.hpp>

namespace embed {
boost::ut::suite bitset_test[](){
    using namespace boost::ut;

//TEST SET() FOR INITIAL VALUE OF 0
    "bitset::set()_set_no_change_0"_test = [](){
        bitset<int> test_set(0); 
        //maintain initial value for even number using set(0,0)
        expect(that % 0000'0000 == test_set.set(0,0));
        expect(that % 0000'0000 == test_set.set(0,0));
        expect(that % 0000'0000 == test_set.set(0,0));
        expect(that % 0000'0000 == test_set.set(0,0));
        expect(that % 0000'0000 == test_set.set(0,0));
        expect(that % 0000'0000 == test_set.set(0,0));
    };  

    "bitset::set()_increment_position_0"_test = [](){
        bitset<int> test_set(0);
        //incrementing position with same value
        expect(that % 0000'0001 == test_set.set(0,1));
        expect(that % 0000'0002 == test_set.set(1,1));
        expect(that % 0000'0004 == test_set.set(2,1));
        expect(that % 0000'0008 == test_set.set(3,1));
        expect(that % 0000'0010 == test_set.set(4,1));
        expect(that % 0000'0020 == test_set.set(5,1));
    };

    "bitset::set()_increment_val_0"_test = [](){
        bitset<int> test_set(0);
        //incrementing value with same position
        expect(that % 0000'0000 == test_set.set(0,0));
        expect(that % 0000'0001 == test_set.set(0,1));
        expect(that % 0000'0001 == test_set.set(0,2));
        expect(that % 0000'0001 == test_set.set(0,3));
        expect(that % 0000'0001 == test_set.set(0,4));
        expect(that % 0000'0001 == test_set.set(0,5));
    };

    //TEST SET() FOR INITIAL VALUE OF 1
    "bitset::set()_set_no_change_1"_test = [](){
        bitset<int> test_set(1); 
        //maintain intial value for odd number using set(0,1)
        expect(that % 0000'0001 == test_set.set(0,1)); 
        expect(that % 0000'0001 == test_set.set(0,1));
        expect(that % 0000'0001 == test_set.set(0,1));
        expect(that % 0000'0001 == test_set.set(0,1));
        expect(that % 0000'0001 == test_set.set(0,1));
        expect(that % 0000'0001 == test_set.set(0,1));
    };

    "bitset::set()_increment_position_1"_test = [](){
        bitset<int> test_set(1);
        //incrementing position with same value
        expect(that % 0000'0001 == test_set.set(0,1)); 
        expect(that % 0000'0003 == test_set.set(1,1));
        expect(that % 0000'0005 == test_set.set(2,1));
        expect(that % 0000'0009 == test_set.set(3,1));
        expect(that % 0000'0011 == test_set.set(4,1));
        expect(that % 0000'0021 == test_set.set(5,1));
    };

    "bitset::set()_increment_value_1"_test = [](){
        bitset<int> test_set(1);
        //incrementing value with same position
        expect(that % 0000'0000 == test_set.set(0,0));
        expect(that % 0000'0001 == test_set.set(0,1));
        expect(that % 0000'0001 == test_set.set(0,2));
        expect(that % 0000'0001 == test_set.set(0,3));
        expect(that % 0000'0001 == test_set.set(0,4));
        expect(that % 0000'0001 == test_set.set(0,5));
    };

    //TEST SET() FOR INITIAL VALUE OF 2
    "bitset::set()_set_no_change_2"_test = [](){
        bitset<int> test_set(2); 
        //maintain initial value for even number using set(0,0)
        expect(that % 0000'0002 == test_set.set(0,0));
        expect(that % 0000'0002 == test_set.set(0,0));
        expect(that % 0000'0002 == test_set.set(0,0));
        expect(that % 0000'0002 == test_set.set(0,0));
        expect(that % 0000'0002 == test_set.set(0,0));
        expect(that % 0000'0002 == test_set.set(0,0));
    };  

    "bitset::set()_increment_position_2"_test = [](){
        bitset<int> test_set(2);
        //incrementing position with same value
        expect(that % 0000'0003 == test_set.set(0,1));
        expect(that % 0000'0002 == test_set.set(1,1));
        expect(that % 0000'0006 == test_set.set(2,1));
        expect(that % 0000'000A == test_set.set(3,1));
        expect(that % 0000'0012 == test_set.set(4,1));
        expect(that % 0000'0022 == test_set.set(5,1));
    };

    "bitset::set()_increment_val_2"_test = [](){
        bitset<int> test_set(2);
        //incrementing value with same position
        expect(that % 0000'0002 == test_set.set(0,0));
        expect(that % 0000'0003 == test_set.set(0,1));
        expect(that % 0000'0003 == test_set.set(0,2));
        expect(that % 0000'0003 == test_set.set(0,3));
        expect(that % 0000'0003 == test_set.set(0,4));
        expect(that % 0000'0003 == test_set.set(0,5));
    };

    //TEST SET() FOR INITIAL VALUE OF 3
    "bitset::set()_set_no_change_3"_test = [](){
        bitset<int> test_set(3); 
        //maintain intial value for odd number using set(0,1)
        expect(that % 0000'0003 == test_set.set(0,1));
        expect(that % 0000'0003 == test_set.set(0,1));
        expect(that % 0000'0003 == test_set.set(0,1));
        expect(that % 0000'0003 == test_set.set(0,1));
        expect(that % 0000'0003 == test_set.set(0,1));
        expect(that % 0000'0003 == test_set.set(0,1));
    };  

     "bitset::set()_increment_position_3"_test = [](){
        bitset<int> test_set(3);
        //incrementing position with same value
        expect(that % 0000'0003 == test_set.set(0,1));
        expect(that % 0000'0003 == test_set.set(1,1));
        expect(that % 0000'0007 == test_set.set(2,1));
        expect(that % 0000'000B == test_set.set(3,1));
        expect(that % 0000'0013 == test_set.set(4,1));
        expect(that % 0000'0023 == test_set.set(5,1));
    };

    "bitset::set()_increment_val_3"_test = [](){
        bitset<int> test_set(3);
        //incrementing value with same position
        expect(that % 0000'0002 == test_set.set(0,0));
        expect(that % 0000'0003 == test_set.set(0,1));
        expect(that % 0000'0003 == test_set.set(0,2));
        expect(that % 0000'0003 == test_set.set(0,3));
        expect(that % 0000'0003 == test_set.set(0,4));
        expect(that % 0000'0003 == test_set.set(0,5));
    };

    //TEST SET() FOR INITIAL VALUE OF 4
    "bitset::set()_set_no_change_4"_test = [](){
        bitset<int> test_set(4); 
        //maintain initial value for even number using set(0,0)
        expect(that % 0000'0004 == test_set.set(0,0));
        expect(that % 0000'0004 == test_set.set(0,0));
        expect(that % 0000'0004 == test_set.set(0,0));
        expect(that % 0000'0004 == test_set.set(0,0));
        expect(that % 0000'0004 == test_set.set(0,0));
        expect(that % 0000'0004 == test_set.set(0,0));
    };  

    "bitset::set()_increment_position_4"_test = [](){
        bitset<int> test_set(4);
        //incrementing position with same value
        expect(that % 0000'0005 == test_set.set(0,1));
        expect(that % 0000'0006 == test_set.set(1,1));
        expect(that % 0000'0004 == test_set.set(2,1));
        expect(that % 0000'000C == test_set.set(3,1));
        expect(that % 0000'0014 == test_set.set(4,1));
        expect(that % 0000'0024 == test_set.set(5,1));
    };

    "bitset::set()_increment_val_4"_test = [](){
        bitset<int> test_set(4);
        //incrementing value with same position
        expect(that % 0000'0004 == test_set.set(0,0));
        expect(that % 0000'0005 == test_set.set(0,1));
        expect(that % 0000'0005 == test_set.set(0,2));
        expect(that % 0000'0005 == test_set.set(0,3));
        expect(that % 0000'0005 == test_set.set(0,4));
        expect(that % 0000'0005 == test_set.set(0,5));
    };

    //TEST SET() FOR INITIAL VALUE OF 5
    "bitset::set()_set_no_change_5"_test = [](){
        bitset<int> test_set(5); 
        //maintain intial value for odd number using set(0,1)
        expect(that % 0000'0005 == test_set.set(0,1));
        expect(that % 0000'0005 == test_set.set(0,1));
        expect(that % 0000'0005 == test_set.set(0,1));
        expect(that % 0000'0005 == test_set.set(0,1));
        expect(that % 0000'0005 == test_set.set(0,1));
        expect(that % 0000'0005 == test_set.set(0,1));
    };  

     "bitset::set()_increment_position_5"_test = [](){
        bitset<int> test_set(5);
        //incrementing position with same value
        expect(that % 0000'0005 == test_set.set(0,1));
        expect(that % 0000'0007 == test_set.set(1,1));
        expect(that % 0000'0005 == test_set.set(2,1));
        expect(that % 0000'000D == test_set.set(3,1));
        expect(that % 0000'0015 == test_set.set(4,1));
        expect(that % 0000'0025 == test_set.set(5,1));
    };

    "bitset::set()_increment_val_5"_test = [](){
        bitset<int> test_set(5);
        //incrementing value with same position
        expect(that % 0000'0004 == test_set.set(0,0));
        expect(that % 0000'0005 == test_set.set(0,1));
        expect(that % 0000'0005 == test_set.set(0,2));
        expect(that % 0000'0005 == test_set.set(0,3));
        expect(that % 0000'0005 == test_set.set(0,4));
        expect(that % 0000'0005 == test_set.set(0,5));
    };

    //TEST SET() FOR INITIAL VALUE OF 10
    "bitset::set()_set_no_change_10"_test = [](){
        bitset<int> test_set(0xA); 
        //maintain initial value for even number using set(0,0)
        expect(that % 0000'000A == test_set.set(0,0));
        expect(that % 0000'000A == test_set.set(0,0));
        expect(that % 0000'000A == test_set.set(0,0));
        expect(that % 0000'000A == test_set.set(0,0));
        expect(that % 0000'000A == test_set.set(0,0));
        expect(that % 0000'000A == test_set.set(0,0));
    };  

    "bitset::set()_increment_position_10"_test = [](){
        bitset<int> test_set(0xA);
        //incrementing position with same value
        expect(that % 0000'000B == test_set.set(0,1));
        expect(that % 0000'000A == test_set.set(1,1));
        expect(that % 0000'000E == test_set.set(2,1));
        expect(that % 0000'000A == test_set.set(3,1));
        expect(that % 0000'001A == test_set.set(4,1));
        expect(that % 0000'002A == test_set.set(5,1));
    };

    "bitset::set()_increment_val_10"_test = [](){
        bitset<int> test_set(0xA);
        //incrementing value with same position
        expect(that % 0000'000A == test_set.set(0,0));
        expect(that % 0000'000B == test_set.set(0,1));
        expect(that % 0000'000B == test_set.set(0,2));
        expect(that % 0000'000B == test_set.set(0,3));
        expect(that % 0000'000B == test_set.set(0,4));
        expect(that % 0000'000B == test_set.set(0,5));
    };

    //TEST SET() FOR INITIAL VALUE OF 11
    "bitset::set()_set_no_change_11"_test = [](){
        bitset<int> test_set(0xB); 
        //maintain intial value for odd number using set(0,1)
        expect(that % 0000'000B == test_set.set(0,1));
        expect(that % 0000'000B == test_set.set(0,1));
        expect(that % 0000'000B == test_set.set(0,1));
        expect(that % 0000'000B == test_set.set(0,1));
        expect(that % 0000'000B == test_set.set(0,1));
        expect(that % 0000'000B == test_set.set(0,1));
    };  

     "bitset::set()_increment_position_11"_test = [](){
        bitset<int> test_set(0xB);
        //incrementing position with same value
        expect(that % 0000'000B == test_set.set(0,1));
        expect(that % 0000'000B == test_set.set(1,1));
        expect(that % 0000'000F == test_set.set(2,1));
        expect(that % 0000'000B == test_set.set(3,1));
        expect(that % 0000'001B == test_set.set(4,1));
        expect(that % 0000'002B == test_set.set(5,1));
    };

    "bitset::set()_increment_val_11"_test = [](){
        bitset<int> test_set(0xB);
        //incrementing value with same position
        expect(that % 0000'000A == test_set.set(0,0));
        expect(that % 0000'000B == test_set.set(0,1));
        expect(that % 0000'000B == test_set.set(0,2));
        expect(that % 0000'000B == test_set.set(0,3));
        expect(that % 0000'000B == test_set.set(0,4));
        expect(that % 0000'000B == test_set.set(0,5));
    };

    //TEST SET() FOR UPPER HALF 
    "bitset::set()_set_no_change_UH1"_test = [](){
        bitset<int> test_set(0x1'FFFF); 
        //maintain intial value for odd number using set(0,1)
        expect(that % 0001'FFFF == test_set.set(16,1));
        expect(that % 0001'FFFF == test_set.set(16,1));
        expect(that % 0001'FFFF == test_set.set(16,1));
        expect(that % 0001'FFFF == test_set.set(16,1));
        expect(that % 0001'FFFF == test_set.set(16,1));
        expect(that % 0001'FFFF == test_set.set(16,1));
    };  

     "bitset::set()_increment_position_UH1"_test = [](){
        bitset<int> test_set(0x1'FFFF);
        //incrementing position with same value
        expect(that % 0001'FFFF == test_set.set(16,1));
        expect(that % 0003'FFFF == test_set.set(17,1));
        expect(that % 0005'FFFF == test_set.set(18,1));
        expect(that % 0009'FFFF == test_set.set(19,1));
        expect(that % 0011'FFFF == test_set.set(20,1));
        expect(that % 0021'FFFF == test_set.set(21,1));
    };

    "bitset::set()_increment_val_UH1"_test = [](){
        bitset<int> test_set(0x1'FFFF);
        //incrementing value with same position
        expect(that % 0000'FFFF == test_set.set(16,0));
        expect(that % 0001'FFFF == test_set.set(16,1));
        expect(that % 0001'FFFF == test_set.set(16,2));
        expect(that % 0001'FFFF == test_set.set(16,3));
        expect(that % 0001'FFFF == test_set.set(16,4));
        expect(that % 0001'FFFF == test_set.set(16,5));
    };

}
}