# ARM registers

## Registers in AArch32 state
In all Arm processors in AArch32 state, the following registers are available and accessible in any processor mode:

15 general-purpose registers R0-R12, the Stack Pointer (SP), and Link Register (LR).
1 Program Counter (PC).
1 Application Program Status Register (APSR).
Note:
SP and LR can be used as general-purpose registers, although Arm deprecates using SP other than as a stack pointer.
Additional registers are available in privileged software execution. Arm processors have a total of 43 registers. The registers are arranged in partially overlapping banks. There is a different register bank for each processor mode. The banked registers give rapid context switching for dealing with processor exceptions and privileged operations.

The additional registers in Arm processors are:

2 supervisor mode registers for banked SP and LR.
2 abort mode registers for banked SP and LR.
2 undefined mode registers for banked SP and LR.
2 interrupt mode registers for banked SP and LR.
7 FIQ mode registers for banked R8-R12, SP and LR.
2 monitor mode registers for banked SP and LR.
1 Hyp mode register for banked SP.
7 Saved Program Status Register (SPSRs), one for each exception mode.
1 Hyp mode register for ELR_Hyp to store the preferred return address from Hyp mode.

## Registers in AArch64 state
In AArch64 state, the following registers are available:

Thirty-one 64-bit general-purpose registers X0-X30, the bottom halves of which are accessible as W0-W30.
Four stack pointer registers SP_EL0, SP_EL1, SP_EL2, SP_EL3.
Three exception link registers ELR_EL1, ELR_EL2, ELR_EL3.
Three saved program status registers SPSR_EL1, SPSR_EL2, SPSR_EL3.
One program counter.
All these registers are 64 bits wide except SPSR_EL1, SPSR_EL2, and SPSR_EL3, which are 32 bits wide.

Most A64 integer instructions can operate on either 32-bit or 64-bit registers. The register width is determined by the register identifier, where W means 32-bit and X means 64-bit. The names Wn and Xn, where n is in the range 0-30, refer to the same register. When you use the 32-bit form of an instruction, the upper 32 bits of the source registers are ignored and the upper 32 bits of the destination register are set to zero.

There is no register named W31 or X31. Depending on the instruction, register 31 is either the stack pointer or the zero register. When used as the stack pointer, you refer to it as SP. When used as the zero register, you refer to it as WZR in a 32-bit context or XZR in a 64-bit context.

## Understand asm code 
In assembly language (ASM), lines that begin with a period (.) typically indicate a directive or pseudo-instruction. These directives are not actual machine instructions; instead, they provide instructions to the assembler on how to process the program.

For example:

.data - Defines the section of the code where data is stored (e.g., variables, constants).

.text - Marks the section containing executable instructions.

.globl - Declares a symbol (like a function or variable) as global, making it accessible from other files.

.word, .byte, .ascii - Used for defining data (e.g., allocating memory or initializing values).

.LFB0: local function begin. The 0 is a numerical identifier assigned by the compiler to uniquely identify a specific function. For example, .LFB0: would mark the beginning of the first function in the compiled program, .LFB1: would mark the next, and so on.

.L3: local label. It might act as a target for a jump instruction (e.g., jmp .L3) or a conditional branch (e.g., je .L3 if a condition is met).

.Ldebug_info0: These labels may mark the beginning or location of debugging-related sections, such as variable information, function boundaries, or line number mappings.Debugging tools like GDB (GNU Debugger) use this information to correlate the compiled machine code with the original source code, making it easier to debug programs.

.loc directive in assembly language is used to provide debugging information, linking the machine code to the source code.
Example:
    .loc 1 5 10 discriminator 3
    This directive essentially says: "The following assembly instruction corresponds to     source file 1, line 5, column 10, and belongs to a specific path identified by  discriminator 3."

The specific directives can vary depending on the assembler being used (e.g., NASM, GAS). Let me know if you'd like an example or further clarification!

## Inline assembly in C
The directives #APP #NO_APP is meant to surround the inline asm code to separate it from the rest of the compiler-generated assembly. See the inline lable in C

## References
https://developer.arm.com/documentation/100076/0100/Instruction-Set-Overview/Overview-of-AArch32-state/Registers-in-AArch32-state?lang=en
https://developer.arm.com/documentation/dui0801/l/Overview-of-AArch64-state/Registers-in-AArch64-state
https://developer.arm.com/documentation/den0013/d/Introduction-to-Assembly-Language/Introduction-to-the-GNU-Assembler/Assembler-directives