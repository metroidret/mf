.align 2

.global track_205

track_205_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 65
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N05, Cn3, v040
	.byte W05
	.byte VOICE, 37
	.byte VOL, 57
	.byte BENDR, 10
	.byte BEND, c_v
	.byte N48, Cn4, v088
	.byte W03
	.byte VOL, 61
	.byte BEND, c_v+47
	.byte W02
	.byte VOL, 65
	.byte W01
	.byte BEND, c_v+23
	.byte W03
	.byte c_v-34 @ BEND
	.byte W03
	.byte c_v-41 @ BEND
	.byte W03
	.byte c_v+14 @ BEND
	.byte W03
	.byte c_v+48 @ BEND
	.byte W03
	.byte c_v+11 @ BEND
	.byte W03
	.byte VOL, 65
	.byte BEND, c_v-42
	.byte W03
	.byte VOL, 45
	.byte BEND, c_v-31
	.byte W03
	.byte VOL, 33
	.byte BEND, c_v+26
	.byte W03
	.byte VOL, 24
	.byte BEND, c_v+46
	.byte W03
	.byte VOL, 17
	.byte BEND, c_v-3
	.byte W03
	.byte VOL, 12
	.byte BEND, c_v-47
	.byte W03
	.byte VOL, 7
	.byte BEND, c_v-21
	.byte W03
	.byte VOL, 3
	.byte W03
	.byte 0 @ VOL
	.byte W08
	.byte FINE

track_205_1:
	.byte KEYSH, 0
	.byte VOICE, 39
	.byte VOL, 56
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v
	.byte W05
	.byte N56, Cn3, v127
	.byte W03
	.byte VOL, 53
	.byte BEND, c_v-4
	.byte W03
	.byte VOL, 50
	.byte BEND, c_v-7
	.byte W03
	.byte VOL, 47
	.byte BEND, c_v-11
	.byte W03
	.byte VOL, 44
	.byte BEND, c_v-14
	.byte W03
	.byte VOL, 40
	.byte BEND, c_v-18
	.byte W03
	.byte VOL, 37
	.byte BEND, c_v-21
	.byte W03
	.byte VOL, 34
	.byte BEND, c_v-25
	.byte W03
	.byte VOL, 31
	.byte BEND, c_v-28
	.byte W03
	.byte VOL, 28
	.byte BEND, c_v-31
	.byte W03
	.byte VOL, 25
	.byte BEND, c_v-35
	.byte W03
	.byte VOL, 22
	.byte BEND, c_v-38
	.byte W03
	.byte VOL, 19
	.byte BEND, c_v-42
	.byte W03
	.byte VOL, 16
	.byte BEND, c_v-45
	.byte W03
	.byte VOL, 13
	.byte BEND, c_v-49
	.byte W03
	.byte VOL, 10
	.byte BEND, c_v-52
	.byte W03
	.byte VOL, 7
	.byte BEND, c_v-55
	.byte W03
	.byte VOL, 4
	.byte BEND, c_v-59
	.byte W03
	.byte VOL, 1
	.byte BEND, c_v-62
	.byte W01
	.byte c_v-63 @ BEND
	.byte W01
	.byte FINE

.align 2

track_205:
	.byte 2
	.byte 0
	.byte 195
	.byte 0
	.word 0x80a6af0
	.word track_205_0
	.word track_205_1

.align 2
