# Carrot Eaters Problem Solution

- [Question 1 information](https://progolymp.se/2023/skolkval/kval23.pdf)

- [Question 1 test cases](https://progolymp.se/2023/skolkval/kvalsvar23.pdf)

This README explains the solution implemented in `main.cpp` for the problem where Tor and his mother eat carrots from a bowl with certain rules.

## Overview

The problem involves Tor and his mother eating carrots from a bowl containing exactly 40 carrots. They eat uninterrupted until the bowl is empty. The solution must account for the number of seconds it takes for each to eat a carrot and handle the special case where neither will take the last carrot if they both are ready to eat it at the same time.

## main.cpp Explained

### Including the Common Header

```cpp
#include "../common.h"
```

The `common.h` header file is included at the top of `main.cpp`. This file contains utility functions for opening files, comparing files, and printing results.

### Function: openFiles();

```cpp
int main() {
    auto[infile, outfile] = openFiles();
```

`openFiles()` is called to open `input.txt` and `output.txt`. This function is defined in `common.h` and returns a pair of file streams.

### Reading Input

```cpp
    int tors_tid, mors_tid;
    while (infile >> tors_tid >> mors_tid) {
```

The program reads pairs of integers from `input.txt`, which represent the number of seconds it takes for Tor (`tors_tid`) and his mother (`mors_tid`) to eat a carrot.

### The Carrot-Eating Logic

```cpp
        int antal_morotter = 40;
        int tors_morotter = 0, mors_morotter = 0;
        int tors_counter = tors_tid, mors_counter = mors_tid;
```

We initialize the number of carrots in the bowl (`antal_morotter`) and counters for the number of carrots Tor and his mother have eaten (`tors_morotter` and `mors_morotter`). We also initialize counters to track when Tor and his mother will be ready to eat the next carrot (`tors_counter` and `mors_counter`).

```cpp
        while (antal_morotter > 0) {
```

The while loop runs until there are no more carrots left in the bowl.

```cpp
            if (antal_morotter == 1 && tors_counter == tors_tid && mors_counter == mors_tid) {
                break; // Neither takes the last carrot if both are ready to take it
            }
```

This condition checks if only one carrot is left and both are ready to eat it. If true, they both refrain from eating the last carrot, and we break out of the loop.

```cpp
            if (tors_counter == tors_tid) { // If it's Tor's turn
                tors_morotter++;
                antal_morotter--;
                tors_counter = 1; // Reset Tor's counter
            } else {
                tors_counter++; // Increment Tor's counter
            }
```

Here, we check if it's Tor's turn to eat a carrot based on his counter. If it is, we increment the number of carrots he's eaten, decrement the total number of carrots, and reset his counter. If it's not his turn, we just increment his counter.

```cpp
            if (antal_morotter > 0 && mors_counter == mors_tid) { // If it's his mother's turn and carrots are left
                mors_morotter++;
                antal_morotter--;
                mors_counter = 1; // Reset his mother's counter
            } else if (antal_morotter > 0) {
                mors_counter++; // Increment his mother's counter
            }
        }
```

We perform a similar check for his mother, incrementing her counter and the number of carrots she's eaten as appropriate.

### Writing Output

```cpp
        outfile << tors_morotter << " " << mors_morotter << '\n';
```

For each pair of `tors_tid` and `mors_tid`, we write the result to `output.txt`, indicating how many carrots Tor and his mother ate.

### Closing Files and Comparing Output

```cpp
    infile.close();
    outfile.close();

    printComparison();
```

After processing all input pairs, we close the file streams and call `printComparison()` to check if the generated output matches the expected output.

## Conclusion

The code solves the carrot-eating problem by simulating the eating process and tracking the number of carrots each person eats. Special cases, such as neither person taking the last carrot, are handled explicitly to ensure the correctness of the solution.
