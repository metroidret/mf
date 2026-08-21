.align 2

.global track_541

track_541_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W02
	.byte N15, En3, v127
	.byte W15
	.byte En3, v040 @ N15
	.byte W15
	.byte En3, v020 @ N15
	.byte W15
	.byte FINE

track_541_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 80
	.byte PAN, c_v
	.byte N15, En3, v127
	.byte W15
	.byte En3, v040 @ N15
	.byte W32
	.byte FINE

.align 2

track_541:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a808c
	.word track_541_0
	.word track_541_1

.align 2
