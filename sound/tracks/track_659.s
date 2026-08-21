.align 2

.global track_659

track_659_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 39
	.byte PAN, c_v
	.byte N18, Dn3, v127
	.byte W48
	.byte FINE

track_659_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 100
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v-32
	.byte N48, Cn3, v127
	.byte W03
	.byte BEND, c_v-21
	.byte W03
	.byte c_v-11 @ BEND
	.byte W03
	.byte c_v @ BEND
	.byte W03
	.byte c_v+10 @ BEND
	.byte W03
	.byte c_v+21 @ BEND
	.byte W03
	.byte c_v+31 @ BEND
	.byte W03
	.byte c_v+42 @ BEND
	.byte W03
	.byte VOL, 100
	.byte W03
	.byte 66 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W03
	.byte 13 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte FINE

.align 2

track_659:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word 0x80a7e10
	.word track_659_0
	.word track_659_1

.align 2
