.align 2

.global track_497

track_497_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 55
	.byte MOD, 50
	.byte VOL, 12
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 127
	.byte MODT, 1
	.byte BEND, c_v-1
	.byte TIE, Gs2, v100
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+14
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+14
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+18
	.byte W01
	.byte c_v+19 @ BEND
	.byte W72
	.byte W96
	.byte EOT @ Gs2, v100
	.byte FINE

.align 2

track_497:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_497_0

.align 2
