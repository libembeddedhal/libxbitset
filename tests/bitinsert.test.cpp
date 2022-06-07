#include <boost/ut.hpp>
#include <cstdint>
#include <libxbitset/bitset.hpp>

namespace xstd {
boost::ut::suite bitinsert_test = [](){
    using namespace boost::ut;

    "bitset::insert() bitrange object position increment (0)"_test = [](){
        xstd::bitset test(0xFFFF'FFFF);
        constexpr xstd::bitrange bitr_obj{0,16};
        expect(that % 0xFFFF'ABCD == test.insert<bitr_obj>(0xABCD));
    };

    "bitset::insert() bitrange object position increment (1)"_test = [](){
        xstd::bitset test(0xFFFF'FFFF);
        constexpr xstd::bitrange bitr_obj{1,16};
        expect(that % 0xFFFF'579B == test.insert<bitr_obj>(0xABCD));
    };

    "bitset::insert() bitrange object position increment (16)"_test = [](){
        xstd::bitset test(0xFFFF'FFFF);
        constexpr xstd::bitrange bitr_obj{16,16};
        expect(that % 0xABCD'FFFF == test.insert<bitr_obj>(0xABCD));
    };

    "bitset::insert() bitrange object position increment out of range"_test = [](){
        xstd::bitset test(0xFFFF'FFFF);
        constexpr xstd::bitrange bitr_obj{27,16};
        expect(that % 0x6FFF'FFFF == test.insert<bitr_obj>(0xABCD));
    };

    "bitset::insert single input from() position increment (0)"_test = [](){
        xstd::bitset test(0);
        static constexpr auto bitr_obj = xstd::bitrange::from<0>();
        expect(that % 0x0000'0001 == test.insert<bitr_obj>(0xFFFF));
    };

    "bitset::insert single input from() position increment (1)"_test = [](){
        xstd::bitset test(0);
        static constexpr auto bitr_obj = xstd::bitrange::from<1>();
        expect(that % 0x0000'0002 == test.insert<bitr_obj>(0xFFFF));
    };

    "bitset::insert single input from() position increment (16)"_test = [](){
        xstd::bitset test(0);
        static constexpr auto bitr_obj = xstd::bitrange::from<16>();
        expect(that % 0x0001'0000 == test.insert<bitr_obj>(0xFFFF));
    };

    "bitset::insert double input from() position increment (0)"_test = [](){
        xstd::bitset test(0xFFFF'FFFF);
        static constexpr auto bitr_obj = xstd::bitrange::from<0,15>();
        expect(that % 0xFFFF'ABCD == test.insert<bitr_obj>(0xABCD));
    }; 

    "bitset::insert double input from() position increment (1)"_test = [](){
        xstd::bitset test(0xFFFF'FFFF);
        static constexpr auto bitr_obj = xstd::bitrange::from<1,15>();
        expect(that % 0xFFFF'579B == test.insert<bitr_obj>(0xABCD));
    };  

    "bitset::insert double input from() position increment (16)"_test = [](){
        xstd::bitset test(0xFFFF'FFFF);
        static constexpr auto bitr_obj = xstd::bitrange::from<16,31>();
        expect(that % 0xABCD'FFFF == test.insert<bitr_obj>(0xABCD));
    };

    "bitset::insert double input from() position increment out of range"_test = [](){
        xstd::bitset test(0xFFFF'FFFF);
        static constexpr auto bitr_obj = xstd::bitrange::from<27,42>();
        expect(that % 0x6FFF'FFFF == test.insert<bitr_obj>(0xABCD));
    };
};
}