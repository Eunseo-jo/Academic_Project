# CSCI 4511W - Intro to AI

This contains final group project for the University of Minnesota Computer Science class - CSCI 4511W, which I took Spring 2022 semester. For final project in Intro to AI class, our team develop the Nerdle solver.

## Nerdle Solver


Nerdle is similar to Wordle with the application of mathematical concepts. 
We see this problem as pathfinding. Using path-finding and data mining computes all possible combinations of possible guesses and find the answer to exact 8 digits equations. 

The "repeater" function creates every possible equation permutation and write out "a1.txt".

### Data Cleaning
The "parser" function removes queries that contained invalid pairs of text that may not pass Nerdle’s evaluation criteria from "a1.txt". Then write it down at "a2.txt".

The "builder" function removes entries that have operation symbols after the equation symbol.
Then write out the finally cleaned equations to a comma-separated value file, “a3.csv”.


### Nerdle guessing engine
The function "Solver" reads “a3.csv” into a pandas dataframe with alphabetical columns for each index, a heuristic column, and a column for the equation. 

The heuristic column, “unique”, counts the number of unique characters remaining in the equation.

It prioritize equations that have the highest uniqueness to them so it can uncover more of the answer in a guess that way.

The function "result mapper" based on user feedback. 
If user gave "2" it can remove all other characters that exist at that index in column.

If user gave “1”, then we can remove that character from that index, but append it to a list, “in play” which keeps track of remaining possible characters.

If we are given a “0”, then we will append it to a list, invalids, which will be used to remove that character from all columns since it does not exist in the equation.

After removal, we repeat this seven more times for every index and then proceed to confirm that all “in play” characters are in the equation, removing ones that do not contain an “in play” character. 

