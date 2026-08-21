.align 2

.global track_610

track_610_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W01
	.byte N28, Cn3, v127
	.byte W28
	.byte W01
	.byte FINE

track_610_1:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 127
	.byte PAN, c_v
	.byte N05, Cn3, v100
	.byte W05
	.byte VOICE, 4
	.byte VOL, 60
	.byte N20 @ Cn3, v100
	.byte W15
	.byte VOL, 50
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W06
	.byte FINE

.align 2

track_610:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7aa4
	.word track_610_0
	.word track_610_1

.align 2
