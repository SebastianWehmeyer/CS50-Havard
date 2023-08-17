
input_text = str(input("Text: ") + " ") 
sentences_count = 0
words_count = 0
letters_count = 0

for text_character in input_text:
    if text_character in [".", "!", "?"]:
        sentences_count += 1
    if text_character in [" "]:
        words_count += 1
    if text_character.isalpha():
        letters_count += 1

grade = round(0.0588 * (letters_count / words_count * 100) - 0.296 * (sentences_count / words_count * 100) - 15.8)

if grade < 1:
   print("Before Grade 1")
elif grade >= 16:
   print("Grade: 16+")
else:
   print("Grade: " + str(grade))
