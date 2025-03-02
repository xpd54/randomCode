from typing import List


def list_to_set(nums: List[int]) -> List[int]:
    my_set = set()
    for n in nums:
        my_set.add(n)
    return my_set


nums = [1, 2, 3, 4, 5, 5]
print(list_to_set(nums))


def contains_duplicate(words: List[str]) -> bool:
    my_set = set()
    for word in words:
        if word in my_set:
            return True
        my_set.add(word)
    return False


non_duplicate = range(1, 10)

print(contains_duplicate(non_duplicate))
