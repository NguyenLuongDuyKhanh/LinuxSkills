	.arch armv8-a
	.file	"Ex1_TestASMCode.cpp"
	.text
.Ltext0:
	.file 0 "/home/pi/Workplace/LinuxSkills/ComputerRegisters" "Ex1_TestASMCode.cpp"
	.align	2
	.global	main
	.type	main, %function
main:
.LFB0:
	.file 1 "Ex1_TestASMCode.cpp"
	.loc 1 1 12
	.cfi_startproc
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	.loc 1 2 9
	mov	w0, 123
	str	w0, [sp, 12]
.LBB2:
	.loc 1 4 14
	str	wzr, [sp, 8]
	.loc 1 4 5
	b	.L2
.L3:
	.loc 1 5 10 discriminator 3
	ldr	w1, [sp, 12]
	ldr	w0, [sp, 8]
	add	w0, w1, w0
	str	w0, [sp, 12]
	.loc 1 4 5 discriminator 3
	ldr	w0, [sp, 8]
	add	w0, w0, 1
	str	w0, [sp, 8]
.L2:
	.loc 1 4 20 discriminator 1
	ldr	w0, [sp, 8]
	cmp	w0, 9
	ble	.L3
.LBE2:
	.loc 1 7 14
	mov	w0, 0
	.loc 1 8 1
	add	sp, sp, 16
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
.Letext0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.4byte	0x7f
	.2byte	0x5
	.byte	0x1
	.byte	0x8
	.4byte	.Ldebug_abbrev0
	.uleb128 0x2
	.4byte	.LASF2
	.byte	0x21
	.4byte	.LASF0
	.4byte	.LASF1
	.8byte	.Ltext0
	.8byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x3
	.4byte	.LASF3
	.byte	0x1
	.byte	0x1
	.byte	0x5
	.4byte	0x7b
	.8byte	.LFB0
	.8byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x7b
	.uleb128 0x1
	.string	"a"
	.byte	0x2
	.byte	0x9
	.4byte	0x7b
	.uleb128 0x2
	.byte	0x91
	.sleb128 -4
	.uleb128 0x4
	.8byte	.LBB2
	.8byte	.LBE2-.LBB2
	.uleb128 0x1
	.string	"i"
	.byte	0x4
	.byte	0xe
	.4byte	0x7b
	.uleb128 0x2
	.byte	0x91
	.sleb128 -8
	.byte	0
	.byte	0
	.uleb128 0x5
	.byte	0x4
	.byte	0x5
	.string	"int"
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
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
	.uleb128 0x2
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
	.uleb128 0x3
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
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7a
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
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
	.uleb128 0x8
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.4byte	0x2c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x8
	.byte	0
	.2byte	0
	.2byte	0
	.8byte	.Ltext0
	.8byte	.Letext0-.Ltext0
	.8byte	0
	.8byte	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF2:
	.string	"GNU C++17 12.2.0 -mlittle-endian -mabi=lp64 -g -fasynchronous-unwind-tables"
.LASF3:
	.string	"main"
	.section	.debug_line_str,"MS",@progbits,1
.LASF1:
	.string	"/home/pi/Workplace/LinuxSkills/ComputerRegisters"
.LASF0:
	.string	"Ex1_TestASMCode.cpp"
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
