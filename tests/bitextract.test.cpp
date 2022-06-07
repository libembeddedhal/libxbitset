#include <boost/ut.hpp>
#include <cstdint>
#include <libxbitset/bitset.hpp>

namespace xstd {
boost::ut::suite bitextract_test = [](){
    using namespace boost::ut;

    "bitset::extract() bitrange object width increment (0)"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        constexpr xstd::bitrange bitr_obj{0,1};
        expect(that % 0x1 == test.extract<bitr_obj>());
    };

    "bitset::extract() bitrange object width increment (4)"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        constexpr xstd::bitrange bitr_obj{0,4};
        expect(that % 0xD == test.extract<bitr_obj>());
    };

    "bitset::extract() bitrange object width increment (8)"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        constexpr xstd::bitrange bitr_obj{0,8};
        expect(that % 0xCD == test.extract<bitr_obj>());
    };

    "bitset::extract() bitrange object position and width increment (4,4)"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        constexpr xstd::bitrange bitr_obj{4,4};
        expect(that % 0xC == test.extract<bitr_obj>());
    };

    "bitset::extract() bitrange object position and width increment (8,8)"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        constexpr xstd::bitrange bitr_obj{8,8};
        expect(that % 0xAB == test.extract<bitr_obj>());
    };

    "bitset::extract() bitrange object upper half"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        constexpr xstd::bitrange bitr_obj{16,8};
        expect(that % 0x23 == test.extract<bitr_obj>());
    };

    "bitset::extract() bitrange object out of range"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        constexpr xstd::bitrange bitr_obj{24,16};
        expect(that % 0x0001 == test.extract<bitr_obj>());
    };

    "bitset::extract() single input from position increment(0)"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        static constexpr auto bitr_obj = xstd::bitrange::from<0>();
        expect(that % 0x1 == test.extract<bitr_obj>());
    };

    "bitset::extract() single input from position increment(4)"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        static constexpr auto bitr_obj = xstd::bitrange::from<4>();
        expect(that % 0x0 == test.extract<bitr_obj>());
    };

    "bitset::extract() single input from position increment(8)"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        static constexpr auto bitr_obj = xstd::bitrange::from<8>();
        expect(that % 0x1 == test.extract<bitr_obj>());
    };

    "bitset::extract() double input from() width increment (0)"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        static constexpr auto bitr_obj = xstd::bitrange::from<0,1>();
        expect(that % 0x1 == test.extract<bitr_obj>());
    };

    "bitset::extract() double input from() width increment (4)"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        static constexpr auto bitr_obj = xstd::bitrange::from<0,3>();
        expect(that % 0xD == test.extract<bitr_obj>());
    };

    "bitset::extract() double input from() width increment (8)"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        static constexpr auto bitr_obj = xstd::bitrange::from<0,7>();
        expect(that % 0xCD == test.extract<bitr_obj>());
    };

    "bitset::extract() double input from() position and width increment (4,7)"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        static constexpr auto bitr_obj = xstd::bitrange::from<4,7>();
        expect(that % 0xC == test.extract<bitr_obj>());
    };

    "bitset::extract() double input from() position and width increment (8,15)"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        static constexpr auto bitr_obj = xstd::bitrange::from<8,15>();
        expect(that % 0xAB == test.extract<bitr_obj>());
    };

    "bitset::extract() double input from() upper half"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        static constexpr auto bitr_obj = xstd::bitrange::from<16,23>();
        expect(that % 0x23 == test.extract<bitr_obj>());
    };

    "bitset::extract() double input from() out of range"_test = [](){
        xstd::bitset test(0x0123'ABCD);
        static constexpr auto bitr_obj = xstd::bitrange::from<24,39>();
        expect(that % 0x0001 == test.extract<bitr_obj>());
    };
};
}