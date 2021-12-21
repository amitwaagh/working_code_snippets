
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

namespace {
    using std::cout;
    using std::string;
    using std::vector;
   
    auto constexpr newline {'\n'};

    template <class InputIt, class ForwardIt, class BinOp>
    auto for_each_token(InputIt first, InputIt last,
                        ForwardIt s_first, ForwardIt s_last,
                        BinOp binary_op)
        noexcept ( true )
        -> void {

        while( first != last ) {
            auto const pos = std::find_first_of(first, last, s_first, s_last);
            binary_op( first, pos );
            if( pos == last ) break;
            first = std::next( pos );
        }

    }

    auto split( string const& str,
                string const& delims = " ",
                bool const skip_empty = true )
        noexcept ( true )
        -> vector<string> {

        vector<string> output;
        for_each_token(cbegin(str), cend(str),
                       cbegin(delims), cend(delims),
                       [&result, skip_empty](auto const begin, auto const end) {
                        if( begin != end || !skip_empty) {
                            output.emplace_back(begin, end);
                        }
                      });

        return output;

    }

    auto print_vec( auto const& seq_container,
                    char const sep = '|' )
        noexcept ( true )
        -> void {
        cout << " vector = { ";
        for( auto const& elem : seq_container ) {
            cout << elem << " " << sep << " ";
        }
        cout << "} " << newline;
    }
}

auto main( ) noexcept -> decltype( EXIT_SUCCESS ) {
    auto constexpr delims { " \n\t\r\f" };
    auto result = split( "Hello \r welcome \t to \f splitting \n string challenge", delims );
    print_vec( result );
    return EXIT_SUCCESS;
}
