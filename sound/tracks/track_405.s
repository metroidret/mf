.align 2

.global track_405

track_405_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 65
	.byte MOD, 20
	.byte VOL, 18
	.byte PAN, c_v
	.byte LFOS, 127
	.byte W12
	.byte N20, Cn3, v080
	.byte W02
	.byte VOL, 21
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W05
	.byte 40 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_405:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_405_0

.align 2
