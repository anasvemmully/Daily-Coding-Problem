
def main():
    try:
        a, b = input("Enter the two words : ").split()
        length_A, length_B = len(a), len(b)
        if length_A != length_B:
            return False
        else: 
            for k in range(length_A):
                if a[k] == b[0]:
                    i,j = 0, k
                    while i < length_B:
                        while True:
                            if a[j] != b[i]:
                                return False
                            j = (j + 1) % length_A
                            break
                        i += 1
                    return True
    except:
        print("Error Try giving two strings!")

if __name__ == "__main__":
    if main():
        print("True")
    else:
        print("False")