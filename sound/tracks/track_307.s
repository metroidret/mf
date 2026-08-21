.align 2

.global track_307

track_307_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 2
	.byte W04
	.byte N10, Cn3, v100
	.byte W10
	.byte Cn3, v127 @ N10
	.byte W10
	.byte Cn3, v080 @ N10
	.byte W10
	.byte Cn3, v052 @ N10
	.byte W10
	.byte Cn3, v020 @ N10
	.byte W52
	.byte W10
	.byte FINE

track_307_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 2
	.byte N10, Cn3, v127
	.byte W10
	.byte Cn3, v080 @ N10
	.byte W10
	.byte Cn3, v060 @ N10
	.byte W10
	.byte Cn3, v040 @ N10
	.byte W10
	.byte Cn3, v020 @ N10
	.byte W56
	.byte W10
	.byte FINE

track_307_2:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 2
	.byte W02
	.byte N04, Cn3, v080
	.byte W05
	.byte N04 @ Cn3, v080
	.byte W05
	.byte N04 @ Cn3, v080
	.byte W04
	.byte VOICE, 6
	.byte N04 @ Cn3, v080
	.byte W04
	.byte VOICE, 7
	.byte N04 @ Cn3, v080
	.byte W04
	.byte VOICE, 5
	.byte VOL, 80
	.byte W02
	.byte N04 @ Cn3, v080
	.byte W05
	.byte N04 @ Cn3, v080
	.byte W05
	.byte Cn3, v060 @ N04
	.byte W04
	.byte VOICE, 6
	.byte N04, Cn3, v040
	.byte W04
	.byte VOICE, 7
	.byte N04, Cn3, v020
	.byte W52
	.byte W10
	.byte FINE

track_307_3:
	.byte KEYSH, 0
	.byte PRIO, 127
	.byte W09
	.byte VOICE, 8
	.byte VOL, 127
	.byte PAN, c_v
	.byte W02
	.byte N05, Fn2, v127
	.byte W03
	.byte N12, Gs2, v112
	.byte W15
	.byte VOICE, 9
	.byte N24, En2, v127
	.byte W66
	.byte W01
	.byte W10
	.byte FINE

track_307_4:
	.byte KEYSH, 0
	.byte W15
	.byte VOICE, 19
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 10
	.byte PRIO, 1
	.byte BEND, c_v+23
	.byte N48, Cn3, v120
	.byte W02
	.byte VOL, 103
	.byte W02
	.byte 117 @ VOL
	.byte BEND, c_v+21
	.byte W02
	.byte VOL, 127
	.byte BEND, c_v+19
	.byte W02
	.byte c_v+14 @ BEND
	.byte W02
	.byte c_v+3 @ BEND
	.byte W02
	.byte c_v-3 @ BEND
	.byte W02
	.byte c_v-7 @ BEND
	.byte W02
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v-14 @ BEND
	.byte W02
	.byte c_v-5 @ BEND
	.byte W02
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+62 @ BEND
	.byte W02
	.byte c_v+61 @ BEND
	.byte W02
	.byte c_v+59 @ BEND
	.byte W02
	.byte c_v+56 @ BEND
	.byte W02
	.byte c_v+51 @ BEND
	.byte W02
	.byte c_v+41 @ BEND
	.byte W02
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W02
	.byte c_v+17 @ BEND
	.byte W01
	.byte VOL, 127
	.byte W01
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 40
	.byte W01
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 5
	.byte W01
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+59
	.byte W32
	.byte W02
	.byte W10
	.byte FINE

track_307_5:
	.byte KEYSH, 0
	.byte W30
	.byte VOICE, 19
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 10
	.byte PRIO, 1
	.byte BEND, c_v+23
	.byte N48, Cn3, v032
	.byte W02
	.byte VOL, 103
	.byte W02
	.byte 117 @ VOL
	.byte BEND, c_v+21
	.byte W02
	.byte VOL, 127
	.byte BEND, c_v+19
	.byte W02
	.byte c_v+14 @ BEND
	.byte W02
	.byte c_v+3 @ BEND
	.byte W02
	.byte c_v-3 @ BEND
	.byte W02
	.byte c_v-7 @ BEND
	.byte W02
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v-14 @ BEND
	.byte W02
	.byte c_v-5 @ BEND
	.byte W02
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+62 @ BEND
	.byte W02
	.byte c_v+61 @ BEND
	.byte W02
	.byte c_v+59 @ BEND
	.byte W02
	.byte c_v+56 @ BEND
	.byte W02
	.byte c_v+51 @ BEND
	.byte W02
	.byte c_v+41 @ BEND
	.byte W02
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W02
	.byte c_v+17 @ BEND
	.byte W01
	.byte VOL, 127
	.byte W01
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 40
	.byte W01
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 5
	.byte W01
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+59
	.byte W19
	.byte W10
	.byte FINE

.align 2

track_307:
	.byte 6
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a808c
	.word track_307_0
	.word track_307_1
	.word track_307_2
	.word track_307_3
	.word track_307_4
	.word track_307_5

.align 2
