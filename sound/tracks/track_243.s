.align 2

.global track_243

track_243_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 30
	.byte PAN, c_v
	.byte N02, Cn3, v127
	.byte W02
	.byte VOICE, 14
	.byte VOL, 4
	.byte N06 @ Cn3, v127
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte FINE

.align 2

track_243:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word 0x80a6af0
	.word track_243_0

.align 2
