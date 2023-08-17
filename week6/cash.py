
while True:
    try:
        change = float(input("Change owed: "))
        if change > 0:
            break
    except ValueError:
        print("Input is not a float")
    else:
        print("Number is not positive")

count = 0

while change > 0:
    if change >= 0.25:
        change -= 0.25
        count += 1
    elif change < 0.25 and change >= 0.10:
        change -= 0.10
        count += 1
    elif change < 0.10 and change >= 0.05:
        change -= 0.05
        count += 1
    elif change < 0.05:
        change -= 0.01
        count += 1

print(count)
