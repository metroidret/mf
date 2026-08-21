.align 2

.global track_438

track_438_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 89
	.byte VOL, 12
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v-47
	.byte N09, Bn2, v127
	.byte W01
	.byte VOL, 13
	.byte W01
	.byte 14 @ VOL
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 17
	.byte W01
	.byte 19 @ VOL
	.byte BEND, c_v-39
	.byte W01
	.byte VOL, 20
	.byte W01
	.byte 22 @ VOL
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 25
	.byte W01
	.byte 27 @ VOL
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v
	.byte N09, Cn3 @ v127
	.byte W01
	.byte VOL, 33
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W02
	.byte N09, Cn3, v020
	.byte W15
	.byte FINE

track_438_1:
	.byte KEYSH, 0
	.byte VOICE, 43
	.byte VOL, 51
	.byte PAN, c_v
	.byte N04, Cn3, v072
	.byte W05
	.byte VOICE, 48
	.byte VOL, 34
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N28, Cn5, v100
	.byte W02
	.byte VOL, 59
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 78
	.byte BEND, c_v+23
	.byte W02
	.byte VOL, 92
	.byte BEND, c_v+21
	.byte W02
	.byte VOL, 103
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 108
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 110
	.byte BEND, c_v+39
	.byte W02
	.byte VOL, 70
	.byte BEND, c_v+37
	.byte W02
	.byte VOL, 45
	.byte BEND, c_v+32
	.byte W02
	.byte VOL, 32
	.byte BEND, c_v+49
	.byte W02
	.byte VOL, 21
	.byte BEND, c_v+54
	.byte W02
	.byte VOL, 12
	.byte BEND, c_v+53
	.byte W02
	.byte VOL, 7
	.byte BEND, c_v+48
	.byte W02
	.byte VOL, 2
	.byte BEND, c_v+62
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

.align 2

track_438:
	.byte 2
	.byte 0
	.byte 181
	.byte 0
	.word 0x80a6d54
	.word track_438_0
	.word track_438_1

.align 2
