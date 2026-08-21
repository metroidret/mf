.align 2

.global track_286

track_286_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 48
	.byte VOL, 7
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-33
	.byte TIE, Bn2, v092
	.byte W06
	.byte VOL, 19
	.byte W03
	.byte BEND, c_v-32
	.byte W03
	.byte VOL, 32
	.byte W06
	.byte 44 @ VOL
	.byte W06
	.byte 57 @ VOL
	.byte W03
	.byte BEND, c_v-31
	.byte W03
	.byte VOL, 70
	.byte W06
	.byte 82 @ VOL
	.byte W08
	.byte 100 @ VOL
	.byte W01
	.byte BEND, c_v-30
	.byte W18
	.byte c_v-29 @ BEND
	.byte W18
	.byte c_v-28 @ BEND
	.byte W15
	.byte c_v-27 @ BEND
	.byte W18
	.byte c_v-26 @ BEND
	.byte W18
	.byte c_v-25 @ BEND
	.byte W18
	.byte c_v-24 @ BEND
	.byte W18
	.byte c_v-23 @ BEND
	.byte W15
	.byte c_v-22 @ BEND
	.byte W09
	.byte W09
	.byte c_v-21 @ BEND
	.byte W18
	.byte c_v-20 @ BEND
	.byte W18
	.byte c_v-19 @ BEND
	.byte W18
	.byte c_v-18 @ BEND
	.byte W15
	.byte c_v-17 @ BEND
	.byte W18
	.byte c_v-16 @ BEND
	.byte W18
	.byte c_v-15 @ BEND
	.byte W18
	.byte c_v-14 @ BEND
	.byte W18
	.byte c_v-13 @ BEND
	.byte W15
	.byte c_v-12 @ BEND
	.byte W18
	.byte c_v-11 @ BEND
	.byte W09
	.byte W09
	.byte c_v-10 @ BEND
	.byte W18
	.byte c_v-9 @ BEND
	.byte W18
	.byte c_v-8 @ BEND
	.byte W15
	.byte c_v-7 @ BEND
	.byte W18
	.byte c_v-6 @ BEND
	.byte W18
	.byte c_v-5 @ BEND
	.byte W18
	.byte c_v-4 @ BEND
	.byte W18
	.byte c_v-3 @ BEND
	.byte W18
	.byte c_v-2 @ BEND
	.byte W15
	.byte c_v-1 @ BEND
	.byte W18
	.byte c_v @ BEND
	.byte W09
	.byte W96
	.byte W96
	.byte W96
	.byte EOT @ Bn2, v092
	.byte FINE

track_286_1:
	.byte KEYSH, 0
	.byte VOICE, 36
	.byte VOL, 100
	.byte PAN, c_v
	.byte N20, Fn1, v127
	.byte W20
	.byte VOICE, 49
	.byte TIE, Bn2, v092
	.byte W76
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte EOT @ Bn2, v092
	.byte FINE

.align 2

track_286:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_286_0
	.word track_286_1

.align 2
