/*
 * Problem Statement
 * Given an array of positive numbers and a positive number ‘k,’
 * find the maximum sum of any contiguous subarray of size ‘k’.
 */

//Sliding Window Pattern
#include <cstdlib>
#include <vector>
#include <iostream>
#include <optional>
#include <limits>


namespace {
    using std::vector;
    using std::cout;
    using std::optional;
    auto constexpr newline {'\n'};

    auto max_subarray_k( std::vector<int> const& input, uint32_t const K ) noexcept -> optional<uint32_t> {
        if( input.size() < K ) return std::nullopt;

        auto start = std::size_t {0};
        auto current_sum = std::uint32_t {0};
        auto max_sum = std::numeric_limits<uint32_t>::min();

        for( size_t end = 0; end < input.size(); ++end ) {
            current_sum += input[end];
            if( end >= K - 1 ) {
                max_sum = std::max( max_sum, current_sum );
                current_sum -= input[start];
                start++;
            }
        }
        return std::make_optional(max_sum);
    }
}

auto main() noexcept -> int {
    {
        auto const result = max_subarray_k(vector{1, 2, 1, 3, 0, 1, 1, 9}, 4);
        cout << result.value_or(0) << newline;
    }
    {
        auto const result = max_subarray_k(vector{1,2,1,3,0,1,1,9}, 12);
        cout << result.value_or(0) << newline;
    }
    return EXIT_SUCCESS;
}
