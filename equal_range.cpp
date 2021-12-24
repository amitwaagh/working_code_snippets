namespace {
    using std::cout;
    using std::vector;
    auto constexpr nl {'\n'};

    class Solution {
    public:
        auto static search_range(vector<int> const& nums, int const target) noexcept -> vector<int> {

            auto const present = std::binary_search(cbegin(nums), cend(nums), target);

            if( !present ) return vector<int>{ -1, -1 };

            auto const start = std::lower_bound(cbegin(nums), cend(nums), target);
            auto const end   = std::upper_bound(cbegin(nums), cend(nums), target);

            //As std::distance return type is long but result MUST be int
            auto const first = static_cast<int>(std::distance(cbegin(nums), start));
            auto const last  = static_cast<int>(std::distance(cbegin(nums), end) - 1);
            return vector<int>{ first, last };

        }
        
        auto static equal_range(vector<int> const& nums, int const target) noexcept -> vector<int> {
            auto const present = std::binary_search(cbegin(nums), cend(nums), target);
            if (!present) return vector<int>{-1, -1};

            auto const [start, end] = std::equal_range(cbegin(nums), cend(nums), target);
            auto const first = static_cast<int>(std::distance(cbegin(nums), start));
            auto const last  = static_cast<int>(std::distance(cbegin(nums), end) - 1);
            return vector<int>{ first, last };
        }
    };

}


[[nodiscard]]
auto main() noexcept -> int {
    {
        auto const range = vector<std::int32_t>{1, 2, 3, 3, 3, 5, 6, 7, 8};
        auto const result =Solution::search_range(range, 3);
        std::copy(cbegin(result),cend(result), std::ostream_iterator<int>(cout," "));
    }
    cout << nl;
    {
        auto const range = vector { 5, 7, 7, 8, 8, 10};
        auto const result = Solution::search_range(range, 6);
        std::copy(cbegin(result),cend(result), std::ostream_iterator<int>(cout," "));
    }
    cout << nl;
    {
        auto const range = vector { 5, 7, 7, 8, 8, 10};
        auto const result = Solution::equal_range(range, 7);
        std::copy(cbegin(result),cend(result), std::ostream_iterator<int>(cout," "));
    }
    return EXIT_SUCCESS;
}
