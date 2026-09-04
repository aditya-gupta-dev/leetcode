package main

import "fmt"

func longestPalindrome(s string) string {
	if len(s) == 0 {
		return ""
	}
	start, end := 0, 0
	for i := 0; i < len(s); i++ {
		len1 := efromcenter(s, i, i)
		len2 := efromcenter(s, i, i+1)
		maxLen := len1
		if len2 > len1 {
			maxLen = len2
		}
		if maxLen > end-start {
			start = i - (maxLen-1)/2
			end = i + maxLen/2
		}
	}
	return s[start : end+1]
}

func efromcenter(s string, left, right int) int {
	L, R := left, right
	for L >= 0 && R < len(s) && s[L] == s[R] {
		L--
		R++
	}
	return R - L - 1
}
func longestPalindromeOld(s string) string {
	isPalindrome := func(input string) bool {
		runes := []rune(input)
		for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
			runes[i], runes[j] = runes[j], runes[i]
		}
		return input == string(runes)
	}

	results, max, start := []string{}, 0, 0

	for i := range len(s) + 1 {
		for _ = range len(s) + 1 {

			substring := s[start:i]
			fmt.Println(substring)
			if isPalindrome(substring) {
				results = append(results, substring)
			}
		}
		start += 1
	}

	fmt.Println(results)
	for i := range len(results) {
		if len(results[i]) > len(results[max]) {
			max = i
		}
	}

	return results[max]
}

func main() {
	key := "cbbd"
	fmt.Println(longestPalindrome(key))
}
