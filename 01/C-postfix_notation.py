
def process_string(arr: list) -> int:
    stack = []
    res = 0
    for i in range(len(arr)):
        if arr[i].isnumeric():
            stack.append(int(arr[i]))
        elif arr[i] in "+-*":
            op2 = stack.pop()
            op1 = stack.pop()
            if arr[i] == "+":
                res = op1 + op2
            elif arr[i] == "-":
                res = op1 - op2
            elif arr[i] == "*":
                res = op1 * op2
            stack.append(res)
    return res

def main():
    s = list(input())
    res = process_string(s)
    print(res)

if __name__ == "__main__":
    main()
