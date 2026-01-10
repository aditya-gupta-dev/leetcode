def applyOperations(nums: list[int]) -> list[int]:
    for i in range(0, len(nums)-1): 
        if nums[i] != nums[i+1]: 
            continue 
        else: 
            nums[i] = nums[i] * 2 
            nums[i+1] = 0 

    seen: list[int] = [] 
    zeros = nums.count(0) 

    for x in nums: 
        if x == 0: 
            continue 
        seen.append(x) 

    nums = list(seen) + [0] * zeros  
    return nums 

arr = [1,2,2,1,1,0] # 1, 4, 2, 0, 0, 0  

print(applyOperations(arr)) # 1, 4, 0, 2, 0, 0  
