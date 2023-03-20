#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include  <type_traits>

#include <EasyDump/h/component.h>

namespace easy {

    class Dump;
    class Actions;

    class SmartActionPtr : public std::unique_ptr<Actions> {
        public:
            using std::unique_ptr<Actions>::unique_ptr;

            SmartActionPtr(std::unique_ptr<Actions> ptr) : std::unique_ptr<Actions>(std::move(ptr)) {}

            template <typename T>
            SmartActionPtr operator<<(const T& element)
            {
                this->get()->operator<<(element);
                return std::move(*this);
            }
    };

    class Dump {
    public:
        Dump(const std::string& path);
        Dump(std::ostream& os = std::cout);


        friend class Actions;

        template <typename T>
        SmartActionPtr operator<<(const T& element)
        {
            SmartActionPtr ptr(std::make_unique<Actions>(*this));
            return ptr << element;;
        }

    private:
        std::ostream& stream_;
        std::ofstream file_;
    };

    class Actions {
    public:
        Actions(Dump& dump) : dump_(dump) {}
        Actions(Actions&&) = default;

        std::ostream& GetStream() { return dump_.stream_; }
        std::vector<std::unique_ptr<Component>>& GetComponents() { return components_; }

        template <typename T>
        void operator<<(const T& element)
        {
            OperatorLS(element, std::is_base_of<Component, T>());
        }


        template <typename T>
        void OperatorLS(const T& element, std::false_type)
        {
            dump_.stream_ << element;
            for (auto& component : components_)
                component->Process(*this);
        }

        template <typename T>
        void OperatorLS(const T& element, std::true_type)
        {
            std::unique_ptr<T> component = std::make_unique<T>(element);
            components_.push_back(std::move(component));
            components_.back()->SetUp(*this);
        }

    private:
        Dump& dump_;
        std::vector<std::unique_ptr<Component>> components_;
    };

}
