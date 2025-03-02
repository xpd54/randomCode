from typing import List


my_list = ["hello", "how", "are", "you", "doing"]

for string in my_list:
    print(string)


def count_x(nums: List[int], x: int) -> int:
    count = 0
    for value in nums:
        if value == x:
            count += 1
    return count


nums: List[int] = [1, 2, 3, 5, 56, 56, 5, 7, 8]
print(count_x(nums, 5))
