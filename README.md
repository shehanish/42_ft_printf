# 42_ft_printf

## ft_printf Project

### Overview

The ft_printf project is a custom implementation of a simplified printf() function that uses variadic macros to manage different format specifiers. This exercise is part of the 42 school curriculum and helps me deepen my understanding of variadic functions, data type handling, and error management in C programming.

### Features

+ Variadic Format Handling: Utilizes variadic macros to support a variable number of arguments.
+ Format Specifiers: My ft_printf supports a range of commonly used format specifiers:
  + %c: Character output
        + %s: String output
        + %p: Pointer output
        + %d, %i: Signed decimal output
        + %u: Unsigned decimal output
        + %x, %X: Hexadecimal output
        + %%: Percentage sign
+ Libft Integration: Leverages existing libft functions to enhance code reuse and maintain consistency.
+ Error Handling: Deals with invalid input formats gracefully, ensuring a smooth user experience.

### Variadic Functions

Variadic functions allow users to pass a variable number and type of arguments to a function. My ft_printf() function utilizes variadic functions as follows:

+ Prototype: int ft_printf(const char *format, ...) returns the number of characters printed (excluding the NULL terminator) or -1 on error.
+ va_list: A data type that represents a list of arguments.
+ **va_start(args, format):** Initializes a va_listpointing to the first variable argument following theformat` string.
+ **va_arg(args, type):** Retrieves the next argument from args` using the specified type.
+ **va_end(args):** Cleans up the va_list`.

### Error Handling

+ My implementation follows Ubuntu's behavior for printf() error returns, with a function called check_error() to handle edge cases, such as a lone % at the end of a format string or followed only by spaces.

+ For NULL pointers, I've chosen to print (nil) as output.

### Testing

+ The test_ft_printf.c file includes various test cases that compare my ft_printf() implementation to the native printf() function.
+ After compiling the project library, create the test program using:

  shell

    cc -o TEST test_ft_printf.c libftprintf.a

+ Note: Expect and ignore the 'incomplete format specifier' warnings as part of the testing process.

Thank you for exploring my ft_printf project! Let me know if you have any feedback or suggestions.
