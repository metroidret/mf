.align 2

.global track_313

track_313_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 56
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-39
	.byte N72, Bn1, v127
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
	.byte VOL, 56
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v+7
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v+3
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-1
	.byte W01
	.byte c_v-4 @ BEND
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-8
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-13
	.byte W19
	.byte FINE

track_313_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 120
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N72, En1, v127
	.byte W88
	.byte W01
	.byte FINE

track_313_2:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 120
	.byte PAN, c_v
	.byte PRIO, 40
	.byte N24, Gn2, v120
	.byte W88
	.byte W01
	.byte FINE

.align 2

track_313:
	.byte 3
	.byte 0
	.byte 221
	.byte 0
	.word 0x80a82f0
	.word track_313_0
	.word track_313_1
	.word track_313_2

.align 2
