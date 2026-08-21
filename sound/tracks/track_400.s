.align 2

.global track_400

track_400_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 71
	.byte VOL, 47
	.byte PAN, c_v
	.byte N04, An2, v127
	.byte W04
	.byte En3, v100 @ N04
	.byte W04
	.byte N15, Cn3 @ v100
	.byte W04
	.byte VOL, 47
	.byte W03
	.byte 32 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_400:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_400_0

.align 2
