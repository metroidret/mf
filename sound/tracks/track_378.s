.align 2

.global track_378

track_378_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 65
	.byte VOL, 31
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-23
	.byte N24, Bn2, v080
	.byte W03
	.byte VOL, 34
	.byte BEND, c_v-9
	.byte W03
	.byte VOL, 29
	.byte BEND, c_v-3
	.byte W03
	.byte VOL, 24
	.byte BEND, c_v-1
	.byte W03
	.byte VOL, 19
	.byte BEND, c_v
	.byte W03
	.byte VOL, 14
	.byte W03
	.byte 9 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W15
	.byte FINE

track_378_1:
	.byte KEYSH, 0
	.byte VOICE, 46
	.byte VOL, 25
	.byte PAN, c_v
	.byte N04, As2, v127
	.byte W04
	.byte N32, Gs2, v120
	.byte W20
	.byte VOL, 25
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_378:
	.byte 2
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_378_0
	.word track_378_1

.align 2
