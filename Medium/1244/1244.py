def main():
    l = list(map(int, input("Enter the population weights : ").split()))
    w = int(input("Enter the boat weight limit : "))
    l.sort(reverse = True)
    print(l)
    off_limit = len(l) - 1
    number_of_boats = 0
    if max(l) == w:
        for i in range(len(l)):
            if i >= off_limit: break 
            if w > l[i] + l[off_limit]:
                off_limit  = off_limit - 1
            number_of_boats += 1
                
        print("The smallest number of boats required will be ", number_of_boats)                
    else:
        print("You can't save everyone!\nTry boat with more weight limit!")

if __name__ == "__main__":
    main()