from cs50 import get_float
from math import floor

# Def the function
def main():
    while True:
        dollars_owed = get_float("Change owed: ")
        cents_owed = floor(dollars_owed * 100)
# Conditionals
        if cents_owed > 0:
            break

    quarters = cents_owed // 25
    dimes = (cents_owed % 25) // 10
    nickels = ((cents_owed % 25) % 10) // 5
    pennies = ((cents_owed % 25) % 10) % 5
# Show the cash :D
    print(f"{quarters + dimes + nickels + pennies}")

if __name__ == "__main__":
    main()