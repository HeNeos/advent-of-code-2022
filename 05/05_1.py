stacks= [
    ["Z", "J", "N", "W", "P", "S"],
    ["G", "S", "T"],
    ["V", "Q", "R", "L", "H"],
    ["V", "S", "T", "D"],
    ["Q", "Z", "T", "D", "B", "M", "J"],
    ["M", "W", "T", "J", "D", "C", "Z", "L"],
    ["L", "P", "M", "W", "G", "T", "J"],
    ["N", "G", "M", "T", "B", "F", "Q", "H"],
    ["R", "D", "G", "C", "P", "B", "Q", "W"]
]

with open("05.inp.txt") as file:
    for line in file:
        numbers = line.split('move')[1].strip()
        number_of_blocks = int(numbers.split("from")[0].strip())

        beginning_list = int(line.split("from")[1].split("to")[0]) - 1
        ending_list = int(line.split("from")[1].split("to")[1]) - 1

        blocks = stacks[beginning_list][-number_of_blocks:]
        blocks_list = blocks[::-1]
        for block in blocks_list:
            stacks[beginning_list].pop()
            stacks[ending_list].append(block)

for lis in stacks:
    if len(lis) > 0:
        print(lis[-1])
    else:
        print("")
