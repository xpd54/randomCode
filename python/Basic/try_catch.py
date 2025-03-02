value = int(input())

try:
    10 / value
except Exception as error:
    print("value is zero ", value)
    print(error)


def catch_the_error() -> None:
    value = input()
    try:
        int_val = int(value)
        print(int_val)
    except ValueError:
        print("Error: Invalid value ")
    except Exception as error:
        print("Generic error ", error)


catch_the_error()
