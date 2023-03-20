#pragma once

#include <type_traits>

namespace easy {
    template<class C>
    struct IsContainer {
    private:
        template<class D>
        static constexpr auto hasValueType() -> decltype(typename D::value_type(), std::true_type()) {
            return {};
        }

        template<class D>
        static constexpr auto hasIteratorAlias() -> decltype(typename D::iterator(), std::true_type()) {
            return {};
        }

        template<class D>
        static constexpr std::false_type hasIteratorAlias(...) {
            return {};
        }

        template<class D>
        static constexpr auto hasConstIteratorAlias() -> decltype(typename D::const_iterator(), std::true_type()) {
            return {};
        }

        template<class D>
        static constexpr auto hasBegin() -> decltype(decltype(std::begin(std::declval<D>())){}, std::true_type()) {
            return {};
        }

        template<class D>
        static constexpr std::false_type hasBegin(...) {
            return {};
        }

        template<class D>
        static constexpr auto hasEnd() -> decltype(decltype(std::end(std::declval<D>())){}, std::true_type()) {
            return {};
        }

        template<class D>
        static constexpr std::false_type hasEnd(...) {
            return {};
        }

        template<class D>
        static constexpr std::false_type hasConstIteratorAlias(...) {
            return {};
        }

        template<class D>
        static constexpr std::false_type hasValueType(...) {
            return {};
        }

    public:
        constexpr static bool value = hasValueType<C>().value &&
            hasIteratorAlias<C>().value &&
            hasConstIteratorAlias<C>().value &&
            hasBegin<C>().value &&
            hasEnd<C>().value;

        constexpr bool operator()() const {
            return value;
        }
    };
}