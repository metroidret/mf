.align 2

.global track_316

track_316_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N24, Fn1, v127
	.byte W18
	.byte VOL, 80
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_316_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 56
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-39
	.byte N24, Bn1, v127
	.byte W01
	.byte BEND, c_v-23
	.byte W01
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+50 @ BEND
	.byte W01
	.byte c_v+52 @ BEND
	.byte W01
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+52 @ BEND
	.byte W01
	.byte c_v+50 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte VOL, 56
	.byte BEND, c_v+35
	.byte W01
	.byte VOL, 48
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v+20
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-25
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-39
	.byte W01
	.byte FINE

track_316_2:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 30
	.byte N02, Gn2, v120
	.byte W24
	.byte FINE

.align 2

track_316:
	.byte 3
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a82f0
	.word track_316_0
	.word track_316_1
	.word track_316_2

.align 2
