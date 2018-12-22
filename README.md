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

> - Rabin - Karp Algorithm

The Naive String Matching algorithm slides the pattern one by one. After each slide, it one by one checks characters at the current shift and if all characters match then prints the match.
Like the Naive Algorithm, Rabin-Karp algorithm also slides the pattern one by one. But unlike the Naive algorithm, Rabin Karp algorithm matches the hash value of the pattern with the hash value of current substring of text, and if the hash values match then only it starts matching individual characters. So Rabin Karp algorithm needs to calculate hash values for following strings.

1) Pattern itself.
2) All the substrings of text of length m.

Since we need to efficiently calculate hash values for all the substrings of size m of text, we must have a hash function which has following property.
Hash at the next shift must be efficiently computable from the current hash value and next character in text or we can say hash(txt[s+1 .. s+m]) must be efficiently computable from hash(txt[s .. s+m-1]) and txt[s+m] i.e., hash(txt[s+1 .. s+m])= rehash(txt[s+m], hash(txt[s .. s+m-1]) and rehash must be O(1) operation.
