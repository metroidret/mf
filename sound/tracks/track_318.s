.align 2

.global track_318

track_318_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 40
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N36, Fn1, v127
	.byte W18
	.byte VOL, 40
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_318_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 28
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-39
	.byte N36, Bn1, v127
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
	.byte VOL, 28
	.byte BEND, c_v+35
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v+20
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v-25
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v-39
	.byte W01
	.byte VOL, 16
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_318_2:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 40
	.byte PAN, c_v
	.byte PRIO, 30
	.byte N01, Gn2, v120
	.byte W36
	.byte FINE

.align 2

track_318:
	.byte 3
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a82f0
	.word track_318_0
	.word track_318_1
	.word track_318_2

.align 2
