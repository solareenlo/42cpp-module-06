# 42cpp-module-06

### ex02
- [dynamic_cast](https://en.cppreference.com/w/cpp/language/dynamic_cast)
- [ダウンキャスト(dynamic_cast)](http://yohshiy.blog.fc2.com/blog-entry-15.html)

### ex01
- [C++と 4 つのキャスト演算](https://www.yunabe.jp/docs/cpp_casts.html)
  - static_cast: 暗黙の型変換が行われることを明示的に示す演算子
  - dynamic_cast: base class のポインタを derived class のポインタにキャストする演算子
  - reinterpret_cast: ポインタ型を他のポインタ型に強制的に変換する演算子
    - または，整数型を任意の型のポインタに変換する演算子
  - const_cast: ポインタ型，参照型の const や volatile を無効化する演算子

### ex00
#### 方針
- `-inf` < `-DBL_MAX` < `-inff` < `-FLT_MAX` < `INT_MIN` < `CHR_MIN` < `-FLT_MIN` < `-DBL_MIN` < `0` < `DBL_MIN` < `FLT_MIN` < `CHR_MIN` < `INT_MAX` < `FLT_MAX` < `+inff` < `DBL_MAX` < `+inf`
- このような大小関係で `char`, `int`, `float`, `double` に値を設定したり，キャストしたりした場合に範囲外になるとエラーにした
- `int` にキャストした場合は小数点以下が切り捨て
- `nan`, `+nan`, `-nan`, `nanf`, `+nanf`, `-nanf` は例外処理
- long は `2^24` までしか整数を正しく保存することができない
  - 仮数部が 23 bit までしかないので
- double は `2^53` までしか整数を正しく保存することができない
  - 仮数部が 52 bit までしかないので

#### 小数点の桁数表示
- [【C++】小数点の桁数を指定する方法と注意点【cout／iostream】](https://marycore.jp/prog/cpp/stream-format-float/)

#### float
- [Convert INT_MAX to float and then back to integer.](https://stackoverflow.com/questions/23420783/convert-int-max-to-float-and-then-back-to-integer/23423240)
- [int to float conversion produces a warning?](https://stackoverflow.com/questions/7775129/int-to-float-conversion-produces-a-warning)
- [FLP34-C. 浮動小数点の型変換は変換後の型の範囲に収まるようにする](https://www.jpcert.or.jp/sc-rules/c-flp34-c.html)
- [浮動小数点数型と誤差 float 型](https://www.cc.kyoto-su.ac.jp/~yamada/programming/float.html)
```c++
for (int a = 16777210; a < 16777224; a++) {
    float b = a;
    int c = b;
    std::cout << "a=" << a;
    std::cout << " c=" << c;
    std::cout << " b=0x" << std::bitset<32>(b) << std::endl;
}
```
```shell
a=16777210 c=16777210 b=0x00000000111111111111111111111010
a=16777211 c=16777211 b=0x00000000111111111111111111111011
a=16777212 c=16777212 b=0x00000000111111111111111111111100
a=16777213 c=16777213 b=0x00000000111111111111111111111101
a=16777214 c=16777214 b=0x00000000111111111111111111111110
a=16777215 c=16777215 b=0x00000000111111111111111111111111
a=16777216 c=16777216 b=0x00000001000000000000000000000000
a=16777217 c=16777216 b=0x00000001000000000000000000000000
a=16777218 c=16777218 b=0x00000001000000000000000000000010
a=16777219 c=16777220 b=0x00000001000000000000000000000100
a=16777220 c=16777220 b=0x00000001000000000000000000000100
a=16777221 c=16777220 b=0x00000001000000000000000000000100
a=16777222 c=16777222 b=0x00000001000000000000000000000110
a=16777223 c=16777224 b=0x00000001000000000000000000001000
```
```c++
for (int a = -16777224; a < -16777210; a++) {
    float b = a;
    int c = b;
    std::cout << "a=" << a;
    std::cout << " c=" << c;
    std::cout << " b=0x" << std::bitset<32>(b) << std::endl;
}
```
```shell
a=-16777224 c=-16777224 b=0x11111110111111111111111111111000
a=-16777223 c=-16777224 b=0x11111110111111111111111111111000
a=-16777222 c=-16777222 b=0x11111110111111111111111111111010
a=-16777221 c=-16777220 b=0x11111110111111111111111111111100
a=-16777220 c=-16777220 b=0x11111110111111111111111111111100
a=-16777219 c=-16777220 b=0x11111110111111111111111111111100
a=-16777218 c=-16777218 b=0x11111110111111111111111111111110
a=-16777217 c=-16777216 b=0x11111111000000000000000000000000
a=-16777216 c=-16777216 b=0x11111111000000000000000000000000
a=-16777215 c=-16777215 b=0x11111111000000000000000000000001
a=-16777214 c=-16777214 b=0x11111111000000000000000000000010
a=-16777213 c=-16777213 b=0x11111111000000000000000000000011
a=-16777212 c=-16777212 b=0x11111111000000000000000000000100
a=-16777211 c=-16777211 b=0x11111111000000000000000000000101
```

#### union
- [Can a union be initialized in the declaration?](https://stackoverflow.com/questions/2148989/can-a-union-be-initialized-in-the-declaration)

#### max, min
- [std::numeric_limits](https://cpprefjp.github.io/reference/limits/numeric_limits.html)

#### 型変換
- [strtol](http://www9.plala.or.jp/sgwr-t/lib/strtol.html)
- [strtod](http://www9.plala.or.jp/sgwr-t/lib/strtod.html)
- INT_MIN, INT_MAX は C++03, C++11 から
