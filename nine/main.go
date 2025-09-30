package main

import "runtime/debug"

func init() {
	debug.SetMemoryLimit(1000)
}

func palindrome(x int) bool {
	if x < 0 {
		return false
	}
	var digit int

	clone := x
	reverse := 0

	for x > 0 {
		digit = x % 10
		x = x / 10
		reverse = reverse*10 + digit
	}

	return clone == reverse
}

func main() {
	println(palindrome(121))
	println(palindrome(-121))
	println(palindrome(10))
}
