
int add (int a, int b){	//둘다 양수 기준
	
	int newNum = getNew();  // 새로운 수
	for(int i = 1 ; i < CIPHER_MAX; i++)
		Num[newNum][i] = Num[a][i] + Num[b][i]; // 각 자리 더하기

	for(int i = CIPHER_MAX - 1; i >= 1; i--)
		if(Num[newNum][i] >= 10){
			if(i == 1)
				sendError(ERROR_NUMBER_OVERFLOW);	// 정수가 50자리 보다 크다(에러표시)
			Num[newNum][i] -= 10; // 10의 자리면 10을 빼서 1의 자리로 만들기
			Num[newNum][i - 1]++;  // 다음 자리수에 1추가
		}
	
	return newNum;  //더한 수 반환
} 

int subtract(int a,int b){	//둘다 양수 기준
	int newNum = getNew();  //새로운 수
	
	if(compare(a,b) == -1){
		Num[newNum][0] = 1;	// - 부호
		int t = a;	// 큰수와 작은수 비교하여 바꾸기
		a = b;
		b = t;
	}
	for(int i = 1; i < CIPHER_MAX; i++)
		Num[newNum][i] = Num[a][i] - Num[b][i]; // 각 자리수 빼기
	
	for(int i =  CIPHER_MAX - 1; i >= 1; i--)
		if(Num[newNum][i] < 0){
			Num[newNum][i] += 10;  //자리수가 10의 자리면 10빼서 1의 자리만들기
			Num[newNum][i - 1]--;  //다음 자리수 1빼기
		}
	return newNum;
}
