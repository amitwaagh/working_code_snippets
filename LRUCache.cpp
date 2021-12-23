#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <list>
#include <unordered_map>

namespace {

    using std::cout;
    using std::string;
    using std::vector;

    auto constexpr nl {'\n'};
    
    template<typename Key = uint32_t, typename Value = int32_t>
    class LRUCache {
        using Capacity = uint32_t;
    public:
        explicit LRUCache(Capacity capacity) noexcept : capacity(capacity) {}

        [[nodiscard]]
        auto get(Key const key) noexcept -> std::optional<Value> {
            if(cache.find(key) != cache.end()) {
                touch(key);
                return std::make_optional(cache[key]);
            }
            return std::nullopt;
        }

        auto set(Key const key, Value const value) noexcept -> void {
            touch(key);
            cache[key] = value;
        }

    private:
        auto touch(Key const key) noexcept -> void {
            if(tracker.find(key) != tracker.end()) {
                recent.erase(tracker[key]);
            } else if (recent.size() >= capacity) {
                auto lru_key = recent.back();
                recent.pop_back();
                tracker.erase(lru_key);
                cache.erase(lru_key);
            }

            recent.push_front(key);
            tracker[key] = recent.begin();
        }

    private:
        Capacity capacity {};
        std::list<Key> recent;
        std::unordered_map<Key, Value> cache;
        std::unordered_map<Key, typename std::list<Key>::iterator> tracker;
    };
}

[[nodiscard]]
auto main() noexcept -> int {
    {
        LRUCache test(2);
    }

    {
        using Level = std::uint32_t;
        using Price = double;
        LRUCache<Level, Price> price_level(4);
        price_level.set(1, 20.1);
        price_level.set(2, 30.2);
        price_level.set(3, 40.3);
        auto result = price_level.get(1);
        price_level.set(4, 50.4);
        price_level.set(5, 60.5);

        cout << price_level.get(5).value_or(-1.0) << nl;
        cout << price_level.get(2).value_or(-1.0) << nl;
    }

    {
        using Symbols = std::string;
        using Qty = std::uint16_t;
        using namespace std::string_literals;
        LRUCache<Symbols, Qty> symbols(4);
        symbols.set("apple"s, 1000);
        cout << symbols.get("apple"s).value_or(0) << nl;
    }
    
    return EXIT_SUCCESS;
}
