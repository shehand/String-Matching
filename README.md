# String-Matching Algorithms

## Language used

> - C

## Algorithms

> - Boyer - Moore Algorithm

Bad Character Heuristic

The idea of bad character heuristic is simple. The character of the text which doesn’t match with the current character of pattern is called the Bad Character. Upon mismatch we shift the pattern until –
1) The mismatch become a match
2) Pattern P move past the mismatch character.

Case 1 – Mismatch become match
We will lookup the position of last occurence of mismatching character in pattern and if mismatching character exist in pattern then we’ll shift the pattern such that it get aligned to the mismatching character in text T.

Case 2 – Pattern move past the mismatch character
We’ll lookup the position of last occurence of mismatching character in pattern and if character does not exist we will shift pattern past the mismatching character.

Complexity - If the character is not present at all, then it may result in a shift by m (length of pattern). Therefore, the bad character heuristic takes O(n/m) time in the best case.
