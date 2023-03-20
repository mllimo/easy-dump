#pragma once

#include "component.h"
#include "type_helper.h"
#include "list.h"

#include <algorithm>

namespace easy {

    template <typename Ta, typename Tb>
    class CompareClass : public Component {
    public:
        CompareClass(const std::string& name_a, const std::string& name_b, const Ta& value_a, const Tb& value_b) :
            name_a_(name_a),
            name_b_(name_b),
            value_a_(value_a),
            value_b_(value_b)
        {
        }

        void SetUp(Actions& actions) override
        {

            bool result = Compare(value_a_, value_b_);

            actions.GetStream()
                << name_a_ << '(';
            Print(value_a_, actions.GetStream())
                << ')'
                << (result ? " == " : " != ")
                << name_b_ << '(';
            Print(value_b_, actions.GetStream()) << ')';


            actions.GetComponents().pop_back();
        }

        template <typename T, std::enable_if_t< !IsContainer<T>::value, bool> = false>
        std::ostream& Print(const T& a, std::ostream& os)
        {
            os << a;
            return os;
        }

        template <typename T, std::enable_if_t< IsContainer<T>::value, bool> = true>
        std::ostream& Print(const T& a, std::ostream& os)
        {
            os << '[';
            for (auto it = a.cbegin(); it != a.cend(); ++it) {
                auto next_it = std::next(it, 1);
                os << *it << (next_it == a.cend() ? "" : ", ");
            }
            os << ']';
            return os;
        }

        template <typename Taa = Ta, typename Tbb = Tb, std::enable_if_t< !IsContainer<Taa>::value, bool> = false>
        bool Compare(const Taa& a, const Tbb& b)
        {
            return a == b;
        }

        template <typename Taa = Ta, typename Tbb = Tb, std::enable_if_t< IsContainer<Taa>::value, bool> = true>
        bool Compare(const Taa& a, const Tbb& b)
        {
            return std::equal(a.cbegin(), a.cend(), b.cbegin(), b.cend());
        }

    private:
        std::string name_a_;
        std::string name_b_;
        const Ta& value_a_;
        const Tb& value_b_;
    };

#define Compare(a,b) CompareClass(#a, #b, a, b)
}