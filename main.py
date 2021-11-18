# file to write primes

from colorama import Fore
import time


def open_file(file_name="testpy.txt",modo='a'):
    return open(file_name,modo)

def is_prime(num):
    if  num <= 0 :
        return False
    i = 2
    while i*i <= num:
        if  num % i == 0 :
            return False
        i += 1
    return True
f = open_file("size.txt","r")
limt = int(f.read())
f.close();
open_file(modo='w').close()
total =0;
for i in range(0,limt):
    inicio = time.time_ns();
    if is_prime(i):
            file = open_file()
            file.write(str(i) + "\n")
            file.close()
            print(f"{Fore.GREEN}{i}")
    else:
        print(f"{Fore.WHITE}{i}")
    fim = time.time_ns();
    total += (fim-inicio)
print("\n Total: " + str(total/1000000000))


