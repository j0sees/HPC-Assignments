# HPC: Assignment 1: Optimization

## Time

##### Summary of the the timining results

|optimization levels	 | average time over 1000 runs in secounds|
|---------------------|----------------------------------------|
|O0			| 3.263373371466|
|O1			| 0.374157216214|
|O2			| 0.001258400473|
|O3			| 0.001234995911|
|Os			| 0.001248916584|
|Og			| 0.372963288267|

#### Discussion of the assembler code
In the following we will discuss the  assembler code considering the different optimization levels.
In the discussion we will not explain every line of code in detail. 
Instead we focus on the differences between the different optimization levels.
A detailed explanation of the assembler code is included in the Appendix A. 

##### O0
The assembler code for the level O0 optimization is not optimized.
While comparing it to the other assembler codes which use a higher optimization level we realized that it
uses different directives. For example it is the only one which uses the following CFI-directives:

* .cfi_def_cfa_offset
* .cfi_def_cfa_register
* .cfi_offset register, offset
* .cfi_def_cfa

The meaning of the single CFI-directive is explained in the appendix A, as well as other assembly code directives.
Also we want to emphasize that it is the only assembler code which uses the pop from stack and push to stack.
Last but not least the code moves much more data between registers and to and from memory than the others.

##### O1
This assembler code is more compact. It does not move as much data between registers and it does not use the stack anymore.

##### O2 and O3
The assembler code of O2 and O3 is the same. 
The compiler divides code into two parts. One part is used many times and is called the hot part (`.LHOT`) the other part is used seldom and is called (`.LCOLD`). Also there is no more jumping but instead a xor comparison. 

Another difference is that the code implements the `.p2align 4,,15`. The first expression `4` is the power-of-two byte alignment required. `.p2align 4` will advance the location counter to  `2*2*2*2 = 16` bytes. The second expression is the value to be used as padding. If it is empty, like in our case, the padding size is equal to zero. The third expression is the maximum number of bytes for padding, in this case it is `15` and maximum.

##### Os
The only difference between O2, O3 and Os is that Os does not use padding.

##### Og
Finally the optimization for debugging does not use `HOT` and `COLD` code areas anymore and introduces jumps again.

## Inlining

For the average time, over 10000 runs, we got the following timings:
 
|inlining	|with method call |
|---------------|-----------------|
|0.0026708748799|0.0025726909274  |
 
As expected the version with the inlining is faster. One possible explanation for this is that the program does not have to resolve the call of the method `mul_cpx()` from a different file.
 
## Locality

##### Summary of the the timining results

|program name			| average time over 10000 runs in seconds |
|-------------------------------|-----------------------------------------|
|locality: O0			| 0.018141724701300000000|
|locality: O3			| 0.018138879311100000000|
|locality Reimplemented sum: O0	| 0.015351182755300000000|
|locality Reimplemented sum: O3	| 0.014818448262400000000|

 * We reimplemented the functions "row_sums" and "col_sums" as a function "sumsRowCol". By doing this we eliminated a for loop and a function call. 
 * For the first implementation of "locality" the program runs in average very fast, in about 18 ms. The difference between the runs with and without full optimization is not really noticeable, although the executable compiled with the O3 flag is slightly faster. The "reimplemented sum" is, again, only slightly faster than the original code regardless of the optimization flag used.
 * The conclusion is that for this example the major improvement in terms of performance was the reimplementation of the summing scheme.

## Indirect addressing

##### Summary of the the timining results

|program name			| average time over 10000 runs in seconds |
|-------------------------------|-----------------------------------------|
|indirect_addressing_O0:	|0.01464258956100000000|
|indirect_addressing_O3:	|0.01348622991800000000|
|direct_addressing_O0:		|0.00884674441600000000|
|direct_addressing_O3:		|0.00898247884300000000|

 * As in the locality task, for this task there is a slight time difference between indirect and direct addressing but not a noticeable one depending on the optimization flags.

 * For indirect addressing an auxiliar p vector is used. In our case this vector is full with data. That is the reason why there is no gain in performance and the program actually runs slower. 
 
 * According to the benchmarks direct_addressing runs faster and in this case that is the expected result. 

## Valgrind 
 
* The output logfile of valgrind indicates, that at exit of the programm 4000 bytes of memory are still in use. The program makes two memory allocations but frees only one, so there is a memory leak. Details for the memory leak are enumerated in the leak summary and in this particular case the indication is that the 4000 bytes of memory are definitely lost. These 4000 bytes correspond to the allocation of 1000 spaces for an integer pointer. We cannot explain the other allocation which is actually freed since we didn't do that explicitly in the program.

## Profiling
 
 * According to the "flat profile" provided by the gprof tool the time required for a run of the sum program is 20 ns. The bash timings differ a little bit since the average for over 1000 runs was 13.4 ns approximately.
 
 * Analyzing the locality.c.gcov file, one can observe that the most frequently run parts of the program were the for loops. These loops performed the sumations over rows and columns for the matrix. This result is as expected. In our implementation these parts were lines 52, 54, 123, 125, 143 and 145. Each executed about 1001000 times.


# Appendix

## Appendix A: Assembler

*** 
.cfi_startproc
Beginning of each function. Initializes some internal data structures.

.cfi_endproc
is used at the end of a function where it closes its unwind entry previously opened by .cfi_startproc, and emits it to .eh_frame.

.cfi_def_cfa_offset
modifies a rule for computing CFA. Register remains the same, but offset is new. Note that it is the absolute offset that will be added to a defined register to compute CFA address.

.cfi_def_cfa_register
modifies a rule for computing CFA. From now on register will be used instead of the old one. Offset remains the same.

.cfi_offset register, offset
Previous value of register is saved at offset offset from CFA.

.cfi_def_cfa
Defines a rule for computing CFA as: take address from register and add offset to it.

SOURCE: https://sourceware.org/binutils/docs/as/CFI-directives.html#CFI-directives
***

.size name , expression
This directive sets the size associated with a symbol name. The size in bytes is computed from expression which can make use of label arithmetic. This directive is typically used to set the size of function symbols.

SOURCE: https://sourceware.org/binutils/docs/as/Size.html#Size
***


.ident
This directive is used by some assemblers to place tags in object files. The behavior of this directive varies depending on the target. When using the a.out object file format, as simply accepts the directive for source-file compatibility with existing assemblers, but does not emit anything for it. When using COFF, comments are emitted to the .comment or .rdata section, depending on the target. When using ELF, comments are emitted to the .comment section.

SOURCE: https://sourceware.org/binutils/docs/as/Ident.html#Ident
***


SOURCE: https://sourceware.org/binutils/docs/as/Ident.html#Ident
***

.section name
Use the .section directive to assemble the following code into a section named name.
This directive is only supported for targets that actually support arbitrarily named sections; on a.out targets, for example, it is not accepted, even with a standard a.out section name.

@progbits
section contains data 

SOURCE: https://sourceware.org/binutils/docs/as/Section.html#Section
***

Note that the assembly code has three different kinds of elements:

  Directives begin with a dot and indicate structural information useful to the assembler, linker, or debugger. 
  but are not in and of themselves assembly instructions. 
  For example, .file simply records the name of the original source file. 
  .data indicates the start of the data section of the program, while 
  .text indicates the start of the actual program code. 
  .string indicates a string constant within the data section, and 
  .globl main indicates that the label main is a global symbol that can be accessed by other code modules.

  Labels end with a colon and indicate by their position the association between names and locations. 
  For example, the label .LC0: indicates that the immediately following string should be called .LC0. 
  The label main: indicates that the instruction pushq %rbp is the first instruction of the main function. 
  By convention, labels beginning with a dot are temporary local labels generated by the compiler, 
  while other symbols are user-visible functions and global variables.

Instructions are the actual assembly code (pushq %rbp), typically indented to visually distinguish them from directives and labels.
***
  
%rax	%rbx	%rcx	%rdx	%rsi	%rdi	%rbp	%rsp	%r8	%r9	%r10	%r11	%r12	%r13	%r14	%r15
We say almost general purpose because earlier versions of the processors intended for each register to be used for a specific purpose, 
and not all instructions could be applied to every register. As the design developed, 
new instructions and addressing modes were added to make the various registers almost equal.
A few remaining instructions, particularly related to string processing, require the use of %rsi and %rdi. 
In addition, two registers are reserved for use as the stack pointer (%rsp) and the base pointer (%rbp). 
The final eight registers are numbered and have no specific restrictions.  
***

mov
The first instruction that you should know about is the MOV instruction, which moves data between registers and to and from memory.

movl %esp, %ebp
movl is the name of the instruction, and the percent signs indicate that esp and ebp

Suffix	Name	Size
B	BYTE	1 byte (8 bits)
W	WORD	2 bytes (16 bits)
L	LONG	4 bytes (32 bits)
Q	QUADWORD	8 bytes (64 bits)
***

Basic Arithmetic
ADD, SUB, IMUL  
***

Comparisons and Jumps
Using the JMP instruction, we may create a simple infinite loop that counts up from zero using the %eax register.

`
	      MOVQ $0, %rax
loop:
        INCQ %rax
        JMP loop
`

To define more useful structures such as terminating loops and if-then statements,
we must have a mechanism for evaluating values and changing program flow. 
In most assembly languages, these are handled by two different kinds of instructions: compares and jumps.

Instruction	Meaning
JE	Jump If Equal
JNE	Jump If Not Equal
JL	Jump If Less Than
JLE	Jump If Less or Equal
JG	Jump if Greater Than
JGE	Jump If Greater or Equal

All comparisons are done with the -----> CMP <-----
***


The Stack
The stack is an auxiliary data structure used primarily to record the function call history of the program along with local variables that do not fit in registers.
Of course, pushing to and popping from the stack referred to by %rsp is so common, that the two operations have their own instructions that behave exactly as above:
PUSHQ %rax
POPQ  %rax
***


RET               # return to caller
***


SOURCE: https://www3.nd.edu/~dthain/courses/cse40243/fall2015/intel-intro.html
***


‘cltq’ -->  is the same as ‘cdqe’:
‘cdqe’ — sign-extend dword in ‘%eax’ to quad in ‘%rax’ (x86-64 only)

SOURCE: https://www.cosc.brocku.ca/Offerings/3P95/nxt/doc/as.pdf
***

Suffixes

The suffixes you mention all appear to be debugging related, as they are all defined under gcc/dwarf2out.c on GCC 4.8.2 and DWARF2 is a major debugging information format for ELF:

#define FUNC_BEGIN_LABEL  "LFB"
#define FUNC_END_LABEL    "LFE"
#define BLOCK_BEGIN_LABEL "LBB"
#define BLOCK_END_LABEL   "LBE"
ASM_GENERATE_INTERNAL_LABEL (loclabel, "LVL", loclabel_num);

SOURCE: http://stackoverflow.com/questions/24787769/what-are-lfb-lbb-lbe-lvl-loc-in-the-compiler-generated-assembly-code
SOURCE: http://www.nasm.us/doc/nasmdoc3.html#section-3.9
***

p2align[wl] abs-expr, abs-expr, abs-expr

Pad the location counter (in the current subsection) to a particular storage boundary. 
The first expression (which must be absolute) is the number of low-order zero bits the location counter must have after advancement. 
For example '.p2align 3' advances the location counter until it a multiple of 8. If the location counter is already a multiple of 8, no change is needed.
The second expression (also absolute) gives the fill value to be stored in the padding bytes. It (and the comma) may be omitted. 
If it is omitted, the padding bytes are normally zero. However, on some systems, 
if the section is marked as containing code and the fill value is omitted, the space is filled with no-op instructions.

SOURCE: https://sourceware.org/binutils/docs/as/P2align.html#P2align
***
