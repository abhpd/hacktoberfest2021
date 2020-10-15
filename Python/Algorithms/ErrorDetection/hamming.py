
import argparse
import math
import colorama

def power_of_two(n):
    return math.log(n, 2).is_integer()
    
def is_code_valid(code):
    return not any([c != '0' and c != '1' for c in code])

def print_digit(digit):
    return colorama.Fore.YELLOW + ("%s" % (digit,)) + colorama.Fore.RESET

# n: 0 = p1, 1 = p2, 2 = p4, 3 = p8, etc...
def calculate_parity(n, hamming, should_print=False):
    parity = 0
    two_power_n = 2**n
    
    s = "p%-2d ({}) =  " % (two_power_n,)
    
    if len(hamming) < two_power_n:
        return False, hamming
    for i in range(1, len(hamming) + 1):
        n_bit = i >> n
        if (n_bit & 1 == 1) and (i != two_power_n):
            parity ^= hamming[i-1]
            s += "d%-2d (%s)   ^  " % (i, print_digit(hamming[i-1]))
    
    if should_print:
        s = s[0:-4].format(print_digit(parity))
        print s
    
    
    hamming[two_power_n - 1] = parity
    return True, hamming
    
# n: 0 = p1, 1 = p2, 2 = p4, 3 = p8, etc...
def check_parity(n, hamming, should_print=False):
    parity = 0
    two_power_n = 2**n
    
    s = "p%-2d ({}) =  " % (two_power_n,)
    
    if len(hamming) < two_power_n:
        return False, False
    for i in range(1, len(hamming) + 1):
        n_bit = i >> n
        if (n_bit & 1 == 1) and (i != two_power_n):
            parity ^= hamming[i-1]
            s += "d%-2d (%s)   ^  " % (i, print_digit(hamming[i-1]))
    
    if should_print:
        s = s[0:-4].format(print_digit(parity))
        print s
    
    valid = hamming[two_power_n - 1] == parity
    return True, valid


def create_code_word(data):
    hamming = []
    i = 0
    while i < len(data):
        if power_of_two(len(hamming) + 1):
            hamming.append(0)
            continue
        hamming.append(data[i])
        i += 1
    return hamming


def create_hamming_code(data, should_print):
    if not is_code_valid(data):
        return None
    data = [ord(c) - ord('0') for c in data]
    hamming = create_code_word(data)
    parity_index = 0
    continue_loop = True
    while continue_loop:
        continue_loop, hamming = calculate_parity(parity_index, hamming, should_print)
        parity_index += 1
    return hamming
    
def check_hamming_code(code, should_print=False):
    invalid_indices = []
    valid_indices = []
    parity_index = 0
    continue_loop = True
    while continue_loop:
        continue_loop, valid = check_parity(parity_index, code, should_print)
        if valid:
            valid_indices.append(2 ** parity_index)
        elif continue_loop:
            invalid_indices.append(2 ** parity_index)
        parity_index += 1
    return valid_indices, invalid_indices

def get_pretty_parity(code):
    s = ""
    for i in range(len(code)):
        if power_of_two(i+1):
            s += colorama.Fore.LIGHTBLUE_EX + code[i] + colorama.Fore.RESET
        else:
            s += code[i]
            
    return s

def get_pretty_check(code, valids, invalids):
    s = ""
    for i in range(len(code)):
        if power_of_two(i + 1):
            color = colorama.Fore.LIGHTGREEN_EX if (i + 1) in valids else colorama.Fore.LIGHTRED_EX
            s += color + code[i] + colorama.Fore.RESET
        else:
            s += code[i]
            
    return s
    
def get_data(code):
    s = ""
    for i in range(len(code)):
        if power_of_two(i + 1):
            continue
        s += code[i]
            
    return s
    
def handle_create(code, should_print):
    hamming = create_hamming_code(code, should_print)
    if hamming is None:
        print "Invalid code! Must be a binary string: 10010101."
    else:
        hamming = ''.join([chr(c + ord('0')) for c in hamming])
        print "Hamming code of {} ({}) is {} ({})".format(code, len(code), get_pretty_parity(hamming), len(hamming))

def handle_check(code, should_print):
    if not is_code_valid(code):
        return None
    str_code = code
    code = [ord(c) - ord('0') for c in code]
    valid_indices, invalid_indices = check_hamming_code(code, should_print)
    data = get_data(str_code)
    print "The data word of {} ({}) is {} ({})\t(without error correction/detection)".format(get_pretty_check(str_code, valid_indices, invalid_indices), len(code), data, len(data))
    

def main():
    parser = argparse.ArgumentParser(description='Hamming Code Calculator')
    parser.add_argument('code', metavar='<code>', type=str,
                        help='The data or code to check. Must be a binary string. Example: 11010001')
    parser.add_argument('-c', dest='check', action='store_true',
                    help='Check the given code instead of calculating code word for it.')
    parser.add_argument('-p', dest='should_print', action='store_true',
                    help='Print calculation of parity bits.')
	
    args = parser.parse_args()
	
    if not args.check:
        handle_create(args.code, args.should_print)
    else:
        handle_check(args.code, args.should_print)


if __name__ == "__main__":
	main()