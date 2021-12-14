#pragma once

#if (__cplusplus > 199711L) || (_MSVC_LANG > 199711L)
    #define NONSTD_STATIC_ASSERT(condition, message) static_assert(condition, message)
#else
    #define NONSTD_STATIC_ASSERT(condition, message)
#endif

namespace detail
{
    template<typename A, typename B, bool condition>
    struct conditional
    {};

    template<typename A, typename B>
    struct conditional<A, B, true>
    {
        typedef A type;
    };

    template<typename A, typename B>
    struct conditional<A, B, false>
    {
        typedef B type;
    };

    template<typename A, typename B, typename C, typename D, typename E, int size>
    struct same_size
    {
        using type = typename conditional<A, typename conditional<B, typename conditional<C, typename conditional<D, E, sizeof(D) == size>::type, sizeof(C) == size>::type, sizeof(B) == size>::type, sizeof(A) == size>::type;
        NONSTD_STATIC_ASSERT(sizeof(type) == size, "Invalid type size");
    };
}

namespace nonstd
{
    typedef detail::same_size<signed char, signed short, signed int, signed long, signed long long, 1>::type int8_t;
    typedef detail::same_size<signed char, signed short, signed int, signed long, signed long long, 2>::type int16_t;
    typedef detail::same_size<signed char, signed short, signed int, signed long, signed long long, 4>::type int32_t;
    typedef detail::same_size<signed char, signed short, signed int, signed long, signed long long, 8>::type int64_t;

    typedef detail::same_size<unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long, 1>::type uint8_t;
    typedef detail::same_size<unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long, 2>::type uint16_t;
    typedef detail::same_size<unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long, 4>::type uint32_t;
    typedef detail::same_size<unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long, 8>::type uint64_t;

    NONSTD_STATIC_ASSERT(sizeof(int8_t) == 1, "sizeof(int8_t) != 1");
    NONSTD_STATIC_ASSERT(sizeof(int16_t) == 2, "sizeof(int16_t) != 2");
    NONSTD_STATIC_ASSERT(sizeof(int32_t) == 4, "sizeof(int32_t) != 4");
    NONSTD_STATIC_ASSERT(sizeof(int64_t) == 8, "sizeof(int64_t) != 8");
    
    NONSTD_STATIC_ASSERT(sizeof(uint8_t) == 1, "sizeof(uint8_t) != 1");
    NONSTD_STATIC_ASSERT(sizeof(uint16_t) == 2, "sizeof(uint16_t) != 2");
    NONSTD_STATIC_ASSERT(sizeof(uint32_t) == 4, "sizeof(uint32_t) != 4");
    NONSTD_STATIC_ASSERT(sizeof(uint64_t) == 8, "sizeof(uint64_t) != 8");

    template<int pointer_size>
    struct pointer_types;

    template<>
    struct pointer_types<4>
    {
        typedef int intptr_t;
        typedef unsigned int uintptr_t;
    };

    template<>
    struct pointer_types<8>
    {
        typedef long long intptr_t;
        typedef unsigned long long uintptr_t;
    };

    typedef detail::same_size<signed char, signed short, signed int, signed long, signed long long, (int)sizeof(void*)>::type intptr_t;
    typedef detail::same_size<unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long, (int)sizeof(void*)>::type uintptr_t;

    NONSTD_STATIC_ASSERT(sizeof(intptr_t) == (int)sizeof(void*), "sizeof(int8_t) != 1");
    NONSTD_STATIC_ASSERT(sizeof(uintptr_t) == (int)sizeof(void*), "sizeof(int8_t) != 1");
}
