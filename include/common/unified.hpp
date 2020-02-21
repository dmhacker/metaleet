#ifndef METALEET_CONSTANTS_HPP
#define METALEET_CONSTANTS_HPP

#include <metal.hpp>

namespace metaleet {

using ZERO = metal::number<0>;
using ONE = metal::number<1>;
using TWO = metal::number<2>;
using PLUS = metal::number<'+'>;
using MINUS = metal::number<'-'>;
using MULT = metal::number<'*'>;
using DIV = metal::number<'/'>;

// lfirst :: list<a> -> a

template <class seq>
using lfirst = metal::at<seq, ZERO>;

// lsecond :: list<a> -> a

template <class seq>
using lsecond = metal::at<seq, ONE>;

// append_at :: list<list<a>> -> number -> a -> list<list<a>>

template <class rows, class ridx, class val>
using append_at = metal::insert<metal::erase<rows, ridx, metal::inc<ridx>>, ridx, metal::append<metal::at<rows, ridx>, val>>;


// pop1 :: list<a> -> list<a>

template <class stack>
using pop1 = metal::take<stack, metal::dec<metal::size<stack>>>;

// pop2 :: list<a> -> list<a>

template <class stack>
using pop2 = pop1<pop1<stack>>;

// geq :: number -> number -> bool

template <class n1, class n2>
using geq = metal::not_<metal::less<n1, n2>>;

// sqr :: number -> number

template <class n>
using sqr = metal::mul<n, n>;

// average :: number -> number -> number
template <class left, class right>
using average = metal::div<metal::add<left, right>, TWO>;

}

#endif
