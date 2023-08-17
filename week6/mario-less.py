
while True:
    try:
        height = int(input("Height: "))
        if height >= 1 and height <= 8:
            break
    except ValueError:
        print("Input is not an int")
    else:
        print("Number must be between 1 & 8")

for current_row in range(1, height+1):
    print(" " * (height-current_row) + "#" * current_row)