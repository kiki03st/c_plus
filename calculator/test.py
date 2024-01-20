import requests
from lxml.html import parse
from io import StringIO

url = ''

num = int(input('찾아볼 항목을 선택하시오. \n\n1. 포켓몬 이름\n2. 기술 이름\n3. 특성 이름\n4. 타입 이름\n입력 : '))

if num in [1, 2, 3]:
	if num == 1:
		url = 'https://pokemon.fandom.com/ko/wiki/%EA%B5%AD%EA%B0%80%EB%B3%84_%ED%8F%AC%EC%BC%93%EB%AA%AC_%EC%9D%B4%EB%A6%84_%EB%AA%A9%EB%A1%9D'
	elif num == 2:
		url = 'https://pokemon.fandom.com/ko/wiki/%EA%B5%AD%EA%B0%80%EB%B3%84_%EA%B8%B0%EC%88%A0_%EC%9D%B4%EB%A6%84_%EB%AA%A9%EB%A1%9D'
	elif num == 3:
		url = 'https://pokemon.fandom.com/ko/wiki/%EA%B5%AD%EA%B0%80%EB%B3%84_%ED%8A%B9%EC%84%B1_%EC%9D%B4%EB%A6%84_%EB%AA%A9%EB%A1%9D'

	n = input('입력 : ')

	text = requests.get(url).text

	text_source = StringIO(text)
	parsed = parse(text_source)

	doc = parsed.getroot()

	tables = doc.findall('.//td')
	for i in range(len(tables)):
		name = tables[i].text_content().strip()
		if name == n:
			print(tables[i - 2].text_content().strip())
			break
elif num == 4:
	n = input('입력 : ')
	dic = {
		'NORMAL' : '노말',
		'FIRE' : '불꽃',
		'WATER' : '물',
		'GRASS' : '풀',
		'ELECTRIC' : '전기',
		'ICE' : '얼음',
		'FIGHTING' : '격투',
		'POISON' : '독',
		'GROUND' : '땅',
		'FLYING' : '비행',
		'PSYCHIC' : '에스퍼',
		'BUG' : '벌레',
		'ROCK' : '바위',
		'GHOST' : '고스트',
		'DRAGON' : '드래곤',
		'DARK' : '악',
		'STEEL' : '강철',
		'FAIRY' : '페어리'
	}
	print(dic[n])
