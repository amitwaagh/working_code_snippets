namespace {
    using std::cout;
    using std::string;
    using std::vector;
    auto constexpr nl {'\n'};

    class PairWithTargetSum final {
    public:
        auto static find(int const target, vector<int> const& input) noexcept -> std::pair<int, int> {
            auto right = input.size() - 1;
            decltype(right) left = 0;

            while( left < right ) {
                auto const current_sum = input[left] + input[right];
                if( current_sum == target ) {
                    return std::make_pair(left, right);
                }

                if( target > current_sum )
                    ++left;
                else
                    --right;

            }
            return std::make_pair(-1, -1);
        }
    };

}

[[nodiscard]]
auto main() noexcept -> int {
    {
        auto const[first, second] = PairWithTargetSum::find(8, vector{0, 1, 2, 3, 4, 5, 8});
        cout << first << " | " << second << nl;
    }
    {
        auto const[first, second] = PairWithTargetSum::find(11, vector{0, 1, 2, 3, 4, 5, 8});
        cout << first << " | " << second << nl;
    }
    return EXIT_SUCCESS;
}
