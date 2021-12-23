namespace {
    using std::cout;
    using std::string;
    using std::vector;
    auto constexpr nl {'\n'};

    class RemoveDuplicates final {
    public:
        auto static remove(vector<int>& input) noexcept -> size_t {
            auto nextNonDuplicate = size_t {1};
            for(size_t next = 1; next < input.size(); ++next) {
                if( input[nextNonDuplicate - 1] != input[next] ) {
                    input[nextNonDuplicate] = input[next];
                    ++nextNonDuplicate;
                }
            }
            return nextNonDuplicate;
        }
    };

}

auto print_vec(auto const& vec) noexcept -> void {
    cout << "vector = { ";
    for(auto const elem:vec) {
        cout << elem << " | ";
    }
    cout << " }" << nl;
}

[[nodiscard]]
auto main() noexcept -> int {
    auto input = vector {1,2,3,3,4,4,4,5,6,6};
    cout << RemoveDuplicates::remove( input ) << nl;
    print_vec(input);
    return EXIT_SUCCESS;
}
