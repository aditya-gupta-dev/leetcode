package main

import (
	"fmt"
)

func singleNumber(nums []int) int {
	freq := make(map[int]int)

	for _, n := range nums { 
		if freq[n] == 0 { 
			freq[n] = 1 
		} else { 
      freq[n] = freq[n] + 1 
		}
	}

	for k, v := range freq { 
		if v == 1 { 
      return k  
		}
	}

	return 0
}

func main() {
	arr := []int{4, 1, 2, 1, 2}
	fmt.Println(singleNumber(arr))
}
