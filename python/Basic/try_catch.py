value = int(input())

try:
    10 / value
except Exception as error:
    print("value is zero ", value)
    print(error)
