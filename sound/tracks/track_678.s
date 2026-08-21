.align 2

.global track_678

track_678_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 0
	.byte BEND, c_v
	.byte N72, Cn2, v060
	.byte W03
	.byte VOL, 29
	.byte W03
	.byte 51 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 76 @ VOL
	.byte W03
	.byte 73 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W24
	.byte W01
	.byte FINE

.align 2

track_678:
	.byte 1
	.byte 0
	.byte 181
	.byte 0
	.word 0x80a838c
	.word track_678_0

.align 2
