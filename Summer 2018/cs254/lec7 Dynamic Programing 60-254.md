# Dynamic Programming

## Coin change problem

- different denominations: 1, 5, 10, 25
- amount wanted: 52
- can be solved many different ways: 
    - 2 * 0.01 + 2 * 0.25 
    - etc...
- *new version:* find the **fewest** number of coins...
    - *greedy* approach maximized the largest denominations
    - doesn't alway work
    - 31 (if 5 isn't available) 
        - *greedy* 1 * 25 + 6 * 1 = 7 coins
        - *better* 3 * 10 + 1 * 1 = 4 coins
    - *divide and conquor*: exponential time. 
        - end up performing same calculations many times over
    - *Dynamic Programming*: 
        - stores results of calculations in an array so that problems only need ot be solved once.  

## Longest Increasing Subsequence