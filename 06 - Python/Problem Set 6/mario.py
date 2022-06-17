# Will see the piramid of Super Marios Bros
from cs50 import get_int
from cs50 import get_string
from cs50 import get_float

# For show the # pyramid

while True:
    try:
        height = get_int(("Height: "))
        if (height >= 1) and (height <= 8):
            break
    except:
        print("", end="")

spaces = 1

# Spaces next to the #
for j in range(height):

    for spaces in range(height-j-1):
        print(" ", end="")

    for i in range(j+1):
        print("#", end="")

    print()
# This was the program :)