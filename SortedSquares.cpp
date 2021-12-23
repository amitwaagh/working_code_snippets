namespace {
    using std::cout;
    using std::string;
    using std::vector;
    auto constexpr nl {'\n'};
    
    class Solution {
    public:
        [[nodiscard]] 
        [[maybe_unused]]
        auto static sortSquaresUsingLoops(vector<int> const& nums) noexcept -> vector<int> {
            auto left = nums.size() - nums.size();
            auto right = nums.size() - 1;
            auto back_inserter = nums.size() - 1;

            auto result = vector<int>(nums.size());

            while( left <= right ) {
                auto const sqr_left = nums[left] * nums[left];
                auto const sqr_right = nums[right] * nums[right];

                if(sqr_left >= sqr_right) {
                    result[back_inserter--] = sqr_left;
                    left++;
                } else {
                    result[back_inserter--] = sqr_right;
                    right--;
                }
            }
            return result;
        }

        [[nodiscard]] 
        [[maybe_unused]]
        auto static sortSquaresWithSTL(vector<int> const& nums) noexcept -> vector<int> {
            auto result = vector<int>(nums.size());
            auto constexpr square = [](auto const num) { return num * num; };
            std::ranges::transform(cbegin(nums), cend(nums), begin(result), square);
            std::ranges::sort(result);
            return result;
        }
    };

}



[[nodiscard]]
auto main() noexcept -> int {
    {
        auto input = vector { -3, -1, 2, 3, 4 };
        cout << (Solution::sortSquaresUsingLoops(input) == Solution::sortSquaresWithSTL(input)) << nl;
    }
    return EXIT_SUCCESS;
}
