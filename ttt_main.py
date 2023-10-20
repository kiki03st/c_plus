### 객체지향 / 인공지능 설계 프로젝트 HW1
### 학번 : 20XXXXXX
### 이름 : 000
### 제출일자 : 22-09-XX

import random

def board_visualization(board):
    ### 틱택토 게임 출력 함수  
    for i_idx in range(3):
        for j_idx in range(3):
            
            if board[i_idx][j_idx] == 0: # not occupied
                print("▨", end='')
            elif board[i_idx][j_idx] == 1: # user
                print("○", end='')
            elif board[i_idx][j_idx] == 2: # computer
                print("×", end='')
            else:
                pass
        print()        
    
def board_turn(board, row, col, val):
    
    if 0 <= row < 3 and 0 <= col < 3:
        if board[row][col] == 0:
            board[row][col] = val
            return 1
        else:
            print("그곳에 돌을 둘 수 없습니다. 다시 입력하세요.")
            return 0
    else:
        print("그곳에 돌을 둘 수 없습니다. 다시 입력하세요.")
        return 0
        
    
def win_condition(v1,v2,v3): # 사용자 승리 return 100, 컴퓨터 승리 return -100, 무승부 return 0
    if v1 == v2 == v3:  
        if v1 == 1: return 100
        elif v2 == 2: return -100
        else: return 0
    else:
        return 0
        
    
def game_result(board): # 사용자 승리 return 100, 컴퓨터 승리 return -100, 무승부 return 0
    result = 0
    # check rows
    for i_idx in range(3):
        result = win_condition(board[i_idx][0],board[i_idx][1],board[i_idx][2])      
        if result != 0: return result
      
    # check cols
    for i_idx in range(3):
        result = win_condition(board[0][i_idx],board[1][i_idx],board[2][i_idx])
        if result != 0: return result
        
    #check diagonals
    result = win_condition(board[0][0],board[1][1],board[2][2])      
    if result != 0: return result
    result = win_condition(board[0][2],board[1][1],board[2][0])      
    if result != 0: return result
        
    return result

def position():
    row = int(input("돌을 놓을 행을 입력하세요 (0~2):"))
    col = int(input("돌을 놓을 열을 입력하세요 (0~2):"))
    
    return row, col



def minimax(board, turn):
    # board : 현재 틱택토 보드
    # turn : user 또는 computer의 차례
    
    # hint
    # 1. minimax함수에서는 사람이 이기면 큰 수 (+100), 컴퓨터가 이기면 작은수 (-100), 비기면 중간값(0) 반환 - game_result() 함수 활용
    # 2. ① 사용자가 둔 수 이후에 대한 탐색과 ② 컴퓨터가 둔 수 이후에 대한 탐색을 재귀적’으로 수행
    #    단, 사용자는 값을 최대화 하는쪽으로 / 컴퓨터는 값을 최소화 하는 쪽으로 탐색 
    #    재귀적으로 탐색을 수행하다보면 승패가 결정된 값이 반환됨
    # 1 - user / 2 - computer
    # 100 - user / -100 - computer
    minimax_val = 0
    def line(board, turn):      #자기 차례에서 1수만 두면 이길 수 있는 경우의 수 구하기
        line_arr=[]
        dot = (0, 0)
        for i in range(3):
            cnt = []
            for j in range(3):
                if board[i][j] == turn:
                    cnt+=1
                elif board[i][j] == 0:
                    dot = (i, j)
                    continue
                else:
                    cnt = -1
                    break
            if cnt == 2:
                line_arr.append(dot)

        for j in range(3):
            cnt = 0
            for i in range(3):
                if board[i][j] == turn:
                    cnt+=1
                elif board[i][j] == 0:
                    dot = (i, j)
                    continue
                else:
                    cnt = -1
                    break
            if cnt == 2:
                line_arr.append(dot)
        
        cnt = 0
        for i in range(3):
            if board[i][2 - i] == turn:
                cnt+=1
            elif board[i][2 - i] == 0:
                dot = (i, 2 - i)
                continue
            else:
                cnt = -1
                break
        if cnt == 2:
            line_arr.append(dot)

        cnt = 0
        for i in range(3):
            if board[2 - i][i] == turn:
                cnt+=1
            elif board[2 - i][i] == 0:
                dot = (2 - i, i)
                continue
            else:
                cnt = -1
                break
        if cnt == 2:
            line_arr.append(dot)
        line_cnt = len(set(line_arr))
        return line_cnt

    # minimax 함수의 재귀를 통해서 value 또는 minimax_val의 값을 반환 가능하게 됨
    # 재귀로서 불러들인 minimax 함수의 리턴값을 어떻게 이용해야할까?
    # result == (2 * turn - 3) * (-100) 의 조건은 결국 최소 2번의 재귀가 반복되면 무용지물이 됨
    # 현재 반환될 수 있는 값은 value,minimax_val 두 가지
    # value의 반환은 항상 어느 한쪽이 이기는 상태로 끝남
    # minimax_val값의 변동 조건은?
    # minimax 함수의 존재 의의는?
    # computer가 하나의 수를 뒀을 때, computer가 만날 수 있는 최악의 조건을 가정하는 함수
    # minimax 함수의 흐름은 다음과 같은 순위에 따라 정해짐
    # 1. 현재 나의 차례에 게임을 끝낼 수 있는 수가 있다면 반환
    # 2. 다음 상대 차례에 상대가 이기는 상황이 나오는 경우, 그 수를 막음
    # 3. 만약 이 두가지 수가 존재하지 않는 경우, 최대한 막기 어려운 수를 둠
    # 막기 어려운 수란 어떠한 수를 두었을 떄, 막아야 하는 자리가 2개 이상인 수를 의미함
    # 4. 모든 조건이 성립하지 않는 경우, 다음 수로 한 줄을 완성할 수 있는 수를 둠
'''
    value = game_result(board)
    if value == (2 * turn - 3) * (-100):
        return value
    for i in range(3):
        for j in range(3):
            if board[i][j] == 0:
                board[i][j] = turn
                result = minimax(board, 3 - turn)
                board[i][j] = 0
                if r 
'''
    value = game_result(board)  #현재 상황에서 승패 또는 무승부 값을 측정
    if value != 0:  #만약 승패가 결정되었다면
        return value    #승패 여부 반환
    for i in range(3):
        for j in range(3):
            if board[i][j] == 0:
                board[i][j] = turn
                if turn == 1:   #현재 차례가 user라면
                    result = minimax(board, 2)  #차례가 computer로 넘어갔을 때의 승패 여부를 반환
                    minimax_val = max(result, minimax_val)  #result와 minimax_val 중에서 더 큰 값을 minimax_val로 지정
                else:   #현재 차례가 computer라면
                    result = minimax(board, 1)
                    minimax_val = min(result, minimax_val)
                board[i][j] = 0
    return minimax_val


def computer(board):
    
    ### 현재 computer()함수는 빈곳에 랜덤하게 돌을 두도록 프로그래밍 되어있음
    ### 무조건 user를 상대로 [비기거나/이기도록] 미니맥스 알고리즘을 이용하여 다시 프로그래밍 하시오  
    ### computer() 함수와 minimax() 함수만 새로 작성하여 문제를 해결하시오
    row = -1
    col = -1
    zero = False
    for i in range(3):
        for j in range(3):
            if board[i][j] == 0:
                board[i][j] = 2
                result = minimax(board, 1)
                if result == -100:
                    return row, col

    return row, col    


### 게임 시작
print("게임 시작")
board = [[0,0,0],[0,0,0],[0,0,0]]
board_visualization(board)

for i_idx in range(5): # 플레이어는 최대 5번 돌을 둔다
    ###### User ######
    print("============= Your turn =============")
    row, col = position()
    while board_turn(board, row, col,1) == 0:
        row, col = position()
        
    board_visualization(board)
    if game_result(board) == 100:
        print("사용자가 승리하였습니다.")
        break
    elif game_result(board) == -100:
        print("컴퓨터가 승리하였습니다.")
        break      
    ########################
    
    if i_idx == 4: #9번을 넘어가서 두는 경우 제외
        break
    
    ###### Computer ######
    print("============= Computer =============")
    row, col = computer(board) # computer 함수를 다시 코딩 하시오
    board_turn(board, row, col, 2)
    board_visualization(board)   
    if game_result(board) == 100:
        print("사용자가 승리하였습니다.")
        break
    elif game_result(board) == -100:
        print("컴퓨터가 승리하였습니다.")
        break
    ########################

    
if game_result(board) == 0:
    print("비겼습니다.")
