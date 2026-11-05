// AArch64 Linux, GNU assembler syntax.
// Standard ASCII: rows 0..7, columns 0..F.
// Control characters (0..31 and 127) are displayed as '.'.

    .section .rodata
.Lheader:
    .asciz "    0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F"
.Lrow_format:
    .asciz "%X |"
.Lcell_format:
    .asciz " %c "

    .text
    .global main
    .type main, %function
main:
    // Keep the stack 16-byte aligned and preserve callee-saved registers.
    stp x29, x30, [sp, -48]!
    mov x29, sp
    stp x19, x20, [sp, 16]

    adrp x0, .Lheader
    add x0, x0, :lo12:.Lheader
    bl puts

    mov w19, 0                  // row: high 4 bits
.Lrow:
    adrp x0, .Lrow_format
    add x0, x0, :lo12:.Lrow_format
    mov w1, w19
    bl printf

    mov w20, 0                  // column: low 4 bits
.Lcolumn:
    lsl w1, w19, 4
    orr w1, w1, w20             // ASCII code = (row << 4) | column

    cmp w1, 32
    b.lo .Lcontrol
    cmp w1, 127
    b.ne .Lprint
.Lcontrol:
    mov w1, 46                  // '.'
.Lprint:
    adrp x0, .Lcell_format
    add x0, x0, :lo12:.Lcell_format
    bl printf

    add w20, w20, 1
    cmp w20, 16
    b.lo .Lcolumn

    mov w0, 10                  // newline
    bl putchar
    add w19, w19, 1
    cmp w19, 8
    b.lo .Lrow

    mov w0, 0
    ldp x19, x20, [sp, 16]
    ldp x29, x30, [sp], 48
    ret
    .size main, .-main

    .section .note.GNU-stack,"",%progbits
