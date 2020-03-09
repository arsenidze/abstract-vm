#include <stack>

template<typename T, typename Container = std::deque<T>>
class IterableStack : public std::stack<T, Container>
{
    using std::stack<T, Container>::c;
public:
    auto begin() { return std::begin(c); }
    auto end() { return std::end(c); }

    auto begin() const { return std::begin(c); }
    auto end() const { return std::end(c); }

    auto rbegin() const { return std::rbegin(c); }
    auto rend() const { return std::rend(c); }
};
