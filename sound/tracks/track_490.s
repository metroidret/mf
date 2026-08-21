.align 2

.global track_490

track_490_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 48
	.byte VOL, 60
	.byte PAN, c_v+36
	.byte W02
	.byte TIE, Cn3, v080
	.byte W03
	.byte PAN, c_v+32
	.byte W06
	.byte c_v+29 @ PAN
	.byte W06
	.byte c_v+26 @ PAN
	.byte VOL, 60
	.byte W03
	.byte 56 @ VOL
	.byte PAN, c_v+25
	.byte W03
	.byte VOL, 52
	.byte PAN, c_v+23
	.byte W03
	.byte VOL, 49
	.byte PAN, c_v+22
	.byte W03
	.byte VOL, 46
	.byte PAN, c_v+20
	.byte W03
	.byte VOL, 43
	.byte PAN, c_v+19
	.byte W03
	.byte VOL, 41
	.byte PAN, c_v+17
	.byte W03
	.byte VOL, 39
	.byte PAN, c_v+16
	.byte W03
	.byte VOL, 37
	.byte PAN, c_v+14
	.byte W03
	.byte VOL, 35
	.byte PAN, c_v+13
	.byte W03
	.byte VOL, 34
	.byte PAN, c_v+11
	.byte W03
	.byte VOL, 33
	.byte PAN, c_v+10
	.byte W03
	.byte VOL, 31
	.byte PAN, c_v+8
	.byte W03
	.byte VOL, 30
	.byte PAN, c_v+7
	.byte W03
	.byte VOL, 29
	.byte PAN, c_v+5
	.byte W03
	.byte VOL, 29
	.byte PAN, c_v+4
	.byte W03
	.byte VOL, 28
	.byte PAN, c_v+2
	.byte W03
	.byte VOL, 27
	.byte PAN, c_v+1
	.byte W03
	.byte VOL, 26
	.byte PAN, c_v
	.byte W24
	.byte W01
	.byte W96
	.byte W96
	.byte W96
	.byte W02
	.byte EOT @ Cn3, v080
	.byte FINE

track_490_1:
	.byte KEYSH, 0
	.byte VOICE, 49
	.byte VOL, 28
	.byte PAN, c_v+36
	.byte TIE, Cn1, v127
	.byte W05
	.byte PAN, c_v+32
	.byte W06
	.byte c_v+29 @ PAN
	.byte W06
	.byte c_v+26 @ PAN
	.byte W03
	.byte c_v+25 @ PAN
	.byte W03
	.byte c_v+23 @ PAN
	.byte W03
	.byte c_v+22 @ PAN
	.byte W03
	.byte c_v+20 @ PAN
	.byte W03
	.byte c_v+19 @ PAN
	.byte W03
	.byte c_v+17 @ PAN
	.byte W03
	.byte c_v+16 @ PAN
	.byte W03
	.byte c_v+14 @ PAN
	.byte W03
	.byte c_v+13 @ PAN
	.byte W03
	.byte c_v+11 @ PAN
	.byte W03
	.byte c_v+10 @ PAN
	.byte W03
	.byte c_v+8 @ PAN
	.byte W03
	.byte c_v+7 @ PAN
	.byte W03
	.byte c_v+5 @ PAN
	.byte W03
	.byte c_v+4 @ PAN
	.byte W03
	.byte c_v+2 @ PAN
	.byte W03
	.byte c_v+1 @ PAN
	.byte W03
	.byte c_v @ PAN
	.byte W24
	.byte W01
	.byte W24
	.byte EOT @ Cn1, v127
	.byte W72
	.byte W96
	.byte W96
	.byte W02
	.byte FINE

.align 2

track_490:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_490_0
	.word track_490_1

.align 2
