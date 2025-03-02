from typing import List


def read_and_print_input() -> None:
    line = input("hello say: ")
    print(line)


read_and_print_input()


def read_interger() -> int:
    return int(input())


print(read_interger())


def read_integers() -> List[int]:
    raw_input = input()
    split_input = raw_input.split(",")
    holding_list = []
    for split_val in split_input:
        holding_list.append(int(split_val))
    return holding_list


holding = read_integers()

for i in holding:
    print(type(i))
