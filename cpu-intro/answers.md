# description
실행하고 옵션에 대한 간략 설명
```
'-l' : process list를 추가함.
  A:B 꼴 
  A: process를 구성하는 instruction 수 
  B: instruction이 cpu 또는 IO를 사용하는 chance
'-c' : cpu 활성 상태를 보여줌
'-p' : stat을 보여줌
'-S' : process가 IO를 issue했을 때 반응을 결정.
  SWITCH_ON_END: IO도중에 다른 프로세스로 switch하지 않도록 함
  SWITCH_ON_IO: IO를 할 때 다른 프로세스로 cpu를 넘김
'-I' : IO가 끝날 때 동작을 결정
  IO_RUN_LATER: IO가 끝난 process가 바로 실행되지 않음. 
  IO_RUN_IMMEDIATE: IO가 끝나면 바로 cpu를 가져옴
```
# 문제풀이
## 1
cpu utilization: 100%
: -c 옵션을 이용해 시각화할 수 있고, -p 옵션을 이용해 사용률을 볼 수 있음
## 2
두 개의 process 중, 첫 번째 프로세스는 4개의 ins와 0%의 IO가 있으며
두 번째 프로세스는 1개의 ins와 이 경우, 무조건 IO이다. 
따라서, 총 소요시간은 4 + IO시작~종료까지 걸리는 시간이 된다.
## 3
이번 경우에는, 처음 실행되는 프로세스가 IO 응답을 대기하는 동안, 두 번째 프로세스가 cpu를 점유하기 때문에, 시간이 대폭 줄어들게 된다. (불필요하게 기다리는 시간이 줄어듦.)
## 4
3번 경우와 다르게, IO동안 process가 cpu를 넘겨주지 않도록 하였으므로, 두 번째 process의 state는 ready 상태로 계속 대기하게 된다. 결국, 시간은 줄지 않는다.
## 5
3번과 마찬가지의 결과가 나타난다.
## 6
별다른 것 없는 결과이다.
## 7
IO_RUN_IMMEDIATE flag를 통해 IO가 끝나자마자 cpu소유권을 가져오므로, 불필요하게 프로세스를 유지하면서 기다릴 필요가 없어진다.
## 8
