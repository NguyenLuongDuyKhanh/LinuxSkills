	.arch armv8-a
	.file	"Ex1_TestASMCode.cpp"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB0:
	.cfi_startproc
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
#APP
// 2 "Ex1_TestASMCode.cpp" 1
	KHANH_LABEL_1
// 0 "" 2
#NO_APP
	mov	w0, 123
	str	w0, [sp, 12]
#APP
// 4 "Ex1_TestASMCode.cpp" 1
	KHANH_LABEL_2
// 0 "" 2
#NO_APP
	str	wzr, [sp, 8]
	b	.L2
.L3:
	ldr	w1, [sp, 12]
	ldr	w0, [sp, 8]
	add	w0, w1, w0
	str	w0, [sp, 12]
	ldr	w0, [sp, 8]
	add	w0, w0, 1
	str	w0, [sp, 8]
.L2:
	ldr	w0, [sp, 8]
	cmp	w0, 9
	ble	.L3
	mov	w0, 0
	add	sp, sp, 16
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
