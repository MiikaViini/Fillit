# Fillit
Find optimal solution placing tetrominos given in to smallest possible square

First group project in Hive Helsinki.

Task was to find optimal solution placing given pieces to smallest possible
square. We were in collaboration with Atte Koykka, who invented the last
piece of algorithm that we use in our last version.

First versions algorithm for solving the puzzle was in recursive manner.
Second version was iterative, which was 8 times faster.
Third and last version was again recursive, but Atte came up with
idea to just check tetrominos from three spots instead of four.
That increased speed again.

Usage

1. Clone the repository
```
git clone https://github.com/MiikaViini/Fillit.git
```

2. Choose your version and go to the project folder and
```
make
```
3. Run
```
./fillit [tetrominos to solve -file]
```
The tetrominos given should be like this:
```
...#
...#
...#
...#

....
....
....
####

.###
...#
....
....

....
..##
.##.
....

....
.##.
.##.
....

....
....
##..
.##.

##..
.#..
.#..
....
```
There is also valid and invalid piece examples in `fillit test_set` directory

4. Output should look like this
```
DDAA
CDDA
CCCA
BBBB
```
where letter indicates in which order piece is in file.
