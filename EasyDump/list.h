#pragma once

#include "component.h"

namespace easy {
    template <typename Container>
    class List : public Component {
    public:
        List(const Container& container) :
            container_(container)
        {
        }

        void SetUp(Actions& actions) override
        {

            actions.GetStream() << '[';
            for (auto it = container_.cbegin(); it != container_.cend(); ++it) {
                auto next_it = std::next(it, 1);
                actions.GetStream() << *it << (next_it == container_.cend() ? "" : ", ");
            }
            actions.GetStream() << ']';
            actions.GetComponents().erase(actions.GetComponents().begin() + actions.GetComponents().size() - 1);
        }
        
    private:
        const Container& container_;
    };
}