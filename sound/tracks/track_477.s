.align 2

.global track_477

track_477_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N64, Cn3, v127
	.byte W66
	.byte Cn3, v016 @ N64
	.byte W30
	.byte W24
	.byte VOL, 127
	.byte W01
	.byte 78 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte FINE

track_477_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 127
	.byte PAN, c_v
	.byte W36
	.byte N64, Cn3, v036
	.byte W60
	.byte W32
	.byte W03
	.byte FINE

.align 2

track_477:
	.byte 2
	.byte 0
	.byte 254
	.byte 0
	.word 0x80a81e8
	.word track_477_0
	.word track_477_1

.align 2
