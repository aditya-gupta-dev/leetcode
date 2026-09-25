package main

import "fmt"

func splitArray(nums []int, k int) int {
	var low, high int64

	for _, num := range nums {
		if int64(num) > low {
			low = int64(num)
		}

		high += int64(num)
	}

	for low < high {
		mid := low + (high-low)/2

		parts := 1
		var sum int64

		for _, num := range nums {
			if sum+int64(num) > mid {
				parts++
				sum = int64(num)
			} else {
				sum += int64(num)
			}
		}

		if parts <= k {
			high = mid
		} else {
			low = mid + 1
		}
	}

	return int(low)
}

func main() {
	nums := []int{7, 2, 5, 10, 8}
	k := 2
	fmt.Println(splitArray(nums, k))
}
