.align 2

.global track_220

track_220_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 79
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte VOICE, 9
	.byte N10, Cn3, v040
	.byte W60
	.byte W02
	.byte W84
	.byte FINE

track_220_1:
	.byte KEYSH, 0
	.byte VOICE, 30
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 80
	.byte N15, An2, v120
	.byte W15
	.byte An2, v060 @ N15
	.byte W15
	.byte An2, v040 @ N15
	.byte W15
	.byte N30, An2, v020
	.byte W48
	.byte W03
	.byte W24
	.byte VOL, 15
	.byte N15, Cn3, v120
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W15
	.byte N30, Cn3, v020
	.byte W30
	.byte FINE

track_220_2:
	.byte KEYSH, 0
	.byte VOICE, 41
	.byte MOD, 60
	.byte VOL, 62
	.byte PAN, c_v
	.byte LFOS, 20
	.byte PRIO, 80
	.byte W05
	.byte VOL, 31
	.byte TIE, Fn3, v120
	.byte W03
	.byte VOL, 32
	.byte W06
	.byte 33 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W06
	.byte 34 @ VOL
	.byte W01
	.byte LFOS, 30
	.byte W02
	.byte VOL, 35
	.byte W06
	.byte 37 @ VOL
	.byte W06
	.byte 37 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W04
	.byte LFOS, 40
	.byte W02
	.byte VOL, 41
	.byte W06
	.byte 43 @ VOL
	.byte W06
	.byte 44 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W01
	.byte LFOS, 60
	.byte W05
	.byte VOL, 49
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 54 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 57 @ VOL
	.byte W01
	.byte LFOS, 70
	.byte W02
	.byte VOL, 59
	.byte W03
	.byte 60 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W03
	.byte EOT @ Fn3, v120
	.byte W54
	.byte W01
	.byte FINE

track_220_3:
	.byte KEYSH, 0
	.byte VOICE, 39
	.byte VOL, 7
	.byte PAN, c_v
	.byte BENDR, 20
	.byte PRIO, 79
	.byte W03
	.byte VOL, 8
	.byte BEND, c_v-61
	.byte W02
	.byte N24, Cn3, v072
	.byte W01
	.byte BEND, c_v-60
	.byte W03
	.byte VOL, 9
	.byte BEND, c_v-58
	.byte W03
	.byte VOL, 10
	.byte BEND, c_v-57
	.byte W03
	.byte c_v-55 @ BEND
	.byte W03
	.byte VOL, 11
	.byte BEND, c_v-54
	.byte W03
	.byte VOL, 11
	.byte BEND, c_v-52
	.byte W03
	.byte LFOS, 20
	.byte BEND, c_v-50
	.byte W03
	.byte VOL, 13
	.byte BEND, c_v-49
	.byte W02
	.byte N24, Cn3, v092
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-47
	.byte W03
	.byte VOL, 14
	.byte BEND, c_v-46
	.byte W03
	.byte VOL, 16
	.byte BEND, c_v-44
	.byte W03
	.byte VOL, 17
	.byte BEND, c_v-43
	.byte W03
	.byte VOL, 18
	.byte BEND, c_v-41
	.byte W03
	.byte VOL, 19
	.byte BEND, c_v-39
	.byte W03
	.byte VOL, 21
	.byte LFOS, 30
	.byte BEND, c_v-38
	.byte W03
	.byte VOL, 22
	.byte BEND, c_v-36
	.byte W02
	.byte N24 @ Cn3, v092
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-35
	.byte W03
	.byte VOL, 27
	.byte BEND, c_v-33
	.byte W03
	.byte VOL, 29
	.byte BEND, c_v-32
	.byte W03
	.byte VOL, 33
	.byte BEND, c_v-30
	.byte W03
	.byte VOL, 36
	.byte BEND, c_v-28
	.byte W03
	.byte VOL, 40
	.byte BEND, c_v-27
	.byte W03
	.byte VOL, 44
	.byte LFOS, 40
	.byte BEND, c_v-25
	.byte W03
	.byte VOL, 48
	.byte BEND, c_v-24
	.byte W02
	.byte N24 @ Cn3, v092
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v-22
	.byte W03
	.byte VOL, 53
	.byte BEND, c_v-21
	.byte W03
	.byte VOL, 55
	.byte BEND, c_v-19
	.byte W03
	.byte c_v-17 @ BEND
	.byte W03
	.byte VOL, 56
	.byte BEND, c_v-16
	.byte W03
	.byte VOL, 55
	.byte BEND, c_v-14
	.byte W03
	.byte VOL, 54
	.byte LFOS, 50
	.byte BEND, c_v-13
	.byte W03
	.byte VOL, 51
	.byte BEND, c_v-11
	.byte W02
	.byte N24 @ Cn3, v092
	.byte W01
	.byte VOL, 46
	.byte BEND, c_v-9
	.byte W03
	.byte VOL, 40
	.byte BEND, c_v-8
	.byte W03
	.byte c_v-6 @ BEND
	.byte W02
	.byte VOL, 28
	.byte W01
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 21
	.byte W01
	.byte BEND, c_v-3
	.byte W02
	.byte VOL, 14
	.byte W01
	.byte BEND, c_v-2
	.byte W02
	.byte VOL, 8
	.byte W01
	.byte BEND, c_v
	.byte W02
	.byte VOL, 3
	.byte W01
	.byte 0 @ VOL
	.byte W56
	.byte W01
	.byte FINE

.align 2

track_220:
	.byte 4
	.byte 0
	.byte 199
	.byte 0
	.word 0x80a6af0
	.word track_220_0
	.word track_220_1
	.word track_220_2
	.word track_220_3

.align 2
