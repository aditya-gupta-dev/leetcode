package main

import (
	"strings"
)

func lengthOfLastWord(s string) int {

	words := strings.Split(strings.TrimRight(s, " "), " ")
	return len(words[len(words)-1])
}

func main() {
	s := "hello World"
	println(lengthOfLastWord(s))
}
