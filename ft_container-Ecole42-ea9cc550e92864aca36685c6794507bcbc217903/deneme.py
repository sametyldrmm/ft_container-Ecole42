if __name__ == '__main__':
    std =[]
    for _ in range(int(input())):
        name = input()
        score = float(input())
        std.append((score,name))
    std.sort()
    print(std)