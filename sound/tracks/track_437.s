.align 2

.global track_437

track_437_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 90
	.byte VOL, 25
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v-33
	.byte W04
	.byte N32, Fn2, v100
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v-31
	.byte VOL, 28
	.byte W01
	.byte BEND, c_v-29
	.byte VOL, 34
	.byte W01
	.byte BEND, c_v-27
	.byte VOL, 41
	.byte W01
	.byte BEND, c_v-25
	.byte VOL, 62
	.byte W01
	.byte BEND, c_v-23
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W01
	.byte c_v-13 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v-7 @ BEND
	.byte W01
	.byte c_v-5 @ BEND
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v-1 @ BEND
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v+18
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v+20
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 25
	.byte W01
	.byte 22 @ VOL
	.byte W05
	.byte FINE

track_437_1:
	.byte KEYSH, 0
	.byte VOICE, 87
	.byte VOL, 80
	.byte PAN, c_v
	.byte BENDR, 16
	.byte BEND, c_v
	.byte N14, Cn2, v127
	.byte W01
	.byte BEND, c_v+5
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+20 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+31 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+52 @ BEND
	.byte W01
	.byte c_v+57 @ BEND
	.byte W01
	.byte c_v+62 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte VOICE, 88
	.byte VOL, 50
	.byte N07, Cn3, v072
	.byte W07
	.byte Cn3, v020 @ N07
	.byte W17
	.byte FINE

.align 2

track_437:
	.byte 2
	.byte 0
	.byte 171
	.byte 0
	.word 0x80a6d54
	.word track_437_0
	.word track_437_1

.align 2
