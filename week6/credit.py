
while True:
    try:
        card_number = str(input("Number: "))
        if (isinstance(int(card_number), int)):
             break
    except:
        print("Invalid")

length = len(card_number)
digit_position, sum_first_digits, sum_second_digits, multiplied_second_digits = 0

while True:
    while digit_position < length:
        sum_first_digits += int(card_number[length - digit_position - 1])
        if length - digit_position - 2 >= 0:
            multiplied_second_digits = int(card_number[length - digit_position - 2]) * 2
            multiplied_as_string = str(multiplied_second_digits)
            digit_position_for_multiplied = 0
            while digit_position_for_multiplied < len(str(multiplied_second_digits)):
                sum_second_digits += int(multiplied_as_string[digit_position_for_multiplied])
                digit_position_for_multiplied += 1

        digit_position += 2
    luhn_algorithm = sum_first_digits + sum_second_digits
    if (luhn_algorithm % 10 == 0):
        if card_number[0] == '3' and length == 15 and(card_number[1] == '4' or card_number[1] == '7'):
                print("AMEX")
                break
        if card_number[0] == '5' and length == 16:
            if card_number[1] == '1' or card_number[1] == '2' or card_number[1] == '3' or card_number[1] == '4' or card_number[1] == '5':
                print("MASTERCARD")
                break
        if card_number[0] == '4' and (length == 13 or length == 16):
                print("VISA")
                break
    else:
        print("INVALID")
        break
