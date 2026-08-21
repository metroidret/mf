.align 2

.global track_619

track_619_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N13, Cn3, v127
	.byte W32
	.byte W03
	.byte FINE

track_619_1:
	.byte KEYSH, 0
	.byte W06
	.byte VOICE, 9
	.byte VOL, 100
	.byte PAN, c_v
	.byte N18, Cn3, v080
	.byte W02
	.byte VOL, 84
	.byte W02
	.byte 73 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W02
	.byte 60 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W13
	.byte FINE

.align 2

track_619:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7aa4
	.word track_619_0
	.word track_619_1

.align 2
