score = int(input())
if score >= 90:
    print("A")
elif 80 <= score and score < 90:
    print("B")
elif 70 <= score and score < 80:
    print("C")
elif 60 <= score and score < 70:
    print("D")
else:
    print("F")