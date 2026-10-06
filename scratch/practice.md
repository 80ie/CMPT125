## B1
>
> A student writes void swap(int a, int b) and calls swap(x, y) from main, but x and y don't change.
> Explain why, using the words "pass by value" and "stack frame".
> Then give the corrected function header and call.

Function parameters are pass by value, meaning the function receives copies. x and y are local to main's stack frame.
`void swap(int *a, int *b)`
`swap(&x, &y)`

## B2
>
> What is wrong with this function? What could happen when the caller uses the returned pointer?
>
> ```c
> int *make_array(void) {
>     int arr[5] = {1, 2, 3, 4, 5};
>     return arr;
> }
> ```
>

The stack's local variables will have been recycled.

## B3
>
> Do an exact count of how many times printf is called by this code, as a function of N.
> Then give the Big-O.
>
> ```c
> for (int i = 0; i < N; i++) {
>     for (int j = 0; j < N; j++) {
>         printf("*");
>         printf(" ");
>     }
>     printf("\n");
> }
> ```
>

= O(N² + N² + N)
= **O(N²)**

## B4
>
> Explain why log₂N = O(log₁₀N). (Hint: change of base.)

Change in base is a change in constant factor, both equal `log N`

## B6
>
> A program is run as `./prog hello 42`. What is `argc`? What is `argv[1]`? Is `argv[2]` the integer 42?
> Explain.
