import subprocess

def process(command):
    return subprocess.Popen(
        command.split(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        stdin=subprocess.PIPE,
        shell=True
    )


def expect(proc, pattern):
    pattern = pattern.strip("\n")
    buffer = ""
    while True:
        buffer += proc.stdout.read(1).decode()
        if pattern.endswith(buffer):
            return True

def write(proc, text):
    proc.stdin.write(f'{text}\n'.encode())
    proc.stdin.flush()
    return text


def test():
    print("Launching processes")
    try:
        c_process = process('magic_square.exe')
        bas_process = process('magic_square.bas')  

        expected_greetings = '''                            MAGIC SQUARE
               CREATIVE COMPUTING  MORRISTOWN NEW JERSEY



GAME OF MAGIC SQUARE

PLAYERS ALTERNATLEY CHOOSE AN INTEGER (1 TO 9)
THAT HAS NOT BEEN PREVIOUSLY USED AND PLACE IT
IN ANY UNFILLED CELL OF A TIC-TAC-TOE BOARD.
THE GOAL IS TO MAKE THE SUM OF EACH ROW, COLUMN,
AND DIAGONAL EQUAL TO 15.

THAT PLAYER LOSES WHO FIRST MAKES THE SUM OF THE
THREE FIGURES IN ANY ROW, COLUMN, OR DIAGONAL
SOMETHING OTHER THAN 15.

A TIE GAME DRAWS A MAGIC SQUARE!!

THE COMPUTER WILL ASK YOU ON EACH MOVE WHICH
CELL YOU WISH TO OCCUPY, AND THE NUMBER YOU WISH
LIKE '3,7' IF YOU WISHED TO PUT A 7 IN CELL 3.

HERE ARE THE CELL NUMBERS:

1 2 3
4 5 6
7 8 9

INPUT YOUR MOVE -- CELL AND NUMBER? 

'''
        
        print("Expecting greetings...")
        expect(bas_process, expected_greetings)
        expect(c_process, expected_greetings)
        print("[+] TEST 1 - PASSED")

        print("Sending keys...")
        write(c_process, '1,4')
        write(bas_process, '1,4')
        print("[+] KEYS SENT")

        ans = ''' 
 4             0             0 
 0             0             0 
 0             0             0 

I MOVE TO CELL  2  WITH A  1 

 4             1             0 
 0             0             0 
 0             0             0 


INPUT YOUR MOVE -- CELL AND NUMBER? '''
        
        expect(bas_process, ans)
        expect(c_process, ans)
        print("[+] TEST 2 - PASSED")

        print("Sending keys...")
        write(c_process, '1,4')
        write(bas_process, '1,4')
        print("[+] KEYS SENT")

        ans = '''ILLEGAL MOVE ... AGAIN

INPUT YOUR MOVE -- CELL AND NUMBER? '''
        
        expect(bas_process, ans)
        expect(c_process, ans)
        print("[+] TEST 3 - PASSED")

        print("Sending keys...")
        write(c_process, '5,9')
        write(bas_process, '5,9')
        print("[+] KEYS SENT")

        ans = ''' 
 4             1             0 
 0             9             0 
 0             0             0 

I MOVE TO CELL  4  WITH A  2 

 4             1             0 
 2             0             0 
 0             0             0 


INPUT YOUR MOVE -- CELL AND NUMBER? '''
        
        expect(bas_process, ans)
        expect(c_process, ans)
        print("[+] TEST 4 - PASSED")

        print("Sending keys...")
        write(c_process, '8,5')
        write(bas_process, '8,5')
        print("[+] KEYS SENT")

        ans = ''' 
 4             1             0
 2             9             0
 0             5             0

I MOVE TO CELL  9  WITH A  8

 4             1             0
 2             9             0
 0             5             8

I LOSE -- YOU WIN!!

LET'S PLAY AGAIN. . .

INPUT YOUR MOVE -- CELL AND NUMBER? '''
        
        expect(bas_process, ans)
        expect(c_process, ans)
        print("[+] TEST 5 - PASSED")        

        print("[+] ALL TESTS PASSED")
    except Exception as ex:
        print(ex)

test()
