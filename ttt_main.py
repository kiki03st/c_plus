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
    # 게임 결과 확인
    result = game_result(board)
    
    if result == 1:  # 사용자가 이긴 경우
        return 100
    elif result == 2:  # 컴퓨터가 이긴 경우
        return -100
    elif result == 0:  # 무승부인 경우
        return 0
    if turn == 1: minimax_val = -100    # 사용자의 차례인 경우
    else: minimax_val = 100             # 컴퓨터의 차례인 경우
    for i in range(3):
        for j in range(3):
            if board[i][j] == 0:        # 빈 칸인 경우
                board[i][j] = turn      # 차례에 맞는 대상이 둠
                score = minimax(board, 3 - turn)    # 다른 대상의 차례로 재귀 호출(사용자 : 컴퓨터 / 컴퓨터 : 사용자)
                board[i][j] = 0         # 보드 되돌려두기
                if turn == 1: minimax_val = max(minimax_val, score) #사용자 차례인 경우, 최댓값 갱신
                else: minimax_val = min(minimax_val, score) #컴퓨터 차례인 경우, 최솟값 갱신
        return minimax_val

def computer(board):
    
    ### 현재 computer()함수는 빈곳에 랜덤하게 돌을 두도록 프로그래밍 되어있음
    ### 무조건 user를 상대로 [비기거나/이기도록] 미니맥스 알고리즘을 이용하여 다시 프로그래밍 하시오  
    ### computer() 함수와 minimax() 함수만 새로 작성하여 문제를 해결하시오
    row = -1
    col = -1
    score = 101    # score 초기값 지정(result보다 큰지 비교해야 하므로 최댓값 100을 초과한 101로 설정)

    for i in range(3):
        for j in range(3):
            if board[i][j] == 0:    # 빈칸인 경우
                board[i][j] = 2     # 컴퓨터가 뒀다고 가정
                result = game_result(board) # 컴퓨터가 뒀을 경우의 값 반환
                board[i][j] = 0     #보드 되돌리기
                if result == -100:  # 컴퓨터가 이긴다면
                    return i, j     # 좌표 반환(컴퓨터가 이길 수 있는 수 두기)
    
    for i in range(3):
        for j in range(3):
            if board[i][j] == 0:    # 빈칸인 경우
                board[i][j] = 1     # 사용자가 뒀다고 가정
                result = game_result(board) # 사용자가 뒀을 경우의 값 반환
                board[i][j] = 0     # 보드 되돌리기
                if result == 100:   # 사용자가 이긴다면
                    return i, j     # 좌표 반환(사용자가 이길 수 있는 수 차단)

    for i in range(3):
        for j in range(3):
            if board[i][j] == 0:    # 빈칸인 경우
                board[i][j] = 2     # 컴퓨터가 뒀다고 가정
                result = minimax(board, 1)  # 미니맥스 알고리즘을 통한 값 반환
                board[i][j] = 0     # 보드 되돌리기
                if result < score:  # 미니맥스 알고리즘을 통해 예측한 값이 score보다 작다면
                    score = result  # score 값을 result로 갱신
                    row = i     # 좌표 갱신
                    col = j     # 좌표 갱신

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
