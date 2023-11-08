f = open('linear_regression.txt', mode = 'r')	#linear_regression.txt 파일 데이터를 입력받을 파일 입출력 객체 f 생성
arr = []	#데이터를 저장할 리스트 arr 생성
for i in f.readlines():	#f.readlines()를 통해 받아온 리스트를 순서대로 i의 값으로 지정
    index, worked_hours, number_of_dolls = i.split()	#파일 내용 한줄의 내용을 각각 index, worked_hours, number_of_dolls로 분할해서 입력
    worked_hours += ' hours'	#worked_hours에 단위인 hours 붙이기
    number_of_dolls += ' dolls'	#number_of_dolls에 단위인 dolls 붙이기
    arr.append([index, worked_hours, number_of_dolls])	#index, worked_hours, number_of_dolls를 리스트로 묶어 arr에 저장하기
f.close()	#파일 입출력 종료
print('1열 : 인덱스')
print('2열 : 작업 시간 (Hours Worked)')
print('3열 : 인형 수 (Number of Dolls)')
print()
print('출력할 데이터의 행을 입력해주세요 : ', end = '')	#출력할 데이터의 행 입력받기
n = int(input())
print(', '.join(arr[n - 1]))	#입력받은 행 속 리스트 속 요소들을.(쉼표)를 기준으로 하나의 문장으로 붙이기

