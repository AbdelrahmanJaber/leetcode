<h2><a href="https://leetcode.com/problems/repeated-dna-sequences/">187. Repeated DNA Sequences</a></h2><h3>Medium</h3><hr>Can you solve this real interview question? Repeated DNA Sequences - The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

 * For example, "ACGAATTCCG" is a DNA sequence.

When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]


Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]


 

Constraints:

 * 1 <= s.length <= 105
 * s[i] is either 'A', 'C', 'G', or 'T'.