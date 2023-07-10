import re

def main():
    
    # [(1,2),(5,8),(4,10),(20,25)] 
    # [(1,3),(2,4),(6,8),(9,10)]
    # [(6,8),(1,9),(2,4),(4,7)]
    input_list = list(map(lambda x : tuple(map(int, x)) , [ x[1:-1].split(',') for x in re.findall(r'(\(\d+,\d+\))', input("Input the list : ")[1:-1])])) 
    for i in enumerate(input_list):
        for j in enumerate(input_list):
            if i == j :continue
            i_index, j_index, i_ele, j_ele = i[0], j[0], i[1], j[1]
            r = range(j[1][0], j[1][1])
            if i_ele[0] in r:
                if i_ele[1] not in r:
                    input_list.insert(i_index, (j_ele[0], i_ele[1]))
                    input_list.pop(j_index)
                input_list.pop(i_index)
    print("Merged interval are :",input_list)

if __name__ == "__main__":
    main()