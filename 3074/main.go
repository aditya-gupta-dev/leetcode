package main

import "slices"

func minimumBoxes(apple []int, capacity []int) int {
	var total int
	for _, a := range apple {
		total += a
	}

	var sum int
	slices.Sort(capacity)

	for i := len(capacity) - 1; i >= 0; i-- {
		sum += capacity[i]
		if sum >= total {
			return len(capacity) - i
		}
	}

	return len(capacity)
}

func main() {
	println(minimumBoxes([]int{1, 3, 2}, []int{4, 3, 1, 5, 2}))
}
