function lenLongestFibSubseq(arr: number[]): number {
    const s = new Set(arr);
    const n = arr.length;
    let maxLen = 0;

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            let a = arr[i];
            let b = arr[j];
            let currLen = 2;

            // Check if the next Fibonacci number exists in the set
            while (s.has(a + b)) {
                let next = a + b;
                a = b;
                b = next;
                currLen++;
            }
            
            if (currLen > 2) {
                maxLen = Math.max(maxLen, currLen);
            }
        }
    }

    return maxLen;
}