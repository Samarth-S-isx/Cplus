nums = [1, 2,3,4,1,5,2,5,2,6]
k = 4


# for exactly K distinct elemnt do for atmost(k) - atmost(k-1) = exactly(k)


def insert(freq, x, c):
    if freq[x] == -1:
        freq[x] = 1
    else:
        freq[x] += 1
    if freq[x] == 1:
        c = c+1
    return c


def remove(freq, x, c):
    freq[x] -= 1
    if freq[x] == 0:
        c = c-1
    return c


def soution(nums, k):
    freq = [-1]*10001
    head = -1
    tail = 0
    n = len(nums)
    ans = 0
    c = 0
    while(tail < n):
        while(head+1 < n and ((c < k and freq[nums[head+1]] <= 0) or (c <= k and freq[nums[head+1]] > 0))):
            head = head+1
            c = insert(freq, nums[head], c)
        ans += head-tail+1
        if (head >= tail):
            c = remove(freq, nums[tail], c)
            tail = tail+1
        else:
            tail = tail+1
            head = tail-1
    return ans


print(soution(nums, k))
