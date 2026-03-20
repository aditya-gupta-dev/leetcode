package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	num := 0
	for {
		num = num*10 + l1.Val
		if l1.Next == nil {
			break
		}

		l1 = l1.Next
	}

	fmt.Println(num)
	return nil 
}

func main() {
	var list = ListNode { 
		Val: 2,
		Next: &ListNode{
			Val: 4,
			Next: &ListNode{
				Val: 3,
				Next: nil,
			},
		}, 
	}

	addTwoNumbers(&list, nil)
}
