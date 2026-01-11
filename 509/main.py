class Solution:
    def fib(self, n: int) -> int:
        a, b = 0, 1 
        s = 0   
        i = 1 

        while i < n:
            s = a + b
            a = b 
            b = s  
            i += 1 
        return s
    
