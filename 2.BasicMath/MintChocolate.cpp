// 20302 : 민트초코
#include <iostream>
using namespace std;
const int MAX = 1e5; // 수식을 이루는 수의 개수 (100,000)

int prime[MAX+1], exponent[MAX + 1];

void isPrime() {    //아레스토테네스의 체를 응용해 소인수 분해 표 만들기
    for (int i = 2; i <= MAX; i++) {
        prime[i] = i; //자기자신(=위치)으로 초기화
    }

    for (int i = 2; i * i < MAX; i++) {
        if (prime[i] == i) { // 해당 수(i)에가 소수일 경우에
            for (int j = i * i; j <= MAX; j += i) { //해당 수(i)의 배수들은 i로 약분가능 -> i대입
                if (prime[j] == j) //별도로 지정된 소수가 없을 경우
                    prime[j] = i; // i는 j의 소인수중 최소 -> 왜 최소인지는 소인수 분해에서
            }
        }
    }

}

void countExp(int a, char c) {

    int cnt;
    if (c == '*') cnt = 1; // *면 ++
    else cnt = -1;// / 이면 --

    while (a > 1) {
        exponent[prime[a]] += cnt; //소인수 분해하여 exponent칸 갱신
        a = a / prime[a]; //최소 소인수로 나누어 다른 소인수들의 값도 구해주어야함
    }

}

//연산이 끝난 후, 소인수의 지수에 음수 있는지 판단 -> 있다면 유리수 -> true 리턴
bool isYuri() {
    for (int i = 2; i <= MAX; i++) {
        if (exponent[i] < 0) //유리수
            return true;
    }
    return false;//정수
}


int main() {

    int N;
    cin >> N;

    int num;
    char op;

    isPrime();

    //맨 처음 수는 연산자가 없어서 '*'로 넣어줌
    cin >> num;
    if (num == 0) {
        cout << "mint chocolate" << "\n";
        return 0;
    }

    countExp(num, '*');
    N--;

    while (N--) {

        cin >> op >> num;

        if (num == 0) {
            cout << "mint chocolate" << "\n";
            return 0;
        }
        countExp(abs(num), op);

    }


    if (isYuri())
        cout << "toothpaste" << "\n";
    else
        cout << "mint chocolate" << "\n";

    return 0;

}
