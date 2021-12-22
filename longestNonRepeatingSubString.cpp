//Sliding Window
//LongestSubstring without repeating char.

#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <bitset>
#include <vector>

namespace {
    using std::cout;
    using std::string;
    using std::vector;

    auto constexpr newline {'\n'};

    namespace ver0 {
        class Solution final {
        public:

            [[nodiscard]]
            static auto isRepeated(string const &s, size_t const start, size_t const end) noexcept -> bool {
                auto char_set = std::bitset<128>(0);
                for (size_t i = start; i <= end; ++i) {
                    size_t const pos = s[i] - ' ';
                    if (char_set[pos])
                        return false;
                    char_set.set(pos, true);
                }
                return true;
            }

            [[nodiscard]]
            static auto longestNonRepeatingSubString(string const &input) noexcept -> size_t {
                auto max_len = std::numeric_limits<uint32_t>::min();
                for (size_t i = 0; i < input.size(); ++i) {
                    for (size_t j = i; j < input.size(); ++j) {
                        if (isRepeated(input, i, j)) {
                            max_len = std::max(max_len, unsigned(j - i + 1));
                        }
                    }
                }
                return max_len;
            }
        };
    }
    namespace ver1 {
        class Solution final {
        public:
            static auto longestNonRepeatingSubString(string const& input) noexcept -> size_t {
                auto chars = std::vector<int>(128);
                auto left = size_t{0}, right = size_t{0};

                auto lenOfSubString = std::numeric_limits<size_t>::min();
                while( right < input.length()) {
                    char c = input[right];
                    chars[c]++;

                    while(chars[c] > 1) {
                        char l = input[left];
                        chars[l]--;
                        left++;
                    }

                    lenOfSubString = std::max(lenOfSubString, right - left +1 );
                    ++right;
                }

                return lenOfSubString;
            }
        };
    }
    namespace {
        class Solution final {
        public :
            auto static longestNonRepeatingSubString(string const& str) noexcept -> size_t {
                auto dict = vector(128, -1);
                auto length = std::numeric_limits<size_t>::min();
                auto start = -1;

                for(size_t i = 0; i < str.length(); ++i) {
                    auto const ch = str[i];
                    
                    if(dict[ch] > start) {
                        start = dict[ch];
                    }
                    
                    dict[ch] = i;

                    length = std::max( length, i - start );
                }

                return length;
            }
        };
    }

}

[[nodiscard]]
auto main() noexcept -> int {
    using namespace std::string_literals;
    cout << Solution::longestNonRepeatingSubString("abcdef"s) << newline;
    cout << Solution::longestNonRepeatingSubString("abcabcd"s) << newline;
    return EXIT_SUCCESS;
}
