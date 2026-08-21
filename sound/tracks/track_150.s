.align 2

.global track_150

track_150_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 50
	.byte VOL, 28
	.byte PAN, c_v
	.byte N24, En4, v127
	.byte W03
	.byte VOL, 24
	.byte W03
	.byte 20 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 13 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_150:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a682c
	.word track_150_0

.align 2
