from typing import Dict, List


def create_dict(name: str, age: int) -> Dict[str, int]:
    my_dict = {name: age}
    return my_dict


print(create_dict("hello", 10))


def list_to_dic(words: List[str]) -> Dict[str, int]:
    my_dict = {}
    for i in range(len(words)):
        w = words[i]
        my_dict[w] = i
    return my_dict


my_list = ["hello", "word", "quick", "fox", "jumps", "over"]

print(list_to_dic(my_list))


def count_char(my_list: List[str]) -> Dict[str, int]:
    my_dict = {}
    for word in my_list:
        for char in word:
            if char in my_dict:
                my_dict[char] += 1
            else:
                my_dict[char] = 1
    return my_dict


print(count_char(my_list))
