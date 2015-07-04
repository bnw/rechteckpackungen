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
Available modes:
         test-overlapping, find-optimal-placement, find-good-placement, improve-placement

See below for detailed description:

test-overlapping FILE
         Tests if the placement described in FILE has any overlapping.

find-optimal-placement FILE [-noRotation]
         Prints an optimal placement for the instance described in FILE.
         Works by enumerating all possible placements.
         -noRotation: Do not roate rectangles to find a better placement.

find-good-placement FILE [-quality=QUALITY] [-noRotation] [-noTreeMutation]
         Prints a placement for the instance described in FILE.
         Works by guessing a solution and then finding a local optimum based on this solution.
         If the bounds are rather small, this might not yield any feasable solution,
         regardless of QUALITY.
         QUALITY (default=2): Number of rectangles that can be mutated.
                 Higher means better results but slower computation.
         -noRotation: Do not roate rectangles to find a better placement.
         -noTreeMutation: Do not move rectangles around the tree to find a better placement.

improve-placement INSTANCE_FILE PLACEMENT_FILE [-quality=QUALITY] [-noRotation] [-noTreeMutation]
         Prints a placement for the instance described in INSTANCE_FILE by finding a
         local optimum based on the compacted(!) placement described in PLACEMENT_FILE.
         QUALITY (default=2): Number of rectangles that can be mutated.
                 Higher means better results but slower computation.
         -noRotation: Do not roate rectangles to find a better placement.
         -noTreeMutation: Do not move rectangles around the tree to find a better placement.
```

How to run the tests
--------------------
```
./tests.exe
```
