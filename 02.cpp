#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <set>
#include <sstream>
#include <tuple>
#include <vector>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#define ASSERT_EQ(a, b)                                   \
    do                                                    \
    {                                                     \
        __typeof__(a) _a = (a);                           \
        __typeof__(b) _b = (b);                           \
        if (_a != _b)                                     \
        {                                                 \
            std::cout << _a << " != " << _b << std::endl; \
            assert(0);                                    \
        }                                                 \
    } while (0)

#define myprint(arg)                                       \
    do                                                     \
    {                                                      \
        std::cout << "" #arg << " = " << arg << std::endl; \
    } while (0)

using ll = int64_t;

namespace
{

    std::vector<std::tuple<ll, ll>> input_real{
        {1, 14},
        {46452718, 46482242},
        {16, 35},
        {92506028, 92574540},
        {1515128146, 1515174322},
        {56453, 79759},
        {74, 94},
        {798, 971},
        {49, 66},
        {601, 752},
        {3428, 4981},
        {511505, 565011},
        {421819, 510058},
        {877942, 901121},
        {39978, 50500},
        {9494916094, 9494978970},
        {7432846301, 7432888696},
        {204, 252},
        {908772, 990423},
        {21425, 25165},
        {1030, 1285},
        {7685, 9644},
        {419, 568},
        {474396757, 474518094},
        {5252506279, 5252546898},
        {4399342, 4505058},
        {311262290, 311393585},
        {1895, 2772},
        {110695, 150992},
        {567521, 773338},
        {277531, 375437},
        {284, 364},
        {217936, 270837},
        {3365257, 3426031},
        {29828, 36350}};

    decltype(input_real) input_test{
        {11, 22},
        {95, 115},
        {998, 1012},
        {1188511880, 1188511890},
        {222220, 222224},
        {1698522, 1698528},
        {446443, 446449},
        {38593856, 38593862},
        {565653, 565659},
        {824824821, 824824827},
        {2121212118, 2121212124}};
    //    auto &input = input_test;
    auto &input = input_real;

    bool is_invalid1(ll num)
    {
        auto s = std::to_string(num);
        if (s.length() % 2)
        {
            return false;
        }
        auto first = s.substr(0, s.length() / 2);
        auto second = s.substr(s.length() / 2, s.length() / 2);
        return first == second;
    }

    bool is_invalid2(ll num)
    {
        auto s = std::to_string(num);
        for (int snippet_len = 1; snippet_len <= s.length() / 2; snippet_len++)
        {
            if (s.length() % snippet_len)
            {
                continue;
            }
            std::set<std::string> snippets;
            for (ll i = 0; i < s.size(); i += snippet_len)
            {
                snippets.insert(s.substr(i, snippet_len));
            }
            if (snippets.size() == 1)
            {
                return true;
            }
        }
        return false;
    }
}

int main2()
{
    int64_t result0 = 0;
    int64_t result1 = 0;

    assert(is_invalid2(12341234));
    assert(is_invalid2(123123123));
    assert(is_invalid2(1212121212));
    assert(is_invalid2(1111111));

    for (auto [from, to] : input)
    {
        for (ll num = from; num <= to; num++)
        {
            if (is_invalid1(num))
            {
                result0 += num;
            }
            if (is_invalid2(num))
            {
                result1 += num;
            }
        }
    }

    myprint(result0);
    myprint(result1);
    return 0;
}
