.align 2

.global track_233

track_233_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 55
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v-47
	.byte N64, Cn3, v092
	.byte W01
	.byte BEND, c_v-45
	.byte W01
	.byte c_v-43 @ BEND
	.byte W01
	.byte c_v-41 @ BEND
	.byte W01
	.byte c_v-39 @ BEND
	.byte W01
	.byte c_v-37 @ BEND
	.byte W01
	.byte c_v-34 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-30 @ BEND
	.byte W01
	.byte c_v-28 @ BEND
	.byte W01
	.byte c_v-26 @ BEND
	.byte W01
	.byte c_v-24 @ BEND
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
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-6 @ BEND
	.byte W01
	.byte c_v-4 @ BEND
	.byte W01
	.byte c_v-2 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte c_v+2 @ BEND
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
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+20 @ BEND
	.byte W01
	.byte c_v+22 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+28 @ BEND
	.byte W01
	.byte c_v+31 @ BEND
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W01
	.byte c_v+37 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+44 @ BEND
	.byte W01
	.byte c_v+46 @ BEND
	.byte W01
	.byte c_v+48 @ BEND
	.byte W01
	.byte c_v+50 @ BEND
	.byte W01
	.byte c_v+52 @ BEND
	.byte W01
	.byte c_v+54 @ BEND
	.byte W01
	.byte c_v+57 @ BEND
	.byte W16
	.byte FINE

track_233_1:
	.byte KEYSH, 0
	.byte VOICE, 37
	.byte MOD, 100
	.byte VOL, 44
	.byte PAN, c_v
	.byte LFOS, 5
	.byte N64, Cn4, v088
	.byte W06
	.byte LFOS, 20
	.byte W06
	.byte 35 @ LFOS
	.byte W06
	.byte 50 @ LFOS
	.byte W06
	.byte 65 @ LFOS
	.byte W06
	.byte 80 @ LFOS
	.byte W08
	.byte 100 @ LFOS
	.byte W24
	.byte W02
	.byte FINE

.align 2

track_233:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word 0x80a6af0
	.word track_233_0
	.word track_233_1

.align 2
