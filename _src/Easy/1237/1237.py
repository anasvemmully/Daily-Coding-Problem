# modify the friends list here 
# to find the friends group

friends = {
        0: [1, 2],
        1: [0, 5],
        2: [0],
        3: [6],
        4: [],
        5: [1],
        6: [3]
    }

def main(friends_list):

    print(friends_list)

    dset = [-1 for x in range(len(friends_list))]
    number_of_groups = 0
    for k,v in friends_list.items():
        for i in v: 
            if dset[k] != i: 
                dset[i] = k
        if dset[k] == -1 : number_of_groups+=1
        
    print("number of groups : ", number_of_groups)

if __name__ == "__main__":
    main(friends)