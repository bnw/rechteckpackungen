# Rechteckpackungen
Programmierpraktikum Diskrete Optimierung: Darstellung von Rechteckpackungen

How to build it
--------------
```
git clone https://github.com/bnw/rechteckpackungen.git
cd rechteckpackungen
make
```

Usage: rechteckpackungen.exe
----------------------------
```
Usage: rechteckpackungen.exe MODE FILES [OPTIONS]
Available modes: test-overlapping, find-optimal-placement, find-good-placement, improve-placement

See below for detailed description:

test-overlapping FILE
         Tests if the placement described in FILE has any overlapping.

find-optimal-placement FILE
         Prints an optimal placement for the instance described in FILE. Works by enumerating all possible placements.

find-good-placement FILE
         Prints a placement for the instance described in FILE. Works by guessing a solution and then finding a local optimum based on this solution.

improve-placement INSTANCE_FILE PLACEMENT_FILE
         Prints a placement for the instance described in INSTANCE_FILE by finding a local optimum based on the placement described in PLACEMENT_FILE.

```

How to run the tests
--------------------
```
./tests.exe
```
