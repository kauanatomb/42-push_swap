# Push Swap

**Push Swap** is an algorithmic project from the 42 core curriculum. The goal is to sort a stack of integers using only a limited set of operations on two stacks (`a` and `b`), with performance constraints based on input size.

All logic was implemented in C, with a focus on minimizing the number of operations, managing memory manually, and respecting project constraints.

---

## ⚙️ Compilation

```bash
make
./push_swap [integers...]
```

Example:
```bash
./push_swap 3 2 1
```
> Output: sa rra

To test performance or validate outputs, I used a separate checker script (given by 42) and benchmarked against 42 guidelines.

## 🎯 Constraints
The project required sorting under the following thresholds:

100 elements → < 700 operations

500 elements → < 5500 operations

These benchmarks strongly influenced the algorithmic design.

## 🧠 Algorithm Strategy
**Phase 1:** Radix Sort with Bitwise Ranks

For initial testing, I implemented a version of Radix Sort, using binary representation of indexed ranks. Each number received a rank (its position in the sorted array), allowing me to sort based on bit positions.

- ✅ Simple to implement and very stable

- ⚠️ Efficient for larger input (500+), but overkill for small inputs

- 🔎 Achieved ~1200 ops on 100, which exceeded the benchmark

**Phase 2:** Chunk-Based Sorting

To meet the operation limits, I implemented a Chunk Sort strategy:

- Divided the sorted input into chunks of N elements (adaptive per input size)

- Pushed elements to stack b chunk-by-chunk, prioritizing order

- Used smart rotations (ra / rra) to minimize movement

- Pulled back from b to a in correct order

Results:

✅ ~600–700 ops for 100 numbers

✅ ~5500–5800 ops for 500 numbers

🚀 Tuned chunk sizes manually for optimal thresholds

## 🧪 Tester Script – Bash Automation

To validate the performance and correctness of the algorithm across multiple randomized inputs, I created a custom Bash script that:

- Generates `$NUM_COUNT` random numbers
- Runs `push_swap` on them
- Pipes the output to the `checker` provided by 42
- Tracks success rate (`OK` vs `KO`) and number of operations
- Highlights any tests that exceed the operation threshold

## 🧩 Challenges Faced
- Finding a balance between simplicity (Radix) and control (Chunks)

- Creating a flexible structure to adapt algorithm per input size

- Avoiding unnecessary rotations while minimizing overall moves

- Managing input validation and edge cases manually (no stdlib helpers)

## ✅ Key Learnings
- Designing algorithms with hard performance limits under pressure

- Using both bitwise logic and greedy heuristics in C

- Writing maintainable, testable C under strict constraints

- Debugging with valgrind, gdb, and trace logs
