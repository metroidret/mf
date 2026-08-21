.align 2

.global track_552

track_552_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 90
	.byte PAN, c_v
	.byte N02, Cn3, v052
	.byte W02
	.byte N04, En3, v060
	.byte W32
	.byte VOICE, 4
	.byte N13, Cn3, v127
	.byte W30
	.byte FINE

track_552_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte PAN, c_v
	.byte W36
	.byte W01
	.byte VOL, 20
	.byte N15, Cn3, v100
	.byte W01
	.byte VOL, 21
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 90 @ VOL
	.byte W13
	.byte FINE

.align 2

track_552:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7654
	.word track_552_0
	.word track_552_1

.align 2
