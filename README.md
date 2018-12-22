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

The hash function suggested by Rabin and Karp calculates an integer value. The integer value for a string is numeric value of a string. For example, if all possible characters are from 1 to 10, the numeric value of “122” will be 122. The number of possible characters is higher than 10 (256 in general) and pattern length can be large. So the numeric values cannot be practically stored as an integer. Therefore, the numeric value is calculated using modular arithmetic to make sure that the hash values can be stored in an integer variable (can fit in memory words). To do rehashing, we need to take off the most significant digit and add the new least significant digit for in hash value. Rehashing is done using the following formula.

hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q

hash( txt[s .. s+m-1] ) : Hash value at shift s.
hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1)
d: Number of characters in the alphabet
q: A prime number
h: d^(m-1)

Complexity - The average and best case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm). Worst case of Rabin-Karp algorithm occurs when all characters of pattern and text are same as the hash values of all the substrings of txt[] match with hash value of pat[]. For example pat[] = “AAA” and txt[] = “AAAAAAA”.

> - KMP (Knuth Morris Pratt) Algorithm

The KMP matching algorithm uses degenerating property (pattern having same sub-patterns appearing more than once in the pattern) of the pattern and improves the worst case complexity to O(n). The basic idea behind KMP’s algorithm is: whenever we detect a mismatch (after some matches), we already know some of the characters in the text of the next window. We take advantage of this information to avoid matching the characters that we know will anyway match. Let us consider below example to understand this.

Matching Overview
txt = "AAAAABAAABA" 
pat = "AAAA"

We compare first window of txt with pat
txt = "AAAAABAAABA" 
pat = "AAAA"  [Initial position]
We find a match. This is same as Naive String Matching.

In the next step, we compare next window of txt with pat.
txt = "AAAAABAAABA" 
pat =  "AAAA" [Pattern shifted one position]
This is where KMP does optimization over Naive. In this 
second window, we only compare fourth A of pattern
with fourth character of current window of text to decide 
whether current window matches or not. Since we know 
first three characters will anyway match, we skipped 
matching first three characters. 

Need of Preprocessing?
An important question arises from the above explanation, 
how to know how many characters to be skipped. To know this, 
we pre-process pattern and prepare an integer array 
lps[] that tells us the count of characters to be skipped. 

Preprocessing Overview:

KMP algorithm preprocesses pat[] and constructs an auxiliary lps[] of size m (same as size of pattern) which is used to skip characters while matching.
name lps indicates longest proper prefix which is also suffix.. A proper prefix is prefix with whole string not allowed. For example, prefixes of “ABC” are “”, “A”, “AB” and “ABC”. Proper prefixes are “”, “A” and “AB”. Suffixes of the string are “”, “C”, “BC” and “ABC”.
We search for lps in sub-patterns. More clearly we focus on sub-strings of patterns that are either prefix and suffix.
For each sub-pattern pat[0..i] where i = 0 to m-1, lps[i] stores length of the maximum matching proper prefix which is also a suffix of the sub-pattern pat[0..i].

 lps[i] = the longest proper prefix of pat[0..i] 
              which is also a suffix of pat[0..i]. 
              
Note : lps[i] could also be defined as longest prefix which is also proper suffix. We need to use properly at one place to make sure that the whole substring is not considered.

Examples of lps[] construction:
For the pattern “AAAA”, 
lps[] is [0, 1, 2, 3]

For the pattern “ABCDE”, 
lps[] is [0, 0, 0, 0, 0]

For the pattern “AABAACAABAA”, 
lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]

For the pattern “AAACAAAAAC”, 
lps[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4] 

For the pattern “AAABAAA”, 
lps[] is [0, 1, 2, 0, 1, 2, 3]

Searching Algorithm:
Unlike Naive algorithm, where we slide the pattern by one and compare all characters at each shift, we use a value from lps[] to decide the next characters to be matched. The idea is to not match a character that we know will anyway match.

How to use lps[] to decide next positions (or to know a number of characters to be skipped)?

- We start comparison of pat[j] with j = 0 with characters of current window of text.
- We keep matching characters txt[i] and pat[j] and keep incrementing i and j while pat[j] and txt[i] keep matching.
-When we see a mismatch
  -We know that characters pat[0..j-1] match with txt[i-j…i-1] (Note that j starts with 0 and increment it only when there is a match).
  -We also know (from above definition) that lps[j-1] is count of characters of pat[0…j-1] that are both proper prefix and suffix.
  -From above two points, we can conclude that we do not need to match these lps[j-1] characters with txt[i-j…i-1] because we know that    these characters will anyway match. Let us consider above example to understand this.
