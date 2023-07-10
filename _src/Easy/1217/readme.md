# **📌 DCP-1217** 

Good morning! Here's your coding interview problem for today.

This problem was asked by Pivotal.

Write an algorithm that finds the total number of set bits in all integers between `1` and `N`.

# **⭐ Solution**

Here i make use of right shift operator `>>` and bitwise-and operator `&`. when the `1` is bitwise-anded with `num` we gets the result as `1`, this counts as 1 implying that we encountered a set-bit and iteratively the `num` is right-shifted until the `num` becomes `0`. At last, the `count` is obtained.  