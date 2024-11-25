# LBYARCH MP
Creators: Ian Matthew Yanga and EemKey

## Execution Time

Input row size = **10**

Average Time (in C, ms) = 0.000000 ms

Average Time (in x86-64, ms) = 0.000000 ms


Input row size = 100

Average Time (in C, ms) = 0.000000 ms

Average Time (in x86-64, ms) = 0.000000 ms


Input row size = 1000

Average Time (in C, ms) = 0.033333 ms

Average Time (in x86-64, ms) = 0.000000 ms


Input row size = 10000

Average Time (in C, ms) = 0.466667 ms

Average Time (in x86-64, ms) = 0.033333 ms

## Observations and Analysis
For Small Input Sizes (10, 100):

Both the C implementation and the x86-64 assembly implementation take effectively 0.000000 ms.
The input size is too small for the time measurement to capture meaningful differences.

For Moderate Input Sizes (1000, 10000):

The C implementation begins to show noticeable execution times:

1000 rows: 0.033333 ms.

10000 rows: 0.466667 ms.

The x86-64 implementation, however, remains significantly faster:

1000 rows: Still 0.000000 ms.

10000 rows: Only 0.033333 ms, 14x faster than C.

## Screenshots

![](images/terminal%201.png)
![](images/terminal%202.png)
