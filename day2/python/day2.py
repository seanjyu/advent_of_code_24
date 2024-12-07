import os

# Get the directory where the Python script is located
current_dir = os.path.dirname(os.path.abspath(__file__))

# Construct the relative file path
file_path = os.path.join(current_dir, 'day2.txt')

part_1 = 0

def checkLine(line: list):
    safe = True
    inc = -1
    prevVal = -1
    fail = 0
    fail_ind = -1
    skipAllowed = 1  # Allow skipping one invalid value
    for i, value in enumerate(line):
        value = int(value)
        
        if prevVal == -1:
            prevVal = value
            continue

        # Detect invalid conditions
        isEqualOrTooClose = abs(prevVal - value) < 1  # Adjacent values must differ by at least 1
        isTooFarApart = abs(prevVal - value) > 3     # Adjacent values must differ by at most 3
        isInvalidDecreasing = (prevVal <= value and inc == 0) 
        isInvalidIncreasing = (prevVal >= value and inc == 1)

        # Handle invalid values (with option to skip one)
        if (isEqualOrTooClose or isTooFarApart or isInvalidDecreasing or isInvalidIncreasing):
            safe = False
            fail += 1
            if skipAllowed > 0:
                skipAllowed -= 1  # Skip this invalid value
                fail_ind = i
                continue  # Don't update prevVal, effectively "skipping" this value

        # Update trend direction if undecided
        if inc == -1:
            inc = 0 if prevVal > value else 1

        prevVal = value

    return safe, fail, fail_ind

# Processing the file
part_1 = 0
with open(file_path, 'r') as file:
    for line in file:
        # Handle line and split on space
        cur_line = line.strip().split(" ")

        # Call checkLine for both cases
        checkLine0, lineFail0, fail_ind0 = checkLine(cur_line)
        checkLine1, lineFail1, fail_ind1 = checkLine(cur_line[1::])  # Skip the first element for the second check

        # Determine if the line is valid based on conditions
        if (lineFail0 <= 0) or (lineFail1 <= 0):
            part_1 += 1
        # if checkLine0:
        #     part_1 += 1
        if fail_ind0 != -1:
            cur_line.remove(cur_line[fail_ind0])
            # print(test)
            checkLineRemove, lineFailRemove, fail_indRemove = checkLine(cur_line)
            if checkLineRemove:
                part_1 += 1

print(part_1)
