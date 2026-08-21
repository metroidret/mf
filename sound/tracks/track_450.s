.align 2

.global track_450

track_450_0:
	.byte VOL, 127
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 71
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N16, En3, v032
	.byte W01
	.byte BEND, c_v-4
	.byte W01
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W01
	.byte c_v-18 @ BEND
	.byte W01
	.byte c_v-22 @ BEND
	.byte W01
	.byte c_v-25 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-36 @ BEND
	.byte W01
	.byte c_v-39 @ BEND
	.byte W01
	.byte c_v-43 @ BEND
	.byte W01
	.byte c_v-46 @ BEND
	.byte W01
	.byte c_v-50 @ BEND
	.byte W01
	.byte c_v-53 @ BEND
	.byte W01
	.byte FINE

track_450_1:
	.byte VOL, 127
	.byte KEYSH, 0
	.byte VOICE, 70
	.byte BENDR, 6
	.byte BEND, c_v
	.byte N16, Bn1, v032
	.byte W01
	.byte BEND, c_v+3
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte c_v+28 @ BEND
	.byte W01
	.byte c_v+31 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W01
	.byte c_v+38 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+52 @ BEND
	.byte W01
	.byte FINE

.align 2

track_450:
	.byte 2
	.byte 0
	.byte 170
	.byte 128
	.word 0x80a8554
	.word track_450_0
	.word track_450_1

.align 2
