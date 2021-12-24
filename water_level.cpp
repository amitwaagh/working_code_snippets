namespace {
    using std::cout;
    using std::vector;
    using std::unordered_set;
    auto constexpr nl {'\n'};

    class Solution {
    public:
        auto static max_area(vector<uint32_t> const & height) noexcept -> uint32_t {
            auto right = height.size() - 1;
            decltype(right) left = 0;

            auto max_water_level = std::numeric_limits<uint32_t>::min();

            while( left < right ) {
                auto const min = std::min(height[left], height[right]);
                auto const current_water_level = static_cast<uint32_t>((right - left) * min);
                max_water_level = std::max( max_water_level, current_water_level );

                while( height[left]  <= min && left < right ) left++;
                while( height[right] <= min && left < right ) right--;
            }

            return max_water_level;
        }
    };

}


[[nodiscard]]
auto main() noexcept -> int {
    using namespace std::string_view_literals;
    cout << ((Solution::max_area(vector<uint32_t>{ 1, 8, 6, 2, 5, 4, 8, 3, 7} ) == 49) ? "Pass"sv : "Fail"sv) << nl;
    cout << ((Solution::max_area(vector<uint32_t>{ 1, 2, 6, 2, 5, 4, 8, 3, 7} ) == 36) ? "Pass"sv : "Fail"sv) << nl;

    return EXIT_SUCCESS;
}
