package main

import "fmt"

func twoSum(nums []int, target int) []int {
	visited := make(map[int]int)
	for i, num := range nums {
		complement := target - num
		if index, ok := visited[complement]; ok {
			return []int{index, i}
		}
		visited[num] = i
	}
	return []int{}
}

func main() {

	nums1 := []int{2, 7, 11, 15}
	target1 := 9
	fmt.Printf("Input: nums = %v, target = %d\n", nums1, target1)
	fmt.Printf("Output: %v\n\n", twoSum(nums1, target1))

	nums2 := []int{3, 2, 4}
	target2 := 6
	fmt.Printf("Input: nums = %v, target = %d\n", nums2, target2)
	fmt.Printf("Output: %v\n\n", twoSum(nums2, target2))

	nums3 := []int{3, 3}
	target3 := 6
	fmt.Printf("Input: nums = %v, target = %d\n", nums3, target3)
	fmt.Printf("Output: %v\n\n", twoSum(nums3, target3))
}
