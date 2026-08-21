.align 2

.global track_483

track_483_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 60
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-39
	.byte N72, Cn2, v127
	.byte W01
	.byte BEND, c_v-29
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+28 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+51 @ BEND
	.byte W02
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+54 @ BEND
	.byte W01
	.byte c_v+55 @ BEND
	.byte W08
	.byte c_v+54 @ BEND
	.byte W01
	.byte c_v+53 @ BEND
	.byte W02
	.byte c_v+52 @ BEND
	.byte W01
	.byte c_v+51 @ BEND
	.byte W02
	.byte c_v+49 @ BEND
	.byte W02
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+46 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+43 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+38 @ BEND
	.byte W01
	.byte c_v+37 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte VOL, 60
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v+7
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v+3
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-1
	.byte W01
	.byte c_v-4 @ BEND
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-8
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-13
	.byte W02
	.byte FINE

track_483_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 127
	.byte PAN, c_v
	.byte N72, Fn1, v127
	.byte W72
	.byte FINE

track_483_2:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 127
	.byte N24, Gn2, v120
	.byte W72
	.byte FINE

.align 2

track_483:
	.byte 3
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a81e8
	.word track_483_0
	.word track_483_1
	.word track_483_2

.align 2
