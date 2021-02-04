import sys
import math

text = None
pretty = False

if len(sys.argv) > 1:
    if sys.argv[-1] == "--pretty":
        pretty = True
        sys.argv.pop()

    text = " ".join(sys.argv[1:])
elif not sys.stdin.isatty():
    text = sys.stdin.read()
else:
    print(f"Usage: {sys.argv[0]} <Text>")
    exit(0)

brainfuck = []
current = 0

for char in text:
    ascii_code = ord(char)
    sign = "+" if ascii_code >= current else "-"
    diff = abs(ascii_code - current)

    # print(f"Diff {diff}\nSign {sign}")

    if not diff:
        brainfuck.append('.')
    elif diff < 10:
        brainfuck.append(sign * diff + ".")
    else:
        closest_sqn = round(math.sqrt(diff))
        rest = diff - (closest_sqn ** 2)

        rests = (sign if rest > 0 else "+" if sign == "-" else "-") * abs(rest)

        brainfuck.append(
            f">{'+' * closest_sqn}[<{sign * closest_sqn}>-]<{rests}.")

    current = ascii_code

    if pretty:
        brainfuck.append("\n")

print("".join(brainfuck))
