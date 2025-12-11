	.file	"Threads7.c"
	.text
.Ltext0:
	.file 0 "/home/musman/Desktop/C/AdvC_Prog/Threads/Threads7" "Threads7.c"
	.globl	thr1_attr
	.bss
	.align 32
	.type	thr1_attr, @object
	.size	thr1_attr, 56
thr1_attr:
	.zero	56
	.globl	thr2_attr
	.align 32
	.type	thr2_attr, @object
	.size	thr2_attr, 56
thr2_attr:
	.zero	56
	.globl	mutex_lock1
	.align 32
	.type	mutex_lock1, @object
	.size	mutex_lock1, 40
mutex_lock1:
	.zero	40
	.globl	mutex_lock2
	.align 32
	.type	mutex_lock2, @object
	.size	mutex_lock2, 40
mutex_lock2:
	.zero	40
	.globl	cond_var1
	.align 32
	.type	cond_var1, @object
	.size	cond_var1, 48
cond_var1:
	.zero	48
	.globl	num_sh
	.align 4
	.type	num_sh, @object
	.size	num_sh, 4
num_sh:
	.zero	4
	.section	.rodata
	.align 8
.LC0:
	.string	"Thread 1 id = %ld,stack size = %li bytes \n"
	.align 8
.LC1:
	.string	"Thread 1 Accessing Shared Resource"
	.align 8
.LC2:
	.string	"Value In Thread 1 Function = %i\n"
	.align 8
.LC3:
	.string	"Thread 1 Failed to Acquire the lock"
	.align 8
.LC4:
	.string	"Thread 1 Freeing Shared Resource"
	.align 8
.LC5:
	.string	"Thread 1 Failed to release the lock"
	.text
	.globl	thread_func1
	.type	thread_func1, @function
thread_func1:
.LFB0:
	.file 1 "Threads7.c"
	.loc 1 21 1
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	.loc 1 21 1
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	.loc 1 23 1
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	thr1_attr(%rip), %rax
	movq	%rax, %rdi
	call	pthread_attr_getstacksize@PLT
	.loc 1 24 1
	movq	-32(%rbp), %rbx
	call	pthread_self@PLT
	.loc 1 24 1 is_stmt 0 discriminator 1
	movq	%rbx, %rdx
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	.loc 1 26 4 is_stmt 1
	leaq	mutex_lock1(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_lock@PLT
	.loc 1 26 3 discriminator 1
	testl	%eax, %eax
	jne	.L2
	.loc 1 26 44 discriminator 1
	leaq	mutex_lock1(%rip), %rax
	movq	%rax, %rsi
	leaq	cond_var1(%rip), %rax
	movq	%rax, %rdi
	call	pthread_cond_wait@PLT
	.loc 1 26 41 discriminator 1
	testl	%eax, %eax
	jne	.L2
	.loc 1 28 1
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	.loc 1 29 7
	movl	num_sh(%rip), %eax
	subl	$1, %eax
	movl	%eax, num_sh(%rip)
	.loc 1 30 1
	movl	num_sh(%rip), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L3
.L2:
	.loc 1 34 5
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L3:
	.loc 1 38 4
	leaq	mutex_lock1(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_unlock@PLT
	.loc 1 38 3 discriminator 1
	testl	%eax, %eax
	jne	.L4
	.loc 1 40 1
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L5
.L4:
	.loc 1 44 2
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L5:
	.loc 1 46 1
	movl	$0, %edi
	call	pthread_exit@PLT
	.cfi_endproc
.LFE0:
	.size	thread_func1, .-thread_func1
	.section	.rodata
	.align 8
.LC6:
	.string	"Thread 2 id = %ld,stack size = %li bytes \n"
	.align 8
.LC7:
	.string	"Thread 2 Signaling Condition Variable"
	.align 8
.LC8:
	.string	"Thread 2 Accessing Shared Resource"
	.align 8
.LC9:
	.string	"Value In Thread 2 Function = %i\n"
	.align 8
.LC10:
	.string	"Thread 2 Failed to Acquire the lock"
	.align 8
.LC11:
	.string	"Thread 2 Freeing Shared Resource"
	.align 8
.LC12:
	.string	"Thread 2 Failed to release the lock"
	.text
	.globl	thread_func2
	.type	thread_func2, @function
thread_func2:
.LFB1:
	.loc 1 50 1
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	.loc 1 50 1
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	.loc 1 52 1
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	thr2_attr(%rip), %rax
	movq	%rax, %rdi
	call	pthread_attr_getstacksize@PLT
	.loc 1 53 1
	movq	-32(%rbp), %rbx
	call	pthread_self@PLT
	.loc 1 53 1 is_stmt 0 discriminator 1
	movq	%rbx, %rdx
	movq	%rax, %rsi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	.loc 1 57 4 is_stmt 1
	leaq	cond_var1(%rip), %rax
	movq	%rax, %rdi
	call	pthread_cond_signal@PLT
	.loc 1 57 3 discriminator 1
	testl	%eax, %eax
	jne	.L8
	.loc 1 59 5
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L8:
	.loc 1 61 4
	leaq	mutex_lock1(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_lock@PLT
	.loc 1 61 3 discriminator 1
	testl	%eax, %eax
	jne	.L9
	.loc 1 63 1
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	.loc 1 64 7
	movl	num_sh(%rip), %eax
	addl	$1, %eax
	movl	%eax, num_sh(%rip)
	.loc 1 65 1
	movl	$1, %edi
	call	sleep@PLT
	.loc 1 66 1
	movl	num_sh(%rip), %eax
	movl	%eax, %esi
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L10
.L9:
	.loc 1 70 5
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L10:
	.loc 1 72 4
	leaq	mutex_lock1(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_unlock@PLT
	.loc 1 72 3 discriminator 1
	testl	%eax, %eax
	jne	.L11
	.loc 1 74 1
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L12
.L11:
	.loc 1 78 5
	leaq	.LC12(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L12:
	.loc 1 81 1
	movl	$0, %edi
	call	pthread_exit@PLT
	.cfi_endproc
.LFE1:
	.size	thread_func2, .-thread_func2
	.section	.rodata
	.align 8
.LC13:
	.string	"Default stack size = %li bytes \n"
	.align 8
.LC14:
	.string	"Creating threads with stack size = %li bytes \n"
.LC15:
	.string	"Thread 1 Creation has failed"
.LC16:
	.string	"Thread 2 Creation has failed"
	.align 8
.LC17:
	.string	"Mutex Lock 1 Creation has failed"
	.align 8
.LC18:
	.string	"Mutex Lock 2 Creation has failed"
.LC19:
	.string	"All threads are completed"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.loc 1 88 1
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	.loc 1 88 1
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 92 1
	leaq	thr1_attr(%rip), %rax
	movq	%rax, %rdi
	call	pthread_attr_init@PLT
	.loc 1 93 1
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	thr1_attr(%rip), %rax
	movq	%rax, %rdi
	call	pthread_attr_getstacksize@PLT
	.loc 1 94 1
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC13(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	.loc 1 95 11
	movq	$9000000, -16(%rbp)
	.loc 1 96 1
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	thr1_attr(%rip), %rax
	movq	%rax, %rdi
	call	pthread_attr_setstacksize@PLT
	.loc 1 98 1
	leaq	thr2_attr(%rip), %rax
	movq	%rax, %rdi
	call	pthread_attr_init@PLT
	.loc 1 99 1
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	thr2_attr(%rip), %rax
	movq	%rax, %rdi
	call	pthread_attr_getstacksize@PLT
	.loc 1 100 1
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC13(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	.loc 1 101 11
	movq	$400000, -16(%rbp)
	.loc 1 102 1
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	thr2_attr(%rip), %rax
	movq	%rax, %rdi
	call	pthread_attr_setstacksize@PLT
	.loc 1 104 1
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC14(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	.loc 1 106 4
	leaq	-32(%rbp), %rax
	movl	$0, %ecx
	leaq	thread_func1(%rip), %rdx
	leaq	thr1_attr(%rip), %rsi
	movq	%rax, %rdi
	call	pthread_create@PLT
	.loc 1 106 3 discriminator 1
	testl	%eax, %eax
	je	.L15
	.loc 1 108 5
	leaq	.LC15(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L15:
	.loc 1 111 4
	leaq	-24(%rbp), %rax
	movl	$0, %ecx
	leaq	thread_func2(%rip), %rdx
	leaq	thr2_attr(%rip), %rsi
	movq	%rax, %rdi
	call	pthread_create@PLT
	.loc 1 111 3 discriminator 1
	testl	%eax, %eax
	je	.L16
	.loc 1 113 5
	leaq	.LC16(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L16:
	.loc 1 116 4
	movl	$0, %esi
	leaq	mutex_lock1(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_init@PLT
	.loc 1 116 3 discriminator 1
	testl	%eax, %eax
	je	.L17
	.loc 1 118 5
	leaq	.LC17(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L17:
	.loc 1 121 4
	movl	$0, %esi
	leaq	mutex_lock2(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_init@PLT
	.loc 1 121 3 discriminator 1
	testl	%eax, %eax
	je	.L18
	.loc 1 123 5
	leaq	.LC18(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L18:
	.loc 1 126 1
	movq	-32(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_join@PLT
	.loc 1 127 1
	movq	-24(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_join@PLT
	.loc 1 128 1
	leaq	.LC19(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	.loc 1 130 1
	movl	$0, %edi
	call	pthread_exit@PLT
	.cfi_endproc
.LFE2:
	.size	main, .-main
.Letext0:
	.file 2 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h"
	.file 3 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h"
	.file 4 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h"
	.file 5 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h"
	.file 6 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
	.file 7 "/usr/include/pthread.h"
	.file 8 "/usr/include/unistd.h"
	.file 9 "/usr/include/stdio.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x649
	.value	0x5
	.byte	0x1
	.byte	0x8
	.long	.Ldebug_abbrev0
	.uleb128 0x13
	.long	.LASF74
	.byte	0xc
	.long	.LASF0
	.long	.LASF1
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x7
	.long	.LASF15
	.byte	0x3
	.byte	0xd6
	.byte	0x17
	.long	0x3a
	.uleb128 0x5
	.byte	0x8
	.byte	0x7
	.long	.LASF2
	.uleb128 0x5
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x14
	.byte	0x8
	.uleb128 0x8
	.long	0x48
	.uleb128 0x5
	.byte	0x1
	.byte	0x8
	.long	.LASF4
	.uleb128 0x5
	.byte	0x2
	.byte	0x7
	.long	.LASF5
	.uleb128 0x5
	.byte	0x1
	.byte	0x6
	.long	.LASF6
	.uleb128 0x5
	.byte	0x2
	.byte	0x5
	.long	.LASF7
	.uleb128 0x15
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x5
	.byte	0x8
	.byte	0x5
	.long	.LASF8
	.uleb128 0x3
	.long	0x7e
	.uleb128 0x5
	.byte	0x1
	.byte	0x6
	.long	.LASF9
	.uleb128 0xf
	.long	0x7e
	.uleb128 0xa
	.long	0x7e
	.long	0x9a
	.uleb128 0xb
	.long	0x3a
	.byte	0x3
	.byte	0
	.uleb128 0x3
	.long	0x79
	.uleb128 0x3
	.long	0x85
	.uleb128 0x16
	.byte	0x8
	.byte	0x2
	.byte	0x1c
	.byte	0x3
	.long	0xc8
	.uleb128 0x2
	.long	.LASF10
	.byte	0x2
	.byte	0x1e
	.byte	0x12
	.long	0x41
	.byte	0
	.uleb128 0x2
	.long	.LASF11
	.byte	0x2
	.byte	0x1f
	.byte	0x12
	.long	0x41
	.byte	0x4
	.byte	0
	.uleb128 0xd
	.byte	0x8
	.byte	0x2
	.byte	0x19
	.long	0xe9
	.uleb128 0x4
	.long	.LASF12
	.byte	0x2
	.byte	0x1b
	.byte	0x28
	.long	0xe9
	.uleb128 0x4
	.long	.LASF13
	.byte	0x2
	.byte	0x20
	.byte	0x5
	.long	0xa4
	.byte	0
	.uleb128 0x5
	.byte	0x8
	.byte	0x7
	.long	.LASF14
	.uleb128 0x7
	.long	.LASF16
	.byte	0x2
	.byte	0x21
	.byte	0x3
	.long	0xc8
	.uleb128 0x10
	.long	.LASF20
	.byte	0x10
	.byte	0x4
	.byte	0x33
	.byte	0x10
	.long	0x124
	.uleb128 0x2
	.long	.LASF17
	.byte	0x4
	.byte	0x35
	.byte	0x23
	.long	0x124
	.byte	0
	.uleb128 0x2
	.long	.LASF18
	.byte	0x4
	.byte	0x36
	.byte	0x23
	.long	0x124
	.byte	0x8
	.byte	0
	.uleb128 0x3
	.long	0xfc
	.uleb128 0x7
	.long	.LASF19
	.byte	0x4
	.byte	0x37
	.byte	0x3
	.long	0xfc
	.uleb128 0x10
	.long	.LASF21
	.byte	0x28
	.byte	0x5
	.byte	0x16
	.byte	0x8
	.long	0x1ab
	.uleb128 0x2
	.long	.LASF22
	.byte	0x5
	.byte	0x18
	.byte	0x7
	.long	0x6b
	.byte	0
	.uleb128 0x2
	.long	.LASF23
	.byte	0x5
	.byte	0x19
	.byte	0x10
	.long	0x41
	.byte	0x4
	.uleb128 0x2
	.long	.LASF24
	.byte	0x5
	.byte	0x1a
	.byte	0x7
	.long	0x6b
	.byte	0x8
	.uleb128 0x2
	.long	.LASF25
	.byte	0x5
	.byte	0x1c
	.byte	0x10
	.long	0x41
	.byte	0xc
	.uleb128 0x2
	.long	.LASF26
	.byte	0x5
	.byte	0x20
	.byte	0x7
	.long	0x6b
	.byte	0x10
	.uleb128 0x2
	.long	.LASF27
	.byte	0x5
	.byte	0x22
	.byte	0x9
	.long	0x64
	.byte	0x14
	.uleb128 0x2
	.long	.LASF28
	.byte	0x5
	.byte	0x23
	.byte	0x9
	.long	0x64
	.byte	0x16
	.uleb128 0x2
	.long	.LASF29
	.byte	0x5
	.byte	0x24
	.byte	0x14
	.long	0x129
	.byte	0x18
	.byte	0
	.uleb128 0x10
	.long	.LASF30
	.byte	0x30
	.byte	0x4
	.byte	0x5e
	.byte	0x8
	.long	0x214
	.uleb128 0x2
	.long	.LASF31
	.byte	0x4
	.byte	0x60
	.byte	0x19
	.long	0xf0
	.byte	0
	.uleb128 0x2
	.long	.LASF32
	.byte	0x4
	.byte	0x61
	.byte	0x19
	.long	0xf0
	.byte	0x8
	.uleb128 0x2
	.long	.LASF33
	.byte	0x4
	.byte	0x62
	.byte	0x10
	.long	0x214
	.byte	0x10
	.uleb128 0x2
	.long	.LASF34
	.byte	0x4
	.byte	0x63
	.byte	0x10
	.long	0x214
	.byte	0x18
	.uleb128 0x2
	.long	.LASF35
	.byte	0x4
	.byte	0x64
	.byte	0x10
	.long	0x41
	.byte	0x20
	.uleb128 0x2
	.long	.LASF36
	.byte	0x4
	.byte	0x65
	.byte	0x10
	.long	0x41
	.byte	0x24
	.uleb128 0x2
	.long	.LASF37
	.byte	0x4
	.byte	0x66
	.byte	0x10
	.long	0x214
	.byte	0x28
	.byte	0
	.uleb128 0xa
	.long	0x41
	.long	0x224
	.uleb128 0xb
	.long	0x3a
	.byte	0x1
	.byte	0
	.uleb128 0x7
	.long	.LASF38
	.byte	0x6
	.byte	0x1b
	.byte	0x1b
	.long	0x3a
	.uleb128 0xd
	.byte	0x4
	.byte	0x6
	.byte	0x20
	.long	0x251
	.uleb128 0x4
	.long	.LASF39
	.byte	0x6
	.byte	0x22
	.byte	0x8
	.long	0x8a
	.uleb128 0x4
	.long	.LASF40
	.byte	0x6
	.byte	0x23
	.byte	0x7
	.long	0x6b
	.byte	0
	.uleb128 0x7
	.long	.LASF41
	.byte	0x6
	.byte	0x24
	.byte	0x3
	.long	0x230
	.uleb128 0xf
	.long	0x251
	.uleb128 0x17
	.long	.LASF42
	.byte	0x38
	.byte	0x6
	.byte	0x38
	.byte	0x7
	.long	0x288
	.uleb128 0x4
	.long	.LASF39
	.byte	0x6
	.byte	0x3a
	.byte	0x8
	.long	0x288
	.uleb128 0x4
	.long	.LASF40
	.byte	0x6
	.byte	0x3b
	.byte	0xc
	.long	0x72
	.byte	0
	.uleb128 0xa
	.long	0x7e
	.long	0x298
	.uleb128 0xb
	.long	0x3a
	.byte	0x37
	.byte	0
	.uleb128 0x7
	.long	.LASF42
	.byte	0x6
	.byte	0x3e
	.byte	0x1e
	.long	0x262
	.uleb128 0xf
	.long	0x298
	.uleb128 0xd
	.byte	0x28
	.byte	0x6
	.byte	0x43
	.long	0x2d6
	.uleb128 0x4
	.long	.LASF43
	.byte	0x6
	.byte	0x45
	.byte	0x1c
	.long	0x135
	.uleb128 0x4
	.long	.LASF39
	.byte	0x6
	.byte	0x46
	.byte	0x8
	.long	0x2d6
	.uleb128 0x4
	.long	.LASF40
	.byte	0x6
	.byte	0x47
	.byte	0xc
	.long	0x72
	.byte	0
	.uleb128 0xa
	.long	0x7e
	.long	0x2e6
	.uleb128 0xb
	.long	0x3a
	.byte	0x27
	.byte	0
	.uleb128 0x7
	.long	.LASF44
	.byte	0x6
	.byte	0x48
	.byte	0x3
	.long	0x2a9
	.uleb128 0xd
	.byte	0x30
	.byte	0x6
	.byte	0x4b
	.long	0x31f
	.uleb128 0x4
	.long	.LASF43
	.byte	0x6
	.byte	0x4d
	.byte	0x1b
	.long	0x1ab
	.uleb128 0x4
	.long	.LASF39
	.byte	0x6
	.byte	0x4e
	.byte	0x8
	.long	0x31f
	.uleb128 0x4
	.long	.LASF40
	.byte	0x6
	.byte	0x4f
	.byte	0x1f
	.long	0x32f
	.byte	0
	.uleb128 0xa
	.long	0x7e
	.long	0x32f
	.uleb128 0xb
	.long	0x3a
	.byte	0x2f
	.byte	0
	.uleb128 0x5
	.byte	0x8
	.byte	0x5
	.long	.LASF45
	.uleb128 0x7
	.long	.LASF46
	.byte	0x6
	.byte	0x50
	.byte	0x3
	.long	0x2f2
	.uleb128 0x9
	.long	.LASF47
	.byte	0xa
	.byte	0x11
	.long	0x298
	.uleb128 0x9
	.byte	0x3
	.quad	thr1_attr
	.uleb128 0x9
	.long	.LASF48
	.byte	0xb
	.byte	0x11
	.long	0x298
	.uleb128 0x9
	.byte	0x3
	.quad	thr2_attr
	.uleb128 0x9
	.long	.LASF49
	.byte	0xd
	.byte	0x11
	.long	0x2e6
	.uleb128 0x9
	.byte	0x3
	.quad	mutex_lock1
	.uleb128 0x9
	.long	.LASF50
	.byte	0xe
	.byte	0x11
	.long	0x2e6
	.uleb128 0x9
	.byte	0x3
	.quad	mutex_lock2
	.uleb128 0x9
	.long	.LASF51
	.byte	0x10
	.byte	0x10
	.long	0x336
	.uleb128 0x9
	.byte	0x3
	.quad	cond_var1
	.uleb128 0x9
	.long	.LASF52
	.byte	0x12
	.byte	0x5
	.long	0x6b
	.uleb128 0x9
	.byte	0x3
	.quad	num_sh
	.uleb128 0x11
	.long	.LASF53
	.byte	0xdb
	.long	0x6b
	.long	0x3d9
	.uleb128 0x1
	.long	0x224
	.uleb128 0x1
	.long	0x3d9
	.byte	0
	.uleb128 0x3
	.long	0x48
	.uleb128 0x6
	.long	.LASF54
	.byte	0x7
	.value	0x30d
	.byte	0xc
	.long	0x6b
	.long	0x3fa
	.uleb128 0x1
	.long	0x3fa
	.uleb128 0x1
	.long	0x404
	.byte	0
	.uleb128 0x3
	.long	0x2e6
	.uleb128 0x8
	.long	0x3fa
	.uleb128 0x3
	.long	0x25d
	.uleb128 0x11
	.long	.LASF55
	.byte	0xca
	.long	0x6b
	.long	0x42c
	.uleb128 0x1
	.long	0x431
	.uleb128 0x1
	.long	0x43b
	.uleb128 0x1
	.long	0x440
	.uleb128 0x1
	.long	0x4a
	.byte	0
	.uleb128 0x3
	.long	0x224
	.uleb128 0x8
	.long	0x42c
	.uleb128 0x3
	.long	0x2a4
	.uleb128 0x8
	.long	0x436
	.uleb128 0x3
	.long	0x445
	.uleb128 0x18
	.long	0x48
	.long	0x454
	.uleb128 0x1
	.long	0x48
	.byte	0
	.uleb128 0x6
	.long	.LASF56
	.byte	0x7
	.value	0x175
	.byte	0xc
	.long	0x6b
	.long	0x470
	.uleb128 0x1
	.long	0x470
	.uleb128 0x1
	.long	0x2e
	.byte	0
	.uleb128 0x3
	.long	0x298
	.uleb128 0x6
	.long	.LASF57
	.byte	0x7
	.value	0x11d
	.byte	0xc
	.long	0x6b
	.long	0x48c
	.uleb128 0x1
	.long	0x470
	.byte	0
	.uleb128 0x6
	.long	.LASF58
	.byte	0x8
	.value	0x1d0
	.byte	0x15
	.long	0x41
	.long	0x4a3
	.uleb128 0x1
	.long	0x41
	.byte	0
	.uleb128 0x6
	.long	.LASF59
	.byte	0x7
	.value	0x461
	.byte	0xc
	.long	0x6b
	.long	0x4ba
	.uleb128 0x1
	.long	0x4ba
	.byte	0
	.uleb128 0x3
	.long	0x336
	.uleb128 0x8
	.long	0x4ba
	.uleb128 0x19
	.long	.LASF60
	.byte	0x7
	.byte	0xd3
	.byte	0xd
	.long	0x4d6
	.uleb128 0x1
	.long	0x48
	.byte	0
	.uleb128 0x6
	.long	.LASF61
	.byte	0x7
	.value	0x343
	.byte	0xc
	.long	0x6b
	.long	0x4ed
	.uleb128 0x1
	.long	0x3fa
	.byte	0
	.uleb128 0x6
	.long	.LASF62
	.byte	0x7
	.value	0x46d
	.byte	0xc
	.long	0x6b
	.long	0x509
	.uleb128 0x1
	.long	0x4bf
	.uleb128 0x1
	.long	0x3ff
	.byte	0
	.uleb128 0x6
	.long	.LASF63
	.byte	0x7
	.value	0x31a
	.byte	0xc
	.long	0x6b
	.long	0x520
	.uleb128 0x1
	.long	0x3fa
	.byte	0
	.uleb128 0x6
	.long	.LASF64
	.byte	0x9
	.value	0x16b
	.byte	0xc
	.long	0x6b
	.long	0x538
	.uleb128 0x1
	.long	0x9f
	.uleb128 0x1a
	.byte	0
	.uleb128 0x1b
	.long	.LASF75
	.byte	0x7
	.value	0x111
	.byte	0x12
	.long	0x224
	.uleb128 0x6
	.long	.LASF65
	.byte	0x7
	.value	0x16e
	.byte	0xc
	.long	0x6b
	.long	0x561
	.uleb128 0x1
	.long	0x43b
	.uleb128 0x1
	.long	0x566
	.byte	0
	.uleb128 0x3
	.long	0x2e
	.uleb128 0x8
	.long	0x561
	.uleb128 0x12
	.long	.LASF71
	.byte	0x57
	.byte	0x5
	.long	0x6b
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x5d3
	.uleb128 0xe
	.long	.LASF66
	.byte	0x57
	.byte	0xe
	.long	0x6b
	.uleb128 0x2
	.byte	0x91
	.sleb128 -52
	.uleb128 0xe
	.long	.LASF67
	.byte	0x57
	.byte	0x1a
	.long	0x9a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0xc
	.long	.LASF68
	.byte	0x59
	.byte	0xb
	.long	0x224
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0xc
	.long	.LASF69
	.byte	0x59
	.byte	0x13
	.long	0x224
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xc
	.long	.LASF70
	.byte	0x5a
	.byte	0x8
	.long	0x2e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.byte	0
	.uleb128 0x12
	.long	.LASF72
	.byte	0x31
	.byte	0x7
	.long	0x48
	.quad	.LFB1
	.quad	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x611
	.uleb128 0xe
	.long	.LASF73
	.byte	0x31
	.byte	0x1a
	.long	0x48
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0xc
	.long	.LASF70
	.byte	0x33
	.byte	0x8
	.long	0x2e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.byte	0
	.uleb128 0x1c
	.long	.LASF76
	.byte	0x1
	.byte	0x14
	.byte	0x7
	.long	0x48
	.quad	.LFB0
	.quad	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xe
	.long	.LASF73
	.byte	0x14
	.byte	0x1a
	.long	0x48
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0xc
	.long	.LASF70
	.byte	0x16
	.byte	0x8
	.long	0x2e
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0x21
	.sleb128 8
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x37
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x17
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 9
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 7
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 12
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x1f
	.uleb128 0x1b
	.uleb128 0x1f
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x17
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x87
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF33:
	.string	"__g_refs"
.LASF43:
	.string	"__data"
.LASF76:
	.string	"thread_func1"
.LASF72:
	.string	"thread_func2"
.LASF68:
	.string	"thread1"
.LASF69:
	.string	"thread2"
.LASF34:
	.string	"__g_size"
.LASF15:
	.string	"size_t"
.LASF51:
	.string	"cond_var1"
.LASF10:
	.string	"__low"
.LASF20:
	.string	"__pthread_internal_list"
.LASF71:
	.string	"main"
.LASF12:
	.string	"__value64"
.LASF44:
	.string	"pthread_mutex_t"
.LASF17:
	.string	"__prev"
.LASF23:
	.string	"__count"
.LASF13:
	.string	"__value32"
.LASF70:
	.string	"stacksize"
.LASF19:
	.string	"__pthread_list_t"
.LASF54:
	.string	"pthread_mutex_init"
.LASF47:
	.string	"thr1_attr"
.LASF63:
	.string	"pthread_mutex_lock"
.LASF7:
	.string	"short int"
.LASF18:
	.string	"__next"
.LASF52:
	.string	"num_sh"
.LASF61:
	.string	"pthread_mutex_unlock"
.LASF26:
	.string	"__kind"
.LASF45:
	.string	"long long int"
.LASF53:
	.string	"pthread_join"
.LASF55:
	.string	"pthread_create"
.LASF8:
	.string	"long int"
.LASF65:
	.string	"pthread_attr_getstacksize"
.LASF64:
	.string	"printf"
.LASF39:
	.string	"__size"
.LASF35:
	.string	"__g1_orig_size"
.LASF41:
	.string	"pthread_mutexattr_t"
.LASF27:
	.string	"__spins"
.LASF21:
	.string	"__pthread_mutex_s"
.LASF4:
	.string	"unsigned char"
.LASF57:
	.string	"pthread_attr_init"
.LASF66:
	.string	"argc"
.LASF30:
	.string	"__pthread_cond_s"
.LASF6:
	.string	"signed char"
.LASF14:
	.string	"long long unsigned int"
.LASF3:
	.string	"unsigned int"
.LASF74:
	.string	"GNU C99 13.3.0 -mtune=generic -march=x86-64 -g -O0 -std=c99 -fstack-usage -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection"
.LASF67:
	.string	"argv"
.LASF58:
	.string	"sleep"
.LASF16:
	.string	"__atomic_wide_counter"
.LASF75:
	.string	"pthread_self"
.LASF73:
	.string	"threadid"
.LASF5:
	.string	"short unsigned int"
.LASF9:
	.string	"char"
.LASF25:
	.string	"__nusers"
.LASF36:
	.string	"__wrefs"
.LASF32:
	.string	"__g1_start"
.LASF11:
	.string	"__high"
.LASF22:
	.string	"__lock"
.LASF60:
	.string	"pthread_exit"
.LASF46:
	.string	"pthread_cond_t"
.LASF2:
	.string	"long unsigned int"
.LASF28:
	.string	"__elision"
.LASF56:
	.string	"pthread_attr_setstacksize"
.LASF62:
	.string	"pthread_cond_wait"
.LASF37:
	.string	"__g_signals"
.LASF24:
	.string	"__owner"
.LASF49:
	.string	"mutex_lock1"
.LASF50:
	.string	"mutex_lock2"
.LASF31:
	.string	"__wseq"
.LASF42:
	.string	"pthread_attr_t"
.LASF38:
	.string	"pthread_t"
.LASF40:
	.string	"__align"
.LASF59:
	.string	"pthread_cond_signal"
.LASF29:
	.string	"__list"
.LASF48:
	.string	"thr2_attr"
	.section	.debug_line_str,"MS",@progbits,1
.LASF1:
	.string	"/home/musman/Desktop/C/AdvC_Prog/Threads/Threads7"
.LASF0:
	.string	"Threads7.c"
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
