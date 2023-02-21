from os import path
try:
    import sys, resource
    _stack_type = 0
except:
    import sys, threading
    _stack_type = 1
    
__MAX_STACK = 1 << 27
_infile = None

def fin(inpath = None):
    global _infile
    if inpath is not None and path.exists(inpath):
        _infile = open(inpath, 'r')
    else:
        _infile = None

input = lambda : _infile.readline() if _infile is not None else sys.stdin.readline()



def f(p, q):
    if p == q:
        return 0
    elif p < q:
        return 2 * f(p, q - p) + 1
    elif p > q:
        return 2 * f(p - q, q) + 2

def main():
    while True: 
        line = input()
        if line != "":
            p, q = list(map(int,line.split()))
            print(f(p, q))
        else:
            break

        
if __name__ == '__main__':
    if _stack_type == 0:
        resource.setrlimit(resource.RLIMIT_STACK, (__MAX_STACK,-1))
        sys.setrecursionlimit(__MAX_STACK)
        main()
    elif _stack_type == 1:
        sys.setrecursionlimit(__MAX_STACK)
        threading.stack_size(__MAX_STACK)
        thread = threading.Thread(target=main)
        thread.start()
        thread.join()