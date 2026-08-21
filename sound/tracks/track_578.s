.align 2

.global track_578

track_578_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte MOD, 0
	.byte VOL, 80
	.byte PAN, c_v
	.byte LFOS, 0
	.byte TIE, Fn2, v052
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte EOT @ Fn2, v052
	.byte W48
	.byte FINE

track_578_1:
	.byte KEYSH, 0
	.byte VOICE, 50
	.byte MOD, 50
	.byte VOL, 0
	.byte PAN, c_v
	.byte LFOS, 8
	.byte TIE, Cn3, v080
	.byte W03
	.byte VOL, 16
	.byte W03
	.byte 32 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 64 @ VOL
	.byte W03
	.byte 79 @ VOL
	.byte W03
	.byte 95 @ VOL
	.byte W03
	.byte 111 @ VOL
	.byte W03
	.byte 127 @ VOL
	.byte W72
	.byte W96
	.byte W96
	.byte W96
	.byte 127 @ VOL
	.byte W03
	.byte 123 @ VOL
	.byte W03
	.byte 119 @ VOL
	.byte W03
	.byte 115 @ VOL
	.byte W03
	.byte 111 @ VOL
	.byte W03
	.byte 107 @ VOL
	.byte W03
	.byte 103 @ VOL
	.byte W03
	.byte 99 @ VOL
	.byte W03
	.byte 95 @ VOL
	.byte W03
	.byte 91 @ VOL
	.byte W03
	.byte 87 @ VOL
	.byte W03
	.byte 83 @ VOL
	.byte W03
	.byte 78 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 54 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 30 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 10 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte EOT @ Cn3, v080
	.byte FINE

track_578_2:
	.byte KEYSH, 0
	.byte VOICE, 64
	.byte VOL, 80
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte TIE, Cn3, v080
	.byte W03
	.byte VOL, 81
	.byte BEND, c_v-62
	.byte W03
	.byte c_v-61 @ BEND
	.byte W03
	.byte VOL, 82
	.byte BEND, c_v-60
	.byte W03
	.byte VOL, 83
	.byte BEND, c_v-58
	.byte W03
	.byte c_v-57 @ BEND
	.byte W03
	.byte VOL, 85
	.byte BEND, c_v-55
	.byte W03
	.byte c_v-53 @ BEND
	.byte W03
	.byte VOL, 86
	.byte BEND, c_v-52
	.byte W03
	.byte VOL, 87
	.byte BEND, c_v-51
	.byte W03
	.byte c_v-49 @ BEND
	.byte W03
	.byte VOL, 89
	.byte BEND, c_v-47
	.byte W03
	.byte VOL, 90
	.byte W03
	.byte 91 @ VOL
	.byte BEND, c_v-45
	.byte W03
	.byte VOL, 92
	.byte BEND, c_v-44
	.byte W03
	.byte VOL, 93
	.byte BEND, c_v-43
	.byte W03
	.byte VOL, 94
	.byte BEND, c_v-41
	.byte W03
	.byte VOL, 95
	.byte BEND, c_v-40
	.byte W03
	.byte VOL, 97
	.byte BEND, c_v-39
	.byte W03
	.byte VOL, 99
	.byte BEND, c_v-37
	.byte W03
	.byte VOL, 100
	.byte BEND, c_v-36
	.byte W03
	.byte VOL, 101
	.byte BEND, c_v-35
	.byte W03
	.byte VOL, 103
	.byte BEND, c_v-34
	.byte W03
	.byte VOL, 105
	.byte BEND, c_v-33
	.byte W03
	.byte VOL, 107
	.byte BEND, c_v-32
	.byte W03
	.byte VOL, 108
	.byte BEND, c_v-31
	.byte W03
	.byte VOL, 111
	.byte BEND, c_v-29
	.byte W03
	.byte VOL, 113
	.byte W03
	.byte 116 @ VOL
	.byte BEND, c_v-27
	.byte W03
	.byte VOL, 119
	.byte BEND, c_v-26
	.byte W03
	.byte VOL, 121
	.byte BEND, c_v-25
	.byte W03
	.byte VOL, 124
	.byte W03
	.byte 127 @ VOL
	.byte BEND, c_v-24
	.byte W03
	.byte c_v-23 @ BEND
	.byte W03
	.byte c_v-22 @ BEND
	.byte W03
	.byte c_v-21 @ BEND
	.byte W06
	.byte c_v-19 @ BEND
	.byte W03
	.byte c_v-18 @ BEND
	.byte W03
	.byte c_v-17 @ BEND
	.byte W06
	.byte c_v-16 @ BEND
	.byte W03
	.byte c_v-15 @ BEND
	.byte W06
	.byte c_v-14 @ BEND
	.byte W03
	.byte c_v-13 @ BEND
	.byte W06
	.byte c_v-12 @ BEND
	.byte W03
	.byte c_v-11 @ BEND
	.byte W06
	.byte c_v-10 @ BEND
	.byte W03
	.byte c_v-9 @ BEND
	.byte W09
	.byte c_v-8 @ BEND
	.byte W03
	.byte c_v-7 @ BEND
	.byte W09
	.byte c_v-6 @ BEND
	.byte W03
	.byte c_v-5 @ BEND
	.byte W15
	.byte c_v-4 @ BEND
	.byte W06
	.byte c_v-3 @ BEND
	.byte W15
	.byte c_v-2 @ BEND
	.byte W18
	.byte c_v-1 @ BEND
	.byte W18
	.byte c_v-2 @ BEND
	.byte W18
	.byte c_v-3 @ BEND
	.byte W12
	.byte c_v-4 @ BEND
	.byte W06
	.byte c_v-5 @ BEND
	.byte W03
	.byte W12
	.byte c_v-6 @ BEND
	.byte W03
	.byte c_v-7 @ BEND
	.byte W09
	.byte c_v-8 @ BEND
	.byte W03
	.byte c_v-9 @ BEND
	.byte W12
	.byte c_v-10 @ BEND
	.byte W03
	.byte c_v-11 @ BEND
	.byte W03
	.byte c_v-12 @ BEND
	.byte W03
	.byte c_v-13 @ BEND
	.byte W09
	.byte c_v-14 @ BEND
	.byte W03
	.byte c_v-15 @ BEND
	.byte W03
	.byte c_v-16 @ BEND
	.byte W03
	.byte c_v-17 @ BEND
	.byte W09
	.byte c_v-19 @ BEND
	.byte W03
	.byte c_v-20 @ BEND
	.byte W03
	.byte c_v-21 @ BEND
	.byte W06
	.byte c_v-22 @ BEND
	.byte W03
	.byte c_v-23 @ BEND
	.byte W03
	.byte c_v-24 @ BEND
	.byte W03
	.byte c_v-25 @ BEND
	.byte VOL, 127
	.byte W03
	.byte 122 @ VOL
	.byte W03
	.byte BEND, c_v-27
	.byte VOL, 118
	.byte W03
	.byte BEND, c_v-28
	.byte VOL, 114
	.byte W03
	.byte BEND, c_v-29
	.byte VOL, 110
	.byte W03
	.byte 106 @ VOL
	.byte W03
	.byte BEND, c_v-31
	.byte VOL, 102
	.byte W03
	.byte BEND, c_v-32
	.byte VOL, 98
	.byte W03
	.byte BEND, c_v-33
	.byte VOL, 94
	.byte W03
	.byte BEND, c_v-35
	.byte VOL, 90
	.byte W03
	.byte 85 @ VOL
	.byte W03
	.byte BEND, c_v-37
	.byte VOL, 81
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte BEND, c_v-39
	.byte VOL, 73
	.byte W03
	.byte BEND, c_v-40
	.byte VOL, 69
	.byte W03
	.byte BEND, c_v-41
	.byte VOL, 65
	.byte W03
	.byte BEND, c_v-43
	.byte VOL, 61
	.byte W03
	.byte BEND, c_v-44
	.byte VOL, 57
	.byte W03
	.byte BEND, c_v-45
	.byte VOL, 53
	.byte W03
	.byte BEND, c_v-46
	.byte VOL, 49
	.byte W03
	.byte BEND, c_v-47
	.byte VOL, 44
	.byte W03
	.byte BEND, c_v-49
	.byte VOL, 40
	.byte W03
	.byte BEND, c_v-50
	.byte VOL, 36
	.byte W03
	.byte BEND, c_v-51
	.byte VOL, 32
	.byte W03
	.byte BEND, c_v-53
	.byte VOL, 28
	.byte W03
	.byte BEND, c_v-55
	.byte VOL, 24
	.byte W03
	.byte BEND, c_v-56
	.byte VOL, 20
	.byte W03
	.byte BEND, c_v-57
	.byte VOL, 16
	.byte W03
	.byte BEND, c_v-59
	.byte VOL, 12
	.byte W03
	.byte BEND, c_v-61
	.byte VOL, 8
	.byte W03
	.byte 3 @ VOL
	.byte W03
	.byte BEND, c_v-63
	.byte VOL, 0
	.byte W03
	.byte EOT @ Cn3, v080
	.byte FINE

.align 2

track_578:
	.byte 3
	.byte 0
	.byte 255
	.byte 0
	.word 0x80a7798
	.word track_578_0
	.word track_578_1
	.word track_578_2

.align 2
