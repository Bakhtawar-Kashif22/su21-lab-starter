.globl factorial

.data
# Input: n (located at label n)
n: .word 3

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit
    # Factorial function in RISC-V assembly
factorial:
    # Base case: if n <= 1, return 1
    li t1, 1
    blt a0, t1, Lreturn

    # Recursive case: compute (n-1)!
    addi sp, sp, -8
    sw ra, 0(sp)   # Save return address
    sw a0, 4(sp)   # Save n

    addi a0, a0, -1
    jal factorial  # Recursive call

    lw t0, 4(sp)   # Load n
    mul a0, t0, a0 # Compute n * (n-1)!

    lw ra, 0(sp)   # Restore return address
    addi sp, sp, 8 # Restore stack pointer
    jr ra          # Return
# Output: n! (returned in a0)
Lreturn:
    li a0, 1       # Return 1 for n <= 1
    jr ra
 




