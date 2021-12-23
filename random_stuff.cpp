namespace {
    using std::cout;
    using std::string;
    using std::vector;
    auto constexpr nl {'\n'};
}

template<typename Container>
auto constexpr get_input = [](auto const count) noexcept -> Container {
    auto output = Container(count);
    auto const begin_counter = -count/2;

    std::iota(begin(output), end(output), begin_counter);
    auto rd         = std::random_device();
    auto generator  = std::mt19937(rd());

    std::ranges::shuffle(output, generator);
    return output;
};


[[nodiscard]]
auto main() noexcept -> int {
    {
        using vec_int = vector<std::int32_t>;
        auto const result = get_input<vec_int>(100);

        cout << "Min Element : " << std::ranges::min(result) << nl;
        cout << "Max Element : " << std::ranges::max(result) << nl;
        auto const [ min, max ] = std::ranges::minmax(result);
        cout << "Diff : " << max - min << nl;

        cout << "vector = { ";
        std::copy(cbegin(result), cend(result), std::ostream_iterator<std::int32_t>(cout, " "));
        cout << "}" << nl;

    }
    return EXIT_SUCCESS;
}
