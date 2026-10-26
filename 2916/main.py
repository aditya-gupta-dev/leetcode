
class Solution:
    def sumCounts(self, nums: list[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)

        size = 4 * n
        sums = [0] * size
        squares = [0] * size
        lazy = [0] * size

        def apply(node: int, left: int, right: int, val: int) -> None:
            length = right - left + 1

            squares[node] = (
                squares[node]
                + 2 * val * sums[node]
                + length * val * val
            ) % MOD

            sums[node] = (sums[node] + length * val) % MOD
            lazy[node] += val

        def push(node: int, left: int, right: int) -> None:
            if lazy[node] == 0 or left == right:
                return

            mid = (left + right) // 2
            val = lazy[node]

            apply(node * 2, left, mid, val)
            apply(node * 2 + 1, mid + 1, right, val)

            lazy[node] = 0

        def update(
            node: int,
            left: int,
            right: int,
            ql: int,
            qr: int,
            val: int,
        ) -> None:
            if ql <= left and right <= qr:
                apply(node, left, right, val)
                return

            push(node, left, right)
            mid = (left + right) // 2

            if ql <= mid:
                update(node * 2, left, mid, ql, qr, val)

            if qr > mid:
                update(node * 2 + 1, mid + 1, right, ql, qr, val)

            sums[node] = (
                sums[node * 2] + sums[node * 2 + 1]
            ) % MOD

            squares[node] = (
                squares[node * 2] + squares[node * 2 + 1]
            ) % MOD

        last_seen = {}
        answer = 0

        for i, x in enumerate(nums):
            prev = last_seen.get(x, -1)
            update(1, 0, n - 1, prev + 1, i, 1)
            answer = (answer + squares[1]) % MOD

            last_seen[x] = i

        return answer
