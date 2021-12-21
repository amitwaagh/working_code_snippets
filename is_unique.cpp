#include <iostream>
#include <cstdlib>
#include <bitset>
#include <string_view>


namespace {
    using std::cout;
    using std::string;
    using std::string_view;
    using std::bitset;

    auto constexpr newline {'\n'};

    auto constexpr is_unique( string_view str ) noexcept -> bool {
        auto char_set = std::bitset<128>(0);
        for(auto const &elem: str) {
            size_t const pos = elem - '!';
            if( char_set[pos] )
                return false;
            char_set.set(pos,true);
        }
        return true;
    }
}

[[nodiscard]]
auto main() noexcept -> std::int32_t {
    using namespace std::string_view_literals;
    {
        auto const result = is_unique("!Aaz"sv);
        cout << (result ? "True!"sv : "False!"sv) << newline;
    }
    {
        auto const result = is_unique("!Aaz!"sv);
        cout << (result ? "True!"sv : "False!"sv) << newline;
    }
    {
        auto const result = is_unique(""sv);
        cout << (result ? "True!"sv : "False!"sv) << newline;
    }
    return EXIT_SUCCESS;
}
