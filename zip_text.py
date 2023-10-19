import os
import sys

def sort_arr(dir_list):
    name = ['' for _ in range(len(dir_list))]
    for i in dir_list:
        i = i[:-4]
        number, filename = i.split('^')
        name[int(number) - 1] = filename
    return name

def main():
    cnt = 1
    if len(sys.argv) < 2:
        print('Error : No Directory')
        return
    for i in range(1, len(sys.argv)):
        line = ''
        os.chdir(os.getcwd() + '/' + sys.argv[i])
        dir_arr = os.listdir()
        cpp_arr = []
        for p in dir_arr:
            if p[-4:] == '.cpp':
                cpp_arr.append(p)
        arr = sort_arr(cpp_arr)
        for j in range(len(arr)):
            cpp_name = str(j + 1) + '^' + arr[j] + '.cpp'
            path = os.path.join(os.getcwd(), cpp_name)
            try:
                f = open(path, mode = 'r')
            except:
                re_name = "_".join(cpp_name.split())
                os.rename(cpp_name, re_name)
                cpp_name = re_name
                path = os.path.join(os.getcwd(), cpp_name)
                f = open(path, mode = 'r')
            line+='//' + str(j + 1) + '. '  + arr[j]  + '\n'
            cnt+=1
            for k in f.readlines():
                line+=k
            f.close()
            line+='\n\n'
        f = open(os.getcwd() + '/' + sys.argv[i] + '.txt', mode = 'w')
        f.write(line)
        f.close()
        print(sys.argv[i] + ' Success.')

if __name__ == "__main__":
    main()
