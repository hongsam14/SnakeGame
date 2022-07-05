# SnakeGame

## Manual
### 게임 규칙
-	뱀은 0.5초에 한 칸씩 움직인다.
-	뱀은 상하좌우로 움직일 수 있으며, 벽에 닿거나 머리가 몸으로 가면 게임이 끝난다.
-	빈 공간에 Item이 나타나며, Item은 나타난 후 10초 뒤에 사라진다.
-	벽에 게이트가 생기며, 게이트로 들어가면 반대 게이트로 나온다.
### 뱀의 이동
-	  : Head
-	  : Body
-	뱀은 상하좌우로 움직일 수 있다. 키보드의 방향키로 움직인다. 다른 키를 입력하면 종료된다.
-	↑ : 상
-	↓ : 하
-	← : 좌
-	→ : 우
-	뱀의 머리가 몸이나 벽에 닿으면 게임이 종료된다
### 아이템
-	Item은 Growth Item과 Poison Item이 있다.
-	  : Growth Item
-	이 아이템을 먹으면 뱀의 길이가 1 증가한다.
-	생성되고 10초 뒤에 사라진다.
-	  : Poison Item
-	이 아이템을 먹으면 뱀의 길이가 1 감소한다.
-	생성되고 10초 뒤에 사라진다.
-	이 아이템을 먹고 뱀의 길이가 3 이하가 되면 게임이 종료된다.
### 게이트
-	  : Gate
-	게이트 입구로 들어가면 반대 게이트로 나온다.
-	게이트를 통과하면 해당 게이트는 사라진다.
### 미션
-	B : 현재 몸 길이 / 가장 길었던 몸 길이
-	+ : Growth Item을 먹은 횟수 
-	– : Poison Item을 먹은 횟수
-	G : Gate를 통과한 횟수

## 설치 방법
프로젝트는 Linux, MacOS 환경에서 실행 가능하다.
### Linux, MacOS
```
./install.sh
```
Make를 하기 이전에 'install.sh' bash파일을 실행시켜 ncurses를 설치한다.
```
make
```
Makefile을 실행시켜 실행파일을 만든다.
```
./SnakeGame
```
아무 인자를 넘겨주지 않는다면 가장 기본 맵인 21 * 21 크기의 맵에서 게임을 하게 된다.
```
./SnakeGame sample_2.map
```
main 인수로 .map파일을 넘겨주게 된다면 해당 맵에서 게임을 플레이할 수 있다.

## 활용 library
### STL Container
- vector
- pair

### ncurses
- 화면 생성, 크기조절 : initscr, endwin, resize_term
- 색상을 초기화 : start_color, init_color, COLOR_PAIR
-	테두리를 출력 : border
-	커서 숨김. 런타임동안 표준 출력 스트림으로 출력되는 정보를 숨긴다. 입력받을 때 확장된 아스키 코드의 값을 받도록 한다. :  keypad, curs_set, noecho
-	창을 생성한다. : newwin, delwin
-	창 테두리를 출력한다 : wborder
-	창의 원하는 상대좌표부터 string을 출력한다. : mvwprintw

## 부록
- github team : https://github.com/Kookmin-Univ-C-programming
- repo:  https://github.com/Kookmin-Univ-C-programming/SnakeGame
- pdcurses repo: https://github.com/Kookmin-Univ-C-programming/SnakeGame_PDCURSES
- project milestones: https://github.com/Kookmin-Univ-C-programming/SnakeGame/milestones
- project kanban board: https://github.com/Kookmin-Univ-C-programming/SnakeGame/projects/1
- project Discussions: https://github.com/Kookmin-Univ-C-programming/SnakeGame/discussions

