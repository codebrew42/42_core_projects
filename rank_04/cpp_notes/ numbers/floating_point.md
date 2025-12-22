# 부동 소수점(Floating Point)의 이해와 프로그래밍 가이드

## 1. Accuracy(정확도) vs Precision(정밀도)

컴퓨터가 숫자를 다루는 두 가지 상반된 방식입니다.

* **Integer (정수)**
    * **High Accuracy:** 2는 정확히 2입니다. 데이터 손실이 없습니다.
    * **Low Precision:** 소수점 이하를 표현하지 못합니다. (예: `5 / 2 = 2`)
* **Float (부동 소수점)**
    * **Low Accuracy:** $1/3$과 같은 무한 소수를 완벽히 저장할 수 없어 근사치를 저장합니다.
    * **High Precision:** 매우 작은 단위까지 세밀하게 표현하여 정보의 밀도를 유지합니다.
```cpp
float x = 0.1f + 0.2f;
if (x == 0.3f) {  // false일 수 있음!
    // 실행 안 될 수 있음
}
```
* **Fixed-Point**
	* 정확+빠름
	* 단점: 제한된 범위
	* 용도: 그래픽, 사운드, 게임
	

---

## 2. IEEE-754 32-bit Float 표현식
```text
seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm
31 (MSB)                        0 (LSB)
```

* **s (1 bit):** 부호 (0: 양수, 1: 음수)
* **e (8 bits):** 지수 (Exponent). 실제 지수에 127을 더한 값(Bias)이 저장됨.
* **m (23 bits):** 가수 (Mantissa). 유효 숫자를 저장.

### 값 계산 공식

* **Implied 1:** 가수의 맨 앞은 항상 `1.xxx` 형태이므로, 숫자 1은 메모리에 저장하지 않고 약속으로 처리합니다.
* **Shift-127 (Bias):** 음수 지수를 표현하기 위해 실제 지수에 127을 더해 저장합니다.
* **특수값:**
	* **0:** 모든 비트가 0
	* **1.0:** `0x3f800000` (e=127이 되어)
	* **+inf:** 지수 비트 모두 1, 가수 0
	* **NaN (Not a Number):** 지수 비트 모두 1, 가수 ≠ 0

---

## 3. 프로그래밍 주의사항 (Pitfalls & Solutions)

### 3.1. 동등 비교 (Equality)

부동 소수점은 미세한 오차 때문에 `==` 비교가 거의 항상 실패합니다.

* **Bad:** `if (a == b)` 또는 단순히 작은 상수(`EPSILON`)와 비교.
* **Good (상대 오차 비교):** 숫자의 크기에 비례하는 오차 범위를 사용합니다.

```cpp
bool nearlyEqual(float a, float b, float epsilon = 1e-5) {
    if (a == b) return true;
    float diff = fabs(a - b);
    float norm = fmin(fabs(a) + fabs(b), FLT_MAX);
    return diff < epsilon * fmax(1.0f, norm);
}

```

### 3.2. 오버플로우 (Overflow)

중간 계산 과정에서 자료형의 한계를 넘는 경우입니다.

* **Bad:** `sqrt(re*re + im*im)` -> `re`가 $10^{200}$이면 제곱 시 바로 Overflow 발생.
* **Good:** 큰 값을 밖으로 빼내어 숫자의 규모를 줄인 뒤 계산합니다.

```cpp
double magnitude(double re, double im) {
    re = fabs(re); im = fabs(im);
    if (re < im) std::swap(re, im);
    if (re == 0.0) return 0.0;
    double r = im / re;
    return re * sqrt(1.0 + r * r); // 숫자의 규모를 안전하게 유지
}

```

### 3.3. 정밀도 손실 (Loss of Significance)

#### 1) 근접한 값의 뺄셈 (Canceled bits)

* **Problem:** `1.0000001 - 1.0000000` 계산 시 유효 숫자 대부분이 사라지고 오차만 남습니다.
* **Good:** 수식을 재배열하여 직접적인 뺄셈을 피합니다.
* 예:  계산 시, 분자 유동화를 통해  로 변환.



#### 2) 작은 값의 누적 (Swamping)

* **Problem:** 큰 수에 아주 작은 수를 더하면 무시됩니다. (`1.0 + 1e-8 = 1.0`)
* **Good:** **Kahan Summation** 알고리즘을 사용하거나, 작은 수들끼리 먼저 더한 뒤 큰 수에 합칩니다.

#### 3) 피드백 루프 (Error Accumulation)

* **Bad:** `x += inc` (루프를 돌 때마다 이전 오차가 다음 단계로 전이됨)
* **Good:** `x = i * inc` (항상 기준점으로부터 새로 계산하여 오차 전이를 차단)

---

## 4. Best Practices

1. **정수 활용:** 소수점 계산이 필요한 '돈' 같은 데이터는 100을 곱해 정수(Cent 단위)로 처리하세요.
2. **Type Casting 주의:** 
	* `float`(32bit)는 약 7자리 정밀도입니다.
	* 32bit `int`의 최대값은 10자리이므로, 큰 정수를 `float`로 바꾸면 데이터가 깨집니다.
	* 큰 정수를 다룰 때는 반드시 `double`을 사용하세요.


3. **연산 순서:** 곱셈을 먼저 하여 유효 숫자를 확보하고, 나눗셈은 나중에 하는 것이 유리합니다.

---

## 5. 왜 고정 소수점(Fixed-Point)을 쓰는가?

부동 소수점의 오차와 하드웨어 의존성을 해결하기 위해 정수만을 사용해 소수를 표현합니다.

* **성능:** FPU(부동소수점 연산장치)가 없는 저사양 프로세서에서 압도적으로 빠름.
* **확정성(Determinism):** 어떤 기기에서 실행해도 비트 단위까지 동일한 결과 보장 (멀티플레이 게임 동기화에 필수).
* **적용 분야:** 임베디드 시스템, 금융 시스템, 물리 엔진, 오디오 신호 처리.

