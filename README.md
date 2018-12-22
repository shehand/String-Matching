# String-Matching Algorithms

## Language used

> - C

## Algorithms

> - Boyer - Moore Algorithm

Bad Character Heuristic

The idea of bad character heuristic is simple. The character of the text which doesn’t match with the current character of pattern is called the Bad Character. Upon mismatch we shift the pattern until –
1) The mismatch become a match
2) Pattern P move past the mismatch character.
