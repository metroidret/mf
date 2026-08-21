.align 2

.global track_387

track_387_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 34
	.byte VOL, 40
	.byte PAN, c_v
	.byte N03, Dn2, v080
	.byte W03
	.byte Dn3 @ N03, v080
	.byte W03
	.byte N13, An2 @ v080
	.byte W02
	.byte VOL, 31
	.byte W03
	.byte 25 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W01
	.byte FINE

.align 2

track_387:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word 0x80a6d54
	.word track_387_0

.align 2
