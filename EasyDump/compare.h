#pragma once

#include "component.h"

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
            actions.GetStream()
                << name_a_ << '(' << value_a_ << ')'
                << (value_a_ == value_b_ ? " == " : " != ")
                << name_b_ << '(' << value_b_ << ')';

            actions.GetComponents().pop_back();
        }

    private:
        std::string name_a_;
        std::string name_b_;
        const Ta& value_a_;
        const Tb& value_b_;
    };

#define Compare(a,b) CompareClass(#a, #b, a, b)
}