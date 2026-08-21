.align 2

.global track_487

track_487_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 103
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v+15
	.byte VOL, 110
	.byte N06, Cn1, v080
	.byte W01
	.byte BEND, c_v+17
	.byte VOL, 109
	.byte W01
	.byte BEND, c_v+19
	.byte W01
	.byte c_v+22 @ BEND
	.byte VOL, 108
	.byte W01
	.byte BEND, c_v+24
	.byte VOL, 106
	.byte W01
	.byte BEND, c_v+26
	.byte VOL, 105
	.byte W01
	.byte BEND, c_v+29
	.byte VOL, 104
	.byte N06, Cn1, v127
	.byte W01
	.byte BEND, c_v+31
	.byte VOL, 102
	.byte W01
	.byte BEND, c_v+34
	.byte VOL, 100
	.byte W01
	.byte BEND, c_v+36
	.byte VOL, 97
	.byte W01
	.byte BEND, c_v+38
	.byte VOL, 85
	.byte W01
	.byte BEND, c_v+41
	.byte VOL, 54
	.byte W01
	.byte BEND, c_v+43
	.byte VOL, 29
	.byte N06 @ Cn1, v127
	.byte W01
	.byte BEND, c_v+45
	.byte VOL, 16
	.byte W01
	.byte BEND, c_v+48
	.byte VOL, 8
	.byte W01
	.byte BEND, c_v+50
	.byte VOL, 4
	.byte W01
	.byte BEND, c_v+53
	.byte VOL, 0
	.byte W02
	.byte FINE

track_487_1:
	.byte KEYSH, 0
	.byte PRIO, 1
	.byte W03
	.byte VOICE, 6
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 4
	.byte BEND, c_v-48
	.byte N15, Cn3, v060
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 84
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 100
	.byte BEND, c_v+28
	.byte W01
	.byte VOL, 108
	.byte BEND, c_v+38
	.byte W01
	.byte VOL, 109
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 105
	.byte BEND, c_v+44
	.byte W01
	.byte VOL, 97
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 72
	.byte BEND, c_v+35
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-48
	.byte W01
	.byte FINE

.align 2

track_487:
	.byte 2
	.byte 0
	.byte 225
	.byte 0
	.word 0x80a81e8
	.word track_487_0
	.word track_487_1

.align 2
