package main

func romanToInt(s string) int {
	var result int
	romans := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}
	for i := 0; i < len(s); i++ {
		if i+1 < len(s) && romans[s[i]] < romans[s[i+1]] {
			result -= romans[s[i]]
		} else {
			result += romans[s[i]]
		}
	}
	return result
}
func main() {
	println(romanToInt("MCMXCIV"))
}
