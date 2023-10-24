def printMemberInfo(name, email, major, grade):
    print('name \t : ', name)
    print('email \t : ', email)
    print('major \t : ', major)
    print('grade \t : ', grade)
    print('-' * 30)

printMemberInfo('Mr. kim', 'kim@gmail.com', 'art', 1)

printMemberInfo(grade = 4, major = 'computer', email = 'abc@gmail.com', name = 'Mr. hong')
printMemberInfo(major = 'sport', grade = 2, name = 'Mr. cong', email = 'def@gmail.com')
printMemberInfo(email = 'ghi@gmail.com', major = 'music', name = 'Mr. wang', grade = 1)
#함수의 매개변수 작성 시에는 (매개변수) = (Value)와 같이 매개변수를 정확히 지정해주면 매개변수 작성 순서와 상관없이 값을 집어넣을 수 있음
