def main():
    s = list(map(int, input("Enter the elements : ").split()))
    l = []
    max = 0
    for k, i in enumerate(s):
        tmp = [i]
        for j in s:
            if i != j:
                if i % j == 0 or j % i == 0:
                    tmp.append(j)
        l.append(tmp)
        if max <= len(tmp):
            max = k
    print("largest subset :", l[max]) 
        
    


if __name__ == "__main__":
    main()