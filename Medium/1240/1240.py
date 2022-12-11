def main():
    def generate_grey_code(bit):
        if n < 1 : return []
        else:
            grey_codes = ['', '']
            i = 1
            while n >= i:
                limit  = 2**i
                if limit != len(grey_codes):
                    grey_codes.extend(grey_codes[::-1])
                for j in range(limit):
                    if j < limit/2:
                        grey_codes[j] = '0' + grey_codes[j]  
                    else:
                        grey_codes[j] = '1' + grey_codes[j]
                i += 1
                    
            return grey_codes

    n = int(input("Enter the numebr of bits : "))
    print(generate_grey_code(n))

if __name__ == "__main__":
    main()