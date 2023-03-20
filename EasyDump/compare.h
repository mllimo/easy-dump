#pragma once

#include "component.h"
#include "type_helper.h"

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
                << name_a_
                << (result ? " == " : " != ")
                << name_b_;

            actions.GetComponents().pop_back();
        }



        template <typename Taa = Ta, typename Tbb = Tb, std::enable_if_t< !IsContainer<Taa>::value, bool> = false>
        bool Compare(const Taa& a, const Tbb& b)
        {
            return a == b;
        }

        template <typename Taa = Ta, typename Tbb = Tb, std::enable_if_t< IsContainer<Taa>::value, bool> = true>
        bool Compare(const Taa& a, const Tbb& b)
        {
            return std::equal(a.begin(), a.end(), b.begin(), b.end());
        }

    private:
        std::string name_a_;
        std::string name_b_;
        const Ta& value_a_;
        const Tb& value_b_;
    };

#define Compare(a,b) CompareClass(#a, #b, a, b)
}