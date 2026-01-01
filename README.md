# Simple CLI calculator

## Requirements

- C compilator

## How to run

Simply use script compile_script.sh

```
./compile_script.sh main.c
```

Or u can just compile it yourself using gcc

```
gcc main.c -lm -o calc
./calc
```
## Usage
Right now you can use operations and sings as:
- +,-,*,/
- (,)
- sqrt(),ln(),sin()

```
$> 2 + 2 * 2
6
$> (2 + 3) * 5
25
$> sqrt(16) + 1
5
$> 10 / 4
2.5
$> exit
```