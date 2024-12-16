# 비트 계산기

과제 1. unsigned char 변수의 값을 비트단위로 찍어주기
        - 지역변수에 특정 값을 하나 넣음
        - 비트 단위로 분해해서 0 이면 0 출력, 1 이면 1 출력



PrintBinaryFromDecimal 함수

[in] decimal : unsigned char  
[out] void


[Description] : 0b00000001 비트 마스크를 이용해서 unsigned char 타입의 decimal 변수에 저장된 값을 1비트씩 화면에 출력합니다.



과제 2. unsigned short (16bit) 변수의 각 비트를 컨트롤 하기

        - unsigned short 변수 = 0 으로 초기값 가짐.
        - 키보드로 1 ~ 16의 비트 자리 입력을 받음
        - 1 / 0  을 사용자로부터 받아서 지정된 자리의 비트를 0 또는 1로 바꿔줌.
    
        - 다른 위체이 입력된 기존 데이터는 보존이 되어야 함



ControlBitFlags 함수

[in] void
[out] void

[Description] : 0b00000001 비트 마스크를 이용해서 unsigned short 타입 변수에 비트단위로 정보를 저장할 수 있습니다. 0 ~ 15 번째의 비트 중 선택하여 0 또는 1 값을 세팅할 수 있습니다.



과제 3. unsigned int (32bit) 변수를 바이트 단위로 사용하기

        - unsigned int 변수 = 0 초기값 가짐
        - 키보드로 1 ~ 4 의 바이트 위치를 입력 받고
        - 해당 위치에 넣을 데이터 0 ~ 255 를 입력 받음
        - 사용자가 입력한 바이트 위치에 해당 값을 넣음
    
        - 데이터가 입력 되면 바이트 단위로 쪼개서 출력 & 4바이트 16진수 출력
        - 기존 데이터는 보존이 되어야 하며
        - 입력된 바이트 위치의 데이터는 기존 값을 지우고 넣음.



ControlBitFlagsToByteUnit 함수

[in] void
[out] void

[Description] : 0x000000FF 비트 마스크를 이용해서 unsigned int 타입 변수에 바이트 단위로 정보를 저장할 수 있습니다. 0 ~ 3 번째의 바이트 중 선택하여 0 ~ 255 까지의 값을 세팅할 수 있습니다.
